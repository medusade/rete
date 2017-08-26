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
///   File: Endpoint.hpp
///
/// Author: $author$
///   Date: 8/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_ENDPOINT_HPP
#define _XOS_NETWORK_SOCKETS_ENDPOINT_HPP

#include "xos/network/sockets/Address.hpp"
#include "xos/network/Endpoint.hpp"
#include "xos/base/Attached.hpp"
#include "xos/logger/Interface.hpp"

namespace xos {
namespace network {
namespace sockets {

typedef int AddrIndex;
enum {
    FirstAddrIndex = 0,
    LastAddrIndex = -1
};
typedef ushort SockPort;
typedef socklen_t SockLen;
typedef struct sockaddr SockAddr;

typedef SockAddr* SockAddrAttachedTo;
typedef AttachT
<SockAddrAttachedTo, int, 0,
 AttachException, Address> EndpointTAddrImplements;
typedef network::Endpoint EndpointTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: EndpointT
///////////////////////////////////////////////////////////////////////
template
<class TAddrImplements = EndpointTAddrImplements,
 class TImplements = EndpointTImplements>

class _EXPORT_CLASS EndpointT
: virtual public TImplements, virtual public TAddrImplements {
public:
    typedef TImplements Implements;
    typedef TAddrImplements AddrImplements;
    typedef typename AddrImplements::family_t::which_t AddressFamily;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttachedTo AttachFirst(const String& host, SockPort port) {
        const char* chars = host.HasChars();
        if ((chars)) { return this->AttachFirst(chars, port); }
        return this->Attach(port);
    }
    virtual SockAddrAttachedTo AttachLast(const String& host, SockPort port) {
        const char* chars = host.HasChars();
        if ((chars)) { return this->AttachLast(chars, port); }
        return this->Attach(port);
    }
    virtual SockAddrAttachedTo Attach(const String& host, SockPort port) {
        const char* chars = host.HasChars();
        if ((chars)) { return this->Attach(chars, port); }
        return this->Attach(port);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttachedTo AttachFirst(const char* host, SockPort port) {
        if ((host)) { return this->Attach(host, FirstAddrIndex, port); }
        return this->Attach(port);
    }
    virtual SockAddrAttachedTo AttachLast(const char* host, SockPort port) {
        if ((host)) { return this->Attach(host, LastAddrIndex, port); }
        return this->Attach(port);
    }
    virtual SockAddrAttachedTo Attach(const char* host, SockPort port) {
        if ((host)) { return this->Attach(host, FirstAddrIndex, port); }
        return this->Attach(port);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttachedTo Attach
    (const char_t* host, AddrIndex index, SockPort port) {
        SockAddrAttachedTo saddr = 0;
        struct addrinfo* addrs = 0;
        int err = 0;

        XOS_LOG_DEBUG("getaddrinfo(\"" << host << "\",...)...");
        if (!(err = getaddrinfo(host, 0, 0, &addrs))) {
            const AddressFamily family = this->Family();
            struct addrinfo* addr = 0;
            AddrIndex addr_i = 0;

            XOS_LOG_DEBUG("...getaddrinfo(\"" << host << "\",...) family = " << family);
            for (addr_i = 0, addr = addrs; addr; addr = addr->ai_next) {
                const AddressFamily addrfamily = addr->ai_family;
                char addrhost[NI_MAXHOST];

                XOS_LOG_DEBUG("getnameinfo(...)... family = " << addrfamily);
                if (!(err = getnameinfo
                    (addr->ai_addr, addr->ai_addrlen, addrhost, sizeof(addrhost)-1, 0, 0, 0))) {

                    addrhost[sizeof(addrhost)-1] = 0;
                    XOS_LOG_DEBUG("...getnameinfo(..., addrhost = \"" << addrhost << "\",...)");
                    if (family == (addrfamily)) {
                        if ((addr_i == index) || ((LastAddrIndex == index) && !(addr->ai_next))) {
                            XOS_LOG_DEBUG("...found family " << family << " address[" << addr_i << "]");
                            saddr = this->Attach(addr->ai_addr, addr->ai_addrlen, port);
                            break;
                        } else {
                            ++addr_i;
                        }
                    }
                } else {
                    XOS_LOG_ERROR("...failed " << this->LastError() << " on getnameinfo(...)");
                }
            }
            freeaddrinfo(addrs);
        } else {
            XOS_LOG_ERROR("...failed " << this->LastError() << " on getaddrinfo(\"" << host << "\",...)");
        }
        return saddr;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttachedTo Attach
    (const SockAddrAttachedTo socketAddress, SockLen socketAddressLen, SockPort port) {
        return 0;
    }
    virtual SockAddrAttachedTo Attach(SockPort port) {
        return 0;
    }
    virtual SockAddrAttachedTo Attach(const char_t* path) {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttachedTo SocketAddress(SockLen& len) const {
        len = SocketAddressLen();
        return this->AttachedTo();
    }
    virtual SockAddrAttachedTo SocketAddress() const {
        return this->AttachedTo();
    }
    virtual SockLen SocketAddressLen() const {
        return 0;
    }
    virtual operator SockAddrAttachedTo() const {
        return this->SocketAddress();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int LastError() const {
        return errno;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef EndpointT<> EndpointImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Endpoint
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Endpoint: virtual public EndpointImplements {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_ENDPOINT_HPP 
