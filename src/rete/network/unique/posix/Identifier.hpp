///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Identifier.hpp
///
/// Author: $author$
///   Date: 2/8/2020
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_UNIQUE_POSIX_IDENTIFIER_HPP
#define _RETE_NETWORK_UNIQUE_POSIX_IDENTIFIER_HPP

#include "rete/network/unique/Identifier.hpp"
#include <sys/time.h>

namespace rete {
namespace network {
namespace unique {
namespace posix {

///////////////////////////////////////////////////////////////////////
///  Class: Identifiert
///////////////////////////////////////////////////////////////////////
template <class TExtends = Identifier, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Identifiert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Identifiert Derives;
    
    typedef typename Extends::Version Version;
    typedef typename Extends::From From;
    typedef typename Extends::wrapped_t wrapped_t;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Identifiert(const Identifiert &copy) {
    }
    Identifiert() {
    }
    virtual ~Identifiert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Generate(From& from, typename Version::Which which = Version::None) {
        if (Version::None != (which)) {
            return false;
        }
        return GenerateTimeBased(from);
    }
    virtual bool GenerateTimeBased(From& from) {
        typename From::Ethernet& ethernet = from.ethernet();
        typename From::Random& random = from.random();
        typename From::Md5& md5 = from.md5();
        wrapped_t& actual = this->wrapped_;

        /// get current UUID time (64 bits)
        ///
        uint64_t uuidTime = Time();

        /// Encode the time into the UUID struct (host order).
        ///
        actual.m_timeLow.m_l = (uint32_t)(uuidTime & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_LOW_BM);
        actual.m_timeMid.m_w = (uint16_t)((uuidTime & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_MID_BM) >> NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_MID_BS);
        actual.m_timeHiAndVersion.m_w = (uint16_t)((uuidTime & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_BM) >> NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_BS);
        actual.m_timeHiAndVersion.m_w |= (uint16_t)(actual::Identifier::VERSION_TIME_BASED << NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_VERSION_BS);

        /// Convert time part to MSB (network order)
        ///
        this->TimeToMsb();

        ssize_t count = 0, ength = 0;
        size_t size = 0;

        /// get clock seqence from a crypto-quality
        /// random number generator.
        ///
        uint16_t uuidClockSeq = 0;
        size  = sizeof(uuidClockSeq);
        if (size != (count = random.generate(&uuidClockSeq, size))) {
            XOS_LOG_ERROR("failed " << count << " on random.Generate(..., " << size << ")");
            return false;
        }

        /// Encode the sequence into the UUID struct (network order).
        ///
        actual.m_clockSeq.m_low = (uuidClockSeq & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_LOW_BM);
        actual.m_clockSeq.m_hiAndRes = ((uuidClockSeq & NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_BM) >> NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_BS);
        actual.m_clockSeq.m_hiAndRes |= (NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_RFC4122_BV << NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_RESERVED_BS);

        /// get node ID from the MAC address.
        ///
        const typename From::MacAddress* macAddress = ethernet.Address();
        if ((macAddress)) {
            XOS_LOG_TRACE("MAC address = " << xos::base::X_to_string(macAddress->m_b, sizeof(macAddress->m_b), ':'));

            /// copy MAC address to node ID (network order).
            ///
            memcpy(actual.m_node.m_b, macAddress->m_b, sizeof(actual.m_node.m_b));
        } else {
            XOS_LOG_ERROR("failed 0 on ethernet.Address()");
            return false;
        }

        /// Generate an MD5 hash of the MAC address to
        /// hide it's identity.
        ///
        uint8_t hash[16];
        if ((sizeof(hash)) != (count = md5(hash, sizeof(hash), actual.m_b, sizeof(actual.m_b)))) {
            XOS_LOG_ERROR("failed " << count << " on md5()");
            return false;
        } else {
            XOS_LOG_TRACE("MD5 hash = " << xos::base::x_to_string(hash, sizeof(hash)));
            memcpy(actual.m_node.m_b, hash, sizeof(actual.m_node.m_b));
        }

        /// Set MAC address multicast bit per RFC4122
        ///
        actual.m_node.m_macAddress.m_oui.m_b[0] &= ~NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST;
        actual.m_node.m_macAddress.m_oui.m_b[0] |= NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_MULTICAST;
        this->SetString(actual);
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual uint64_t Time() const {
        uint64_t now = 0;
        struct timeval tv;

        /// get current time
        ///
        gettimeofday(&tv, (struct timezone*)0);

        /// Offset between UUID formatted times and Unix formatted times.
        /// UUID UTC base time is October 15, 1582.
        /// Unix base time is January 1, 1970.
        ///
        now = (tv.tv_sec * 10000000) + (tv.tv_usec * 10) + 0x01B21DD213814000LL;
        return now;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS Identifiert
typedef Identifiert<> Identifier;

} /// namespace posix
} /// namespace unique
} /// namespace network
} /// namespace rete

#endif /// _RETE_NETWORK_UNIQUE_POSIX_IDENTIFIER_HPP 
