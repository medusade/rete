///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: Addresses.hpp
///
/// Author: $author$
///   Date: 11/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_POSIX_INTERFACES_ADDRESSES_HPP
#define _XOS_NETWORK_SOCKETS_POSIX_INTERFACES_ADDRESSES_HPP

#include "xos/network/sockets/interfaces/Addresses.hpp"
#include "xos/logger/Interface.hpp"
#include <ifaddrs.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <net/if_types.h>

namespace xos {
namespace network {
namespace sockets {
namespace posix {
namespace interfaces {

///////////////////////////////////////////////////////////////////////
///  Class: AddressesT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = sockets::interfaces::Addresses, class TExtends = Base>

class _EXPORT_CLASS AddressesT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Implements::Address Address;
    typedef typename Implements::AddressAt AddressAt;
    typedef typename Implements::UnspecAddress UnspecAddress;
    typedef typename Implements::LinkAddress LinkAddress;
    typedef typename Implements::IpAddress IpAddress;
    typedef typename Implements::IpV4Address IpV4Address;
    typedef typename Implements::IpV6Address IpV6Address;
    typedef typename Implements::EthernetAddress EthernetAddress;
    typedef typename Address::family_t Family;
    typedef typename UnspecAddress::char_t char_t;

    typedef struct ifaddrs IFAddrs;
    typedef struct sockaddr SockAddr;
    typedef struct sockaddr_dl SockAddrDl;
    typedef struct sockaddr_in SockAddrIn;
    typedef struct sockaddr_in6 SockAddrIn6;
    typedef in_addr InAddr;
    typedef in6_addr In6Addr;
    
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: AddressesT
    ///////////////////////////////////////////////////////////////////////
    AddressesT() {
    }
    virtual ~AddressesT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Address* GetFirst(AddressAt& at) {
        const Family family = AF_UNSPEC;
        return GetFirst(at, family);
    }
    virtual const Address* GetNext(AddressAt& at) {
        const Family family = AF_UNSPEC;
        return GetNext(at, family);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Address* GetFirst(AddressAt& at, const Family& family) {
        const IFAddrs* ifAddrs = 0;
        if ((GetFirst(ifAddrs))) {
            const Address* address = 0;
            do {
                if ((address = Get(*ifAddrs, family))) {
                    at = ifAddrs;
                    return address;
                }
            } while (GetNext(ifAddrs));
        }
        return 0;
    }
    virtual const Address* GetNext(AddressAt& at, const Family& family) {
        const IFAddrs* ifAddrs = 0;
        if ((ifAddrs = (const IFAddrs*)at) && (GetNext(ifAddrs))) {
            const Address* address = 0;
            do {
                if ((address = Get(*ifAddrs, family))) {
                    at = ifAddrs;
                    return address;
                }
            } while (GetNext(ifAddrs));
        }
        return 0;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Address* Get(const IFAddrs& ifAddrs, const Family& family) {
        SockAddr* sa = 0;
        if ((sa = ifAddrs.ifa_addr)) {
            Family af = AF_UNSPEC;            
            if (((af = sa->sa_family) == family) || (family == AF_UNSPEC)) {
                return Get(*sa, af);
            }
        }
        return 0;
    }
    virtual const Address* Get(const SockAddr& addr, const Family& family) {
        const Address* address = 0;
        switch (family) {
        case AF_INET:
            XOS_LOG_DEBUG("Get_AF_INET(addr)...");
            address = Get_AF_INET(addr);
            break;
        case AF_INET6:
            XOS_LOG_DEBUG("Get_AF_INET6(addr)...");
            address = Get_AF_INET6(addr);
            break;
        case AF_LINK:
            XOS_LOG_DEBUG("Get_AF_LINK(addr)...");
            address = Get_AF_LINK(addr);
            break;
        case AF_UNSPEC:
        default:
            XOS_LOG_DEBUG("Get_AF_UNSPEC(addr)...");
            address = Get_AF_UNSPEC(addr);
            break;
        }
        return address;
    }
    virtual const Address* Get_AF_INET(const SockAddr& addr) {
        const SockAddrIn& addrIn = (const SockAddrIn&)addr;
        const InAddr& inAddr = addrIn.sin_addr;
        const char_t* data = (const char_t*)&inAddr;
        size_t len = sizeof(InAddr);
        XOS_LOG_DEBUG("m_ipV4.SetData(data, len = " << len << ")...");
        m_ipV4.SetData(data, len);
        return &m_ipV4;
    }
    virtual const Address* Get_AF_INET6(const SockAddr& addr) {
        const SockAddrIn6& addrIn6 = (const SockAddrIn6&)addr;
        const In6Addr& in6Addr = addrIn6.sin6_addr;
        const char_t* data = (const char_t*)&in6Addr;
        size_t len = sizeof(In6Addr);
        XOS_LOG_DEBUG("m_ipV6.SetData(data, len = " << len << ")...");
        m_ipV6.SetData(data, len);
        return &m_ipV6;
    }
    virtual const Address* Get_AF_LINK(const SockAddr& addr) {
        const SockAddrDl& addrDl = (const SockAddrDl&)addr;
        const Address* address = 0;
        switch (addrDl.sdl_type) {
        case IFT_ETHER:
            XOS_LOG_DEBUG("Get_IFT_ETHER_AF_LINK(addrDl)...");
            address = Get_IFT_ETHER_AF_LINK(addrDl);
            break;
        case IFT_OTHER:
        default:
            XOS_LOG_DEBUG("Get_IFT_OTHER_AF_LINK(addrDl)...");
            address = Get_IFT_OTHER_AF_LINK(addrDl);
            break;
        }
        return address;
    }
    virtual const Address* Get_AF_UNSPEC(const SockAddr& addr) {
        const char_t* data = (const char_t*)addr.sa_data;
        size_t len = addr.sa_len;
        if ((data) && (len)) {
            XOS_LOG_DEBUG("m_unspec.SetData(data, len = " << len << ")...");
            m_unspec.SetData(data, len);
            return &m_unspec;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Address* Get_IFT_ETHER_AF_LINK(const SockAddrDl& addr) {
        size_t nlen = addr.sdl_nlen, alen = addr.sdl_alen, slen = addr.sdl_slen;
        const char_t* data = (const char_t*)addr.sdl_data;
        size_t len = nlen + alen + slen;
        if ((data) && (len)) {
            const char* llName = (const char*)data;
            const EthernetAddress* llAddr = (const EthernetAddress*)(llName + nlen);
            XOS_LOG_DEBUG("m_link.SetData(data, len = " << len << ")...");
            m_link.SetData(data, len);
            return &m_link;
        }
        return 0;
    }
    virtual const Address* Get_IFT_OTHER_AF_LINK(const SockAddrDl& addr) {
        const char_t* data = (const char_t*)addr.sdl_data;
        size_t len = addr.sdl_nlen + addr.sdl_alen + addr.sdl_slen;
        if ((data) && (len)) {
            XOS_LOG_DEBUG("m_link.SetData(data, len = " << len << ")...");
            m_link.SetData(data, len);
            return &m_link;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const IFAddrs* GetFirst(const IFAddrs*& ifAddrs) const {
        IFAddrs* addrs = 0;
        int err = 0;

        XOS_LOG_DEBUG("getifaddrs(&ifAddrs)...");
        if (!(err = getifaddrs(&addrs))) {
            ifAddrs = addrs;
            return ifAddrs;
        } else {
            XOS_LOG_ERROR("...failed errno = " << errno << " on getifaddrs(&ifAddrs)");
        }
        return 0;
    }
    virtual const IFAddrs* GetNext(const IFAddrs*& ifAddrs) const {
        if ((ifAddrs)) {
            ifAddrs = ifAddrs->ifa_next;
        }
        return ifAddrs;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    UnspecAddress m_unspec;
    LinkAddress m_link;
    IpV4Address m_ipV4;
    IpV6Address m_ipV6;
};
typedef AddressesT<> Addresses;

} // namespace interfaces 
} // namespace posix 
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_POSIX_INTERFACES_ADDRESSES_HPP 

        

