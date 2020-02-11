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
#ifndef RETE_NETWORK_UNIQUE_IDENTIFIER_HPP
#define RETE_NETWORK_UNIQUE_IDENTIFIER_HPP

#include "rete/network/ethernet/Address.hpp"
#include "cifra/crypto/random/generator.hpp"
#include "cifra/crypto/hash/base.hpp"
#include "xos/base/to_string.hpp"
#include "xos/base/wrapped.hpp"
#include "xos/io/string/writer.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_LOW_BM 0x00000000FFFFFFFFLL
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_LOW_BS 0

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_MID_BM 0x0000FFFF00000000LL
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_MID_BS 32

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_BM 0x0FFF000000000000LL
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_BS 48

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_VERSION_BM 0xF000
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_TIME_HI_VERSION_BS 12

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_VERSION_BM 0xF0
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_VERSION_BS 4

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_LOW_BM 0x00FF
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_LOW_BS 0

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_BM 0x1F00
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_BS 8

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_RESERVED_BM 0xE0
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_CLOCK_SEQ_HI_RESERVED_BS 5

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_NCS_COMPATIBILITY_BM 0x4
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_NCS_COMPATIBILITY_BV 0x0

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_RFC4122_BM 0x6
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_RFC4122_BV 0x4

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BM 0x7
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_MICROSOFT_COMPATIBILITY_BV 0x6

#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_FUTURE_DEFINITION_BM 0x7
#define NETWORK_UNIQUE_ACTUAL_IDENTIFIER_RESERVED_VARIANT_FUTURE_DEFINITION_BV 0x7

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace rete {
namespace network {
namespace unique {

namespace actual {
#include "xos/platform/platform_packed_begin.h"
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
struct PACKED_STRUCT Identifier {
    enum {
        VERSION_NONE            = 0x0,

        VERSION_TIME_BASED      = 0x1,
        VERSION_DCE_SECURITY    = 0x2,
        VERSION_NAME_BASED_MD5  = 0x3,
        VERSION_RANDOM          = 0x4,
        VERSION_NAME_BASED_SHA1 = 0x5,

        VERSION_NEXT,
        VERSION_FIRST = VERSION_NONE+1,
        VERSION_LAST = VERSION_NEXT-1,
        VERSION_COUNT = VERSION_LAST-VERSION_FIRST+1
    };
    enum {
        RESERVED_VARIANT_FIRST,

        RESERVED_VARIANT_FUTURE_DEFINITION = RESERVED_VARIANT_FIRST,
        RESERVED_VARIANT_MICROSOFT_COMPATIBILITY,
        RESERVED_VARIANT_RFC4122,
        RESERVED_VARIANT_NCS_COMPATIBILITY,

        RESERVED_VARIANT_NEXT,
        RESERVED_VARIANT_LAST = RESERVED_VARIANT_NEXT-1,
        RESERVED_VARIANT_COUNT = RESERVED_VARIANT_LAST-RESERVED_VARIANT_FIRST+1
    };
    typedef ethernet::actual::Address MacAddress;

    union {
        uint8_t m_b[16];
        uint16_t m_w[8];
        uint32_t m_l[4];

        struct PACKED_STRUCT {
            union {
                uint8_t m_b[4];
                uint16_t m_w[2];
                uint32_t m_l;
            } m_timeLow;

            union {
                uint8_t m_b[2];
                uint16_t m_w;
            } m_timeMid;

            union {
                uint8_t m_b[2];
                uint16_t m_w;

                struct PACKED_STRUCT {
                    uint8_t m_version;
                    uint8_t m_hi;
                };
            } m_timeHiAndVersion;

            union {
                uint8_t m_b[2];
                uint16_t m_w;

                struct PACKED_STRUCT {
                    uint8_t m_hiAndRes;
                    uint8_t m_low;
                };
            } m_clockSeq;

            union {
                uint8_t m_b[6];
                uint16_t m_w[3];

                struct PACKED_STRUCT {
                    union {
                        uint8_t m_b[2];
                        uint16_t m_w;
                    } m_nodeHi;

                    union {
                        uint8_t m_b[4];
                        uint16_t m_w[2];
                        uint32_t m_l;
                    } m_nodeLow;
                };

                MacAddress m_macAddress;
            } m_node;
        };
    };
};
#include "xos/platform/platform_packed_end.h"
} /// namespace actual

///////////////////////////////////////////////////////////////////////
///  Class: IdentifierT
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = xos::base::wrappedt<actual::Identifier>, 
 class TImplements = typename TExtends::Implements>
class EXPORT_CLASS IdentifierT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef IdentifierT Derives; 

    typedef typename Extends::wrapped_t wrapped_t;
    typedef xos::base::string string_t;
    
    ///////////////////////////////////////////////////////////////////////
    ///  Class: Version
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Version {
    public:
        typedef int Which;
        enum {
            None          = actual::Identifier::VERSION_NONE,
            TimeBased     = actual::Identifier::VERSION_TIME_BASED,
            DceSecurity   = actual::Identifier::VERSION_DCE_SECURITY,
            NameBasedMd5  = actual::Identifier::VERSION_NAME_BASED_MD5,
            Random        = actual::Identifier::VERSION_RANDOM,
            NameBasedSha1 = actual::Identifier::VERSION_NAME_BASED_SHA1
        };
        ///////////////////////////////////////////////////////////////////////
        /// constructors / destructor
        ///////////////////////////////////////////////////////////////////////
        Version(const Version& copy): m_which(copy.m_which) {}
        Version(Which which = None): m_which(which) {}
        operator Which () const { return m_which; }
    protected:
        Which m_which;
    }; /// class _EXPORT_CLASS Version

    ///////////////////////////////////////////////////////////////////////
    ///  Class: From
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS From {
    public:
        typedef cifra::crypto::random::generator Random;
        typedef cifra::crypto::hash::implement_base Md5;
        typedef cifra::crypto::hash::implement_base Sha1;
        typedef network::ethernet::actual::Address MacAddress;
        ///////////////////////////////////////////////////////////////////////
        ///  Class: Ethernet
        ///////////////////////////////////////////////////////////////////////
        class _EXPORT_CLASS Ethernet {
        public:
            typedef From::MacAddress MacAddress;
            virtual const MacAddress* Address() const = 0;
        }; /// class _EXPORT_CLASS Ethernet
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual Ethernet& ethernet() const = 0;
        virtual Random& random() const = 0;
        virtual Md5& md5() const = 0;
        virtual Sha1& sha1() const = 0;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    }; /// class _EXPORT_CLASS From

    ///////////////////////////////////////////////////////////////////////
    /// constructors / destructor
    ///////////////////////////////////////////////////////////////////////
    IdentifierT(const IdentifierT& copy): Extends(copy) {
    }
    IdentifierT() {
    }
    virtual ~IdentifierT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Generate(From& from, typename Version::Which which = Version::None) {
        return false;
    }
    virtual void Clear() {
        memset(&this->wrapped_, 0, sizeof(wrapped_t));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteX(xos::io::string::writer& writer, char A = 'A', char separator = '-') const {
        ssize_t count = 0, count2 = 0;

        if (0 < (count = WriteX
            (writer, this->wrapped_.m_timeLow.m_b,
             sizeof(this->wrapped_.m_timeLow.m_b), A, separator))) {

            if (0 < (count2 = WriteX
                (writer, this->wrapped_.m_timeMid.m_b,
                 sizeof(this->wrapped_.m_timeMid.m_b), A, separator))) {
    
                if (0 < (count2 = WriteX
                    (writer, this->wrapped_.m_timeHiAndVersion.m_b,
                     sizeof(this->wrapped_.m_timeHiAndVersion.m_b), A, separator))) {
        
                    if (0 < (count2 = WriteX
                        (writer, this->wrapped_.m_clockSeq.m_b,
                         sizeof(this->wrapped_.m_clockSeq.m_b), A, separator))) {
            
                        if (0 < (count2 = WriteX
                            (writer, this->wrapped_.m_node.m_b,
                             sizeof(this->wrapped_.m_node.m_b), A))) {
                            count += count2;
                        }
                    }
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator != (const IdentifierT& to) const {
        return (0 != (memcmp(&this->wrapped_, &to.wrapped_, sizeof(wrapped_t))));
    }
    virtual bool operator == (const IdentifierT& to) const {
        return (0 == (memcmp(&this->wrapped_, &to.wrapped_, sizeof(wrapped_t))));
    }
    virtual operator wrapped_t& () const {
        return (wrapped_t&)this->wrapped_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& SetString(const wrapped_t& to) {
        string_t& string = (string_t&)m_string;
        xos::io::string::writer writer(string);
        string.clear();
        WriteX(writer);
        return (string_t&)m_string;
    }
    virtual string_t& String() const {
        return (string_t&)m_string;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteX
    (xos::io::string::writer& writer, const uint8_t* value, size_t size, char A = 'A', char separator = 0) const {
        const bool upperCase = ('A' == A);
        ssize_t count = 0, count2 = 0;

        if (0 < (count = writer.writex(value, size, upperCase))) {
            if (separator) {
                if (0 < (count2 = writer.write(&separator, sizeof(separator)))) {
                    count += count2;
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual uint8_t& TimeToMsb() {
        ToMsb(*this->wrapped_.m_timeLow.m_b, this->wrapped_.m_timeLow.m_l, sizeof(this->wrapped_.m_timeLow.m_l));
        ToMsb(*this->wrapped_.m_timeMid.m_b, this->wrapped_.m_timeMid.m_w, sizeof(this->wrapped_.m_timeMid.m_w));
        ToMsb(*this->wrapped_.m_timeHiAndVersion.m_b, this->wrapped_.m_timeHiAndVersion.m_w, sizeof(this->wrapped_.m_timeHiAndVersion.m_w));
        return *this->wrapped_.m_b;
    }
    virtual uint8_t& ToMsb(uint8_t& to, unsigned long value, size_t size) const {
        unsigned long msbValue = 0;
        for (int b = 0; b < size; ++b) {
            msbValue <<= 8;
            msbValue |= (value & 0xFF);
            value >>= 8;
        }
        for (int b = 0; b < size; ++b) {
            (&to)[b] = (msbValue & 0xFF);
            msbValue >>= 8;
        }
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t m_string;
}; /// class exported IdentifierT
typedef IdentifierT<> Identifier;

} /// namespace unique
} /// namespace network
} /// namespace rete

#endif /// RETE_NETWORK_UNIQUE_IDENTIFIER_HPP
