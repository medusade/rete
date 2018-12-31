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
///   Date: 7/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETS_ENDPOINT_HPP
#define _RETE_NETWORK_SOCKETS_ENDPOINT_HPP

#include "rete/network/sockets/Location.hpp"
#include "rete/network/sockets/Address.hpp"
#include "rete/network/Endpoint.hpp"

namespace rete {
namespace network {
namespace sockets {

typedef network::SockAddr SockAddr;
typedef network::SockAddrAttached SockAddrAttached;
typedef network::SockAddrAttacher SockAddrAttacher;
typedef network::Endpoint EndpointTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: EndpointT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = EndpointTImplements>

class _EXPORT_CLASS EndpointT: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached AttachFirst(const sockets::Location& location) {
        SockAddrAttached (EndpointT::*attach)
        (const char* host, SockPort port) = &EndpointT::AttachFirst;
        return this->Attach(attach, location);
    }
    virtual SockAddrAttached AttachLast(const sockets::Location& location) {
        SockAddrAttached (EndpointT::*attach)
        (const char* host, SockPort port) = &EndpointT::AttachLast;
        return this->Attach(attach, location);
    }
    virtual SockAddrAttached Attach(const sockets::Location& location) {
        SockAddrAttached (EndpointT::*attach)
        (const char* host, SockPort port) = &EndpointT::Attach;
        return this->Attach(attach, location);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached AttachFirst(const String& host, SockPort port) {
        SockAddrAttached (EndpointT::*attach)
        (const char* host, SockPort port) = &EndpointT::AttachFirst;
        return this->Attach(attach, host, port);
    }
    virtual SockAddrAttached AttachLast(const String& host, SockPort port) {
        SockAddrAttached (EndpointT::*attach)
        (const char* host, SockPort port) = &EndpointT::AttachLast;
        return this->Attach(attach, host, port);
    }
    virtual SockAddrAttached Attach(const String& host, SockPort port) {
        SockAddrAttached (EndpointT::*attach)
        (const char* host, SockPort port) = &EndpointT::Attach;
        return this->Attach(attach, host, port);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached AttachFirst(const char* host, SockPort port) {
        if ((host)) { return this->Attach(host, FirstAddrIndex, port); }
        return this->Attach(port);
    }
    virtual SockAddrAttached AttachLast(const char* host, SockPort port) {
        if ((host)) { return this->Attach(host, LastAddrIndex, port); }
        return this->Attach(port);
    }
    virtual SockAddrAttached Attach(const char* host, SockPort port) {
        if ((host)) { return this->Attach(host, FirstAddrIndex, port); }
        return this->Attach(port);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach
    (const char_t* host, AddrIndex index, SockPort port) {
        SockAddrAttached saddr = 0;
        struct addrinfo* addrs = 0;
        int err = 0;

        CRONO_LOG_DEBUG("getaddrinfo(\"" << host << "\",...)...");
        if (!(err = getaddrinfo(host, 0, 0, &addrs))) {
            const AddressFamily family = this->Family();
            struct addrinfo* addr = 0;
            AddrIndex addr_i = 0;

            CRONO_LOG_DEBUG("...getaddrinfo(\"" << host << "\",...) family = " << family);
            for (addr_i = 0, addr = addrs; addr; addr = addr->ai_next) {
                const AddressFamily addrfamily = addr->ai_family;
                char addrhost[NI_MAXHOST];

                CRONO_LOG_DEBUG("getnameinfo(...)... family = " << addrfamily);
                if (!(err = getnameinfo
                    (addr->ai_addr, addr->ai_addrlen, addrhost, sizeof(addrhost)-1, 0, 0, 0))) {

                    addrhost[sizeof(addrhost)-1] = 0;
                    CRONO_LOG_DEBUG("...getnameinfo(..., addrhost = \"" << addrhost << "\",...)");
                    if (family == (addrfamily)) {
                        if ((addr_i == index) || ((LastAddrIndex == index) && !(addr->ai_next))) {
                            CRONO_LOG_DEBUG("...found family " << family << " address[" << addr_i << "]");
                            saddr = this->Attach(addr->ai_addr, addr->ai_addrlen, port);
                            break;
                        } else {
                            ++addr_i;
                        }
                    }
                } else {
                    CRONO_LOG_ERROR("...failed " << this->LastError() << " on getnameinfo(...)");
                }
            }
            freeaddrinfo(addrs);
        } else {
            CRONO_LOG_ERROR("...failed " << this->LastError() << " on getaddrinfo(\"" << host << "\",...)");
        }
        return saddr;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach
    (const SockAddrAttached socketAddress, SockLen socketAddressLen, SockPort port) {
        return 0;
    }
    virtual SockAddrAttached Attach(SockPort port) {
        return 0;
    }
    virtual SockAddrAttached Attach(const char_t* path) {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached SocketAddress(SockLen& len) const {
        len = SocketAddressLen();
        return this->AttachedTo();
    }
    virtual SockAddrAttached SocketAddress() const {
        return this->AttachedTo();
    }
    virtual SockLen SocketAddressLen() const {
        return 0;
    }
    virtual operator SockAddrAttached () const {
        return this->SocketAddress();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int LastError() const {
        return errno;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach
    (SockAddrAttached (EndpointT::*attach)
     (const char* host, SockPort port), const network::Location& location) {
        if ((attach)) {
            SockAddrAttached sockAddr = 0;
            const sockets::Location* socketsLocation = 0;

            if ((socketsLocation = location.SocketsLocation())) {
                sockAddr = this->Attach(attach, *socketsLocation);
            }
            return  sockAddr;
        }
        return  0;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach
    (SockAddrAttached (EndpointT::*attach)
     (const char* host, SockPort port), const sockets::Location& location) {
        if ((attach)) {
            SockAddrAttached sockAddr = 0;
            SockPort port = 0;

            if (0 < (port = location.Port())) {
                const char* chars = 0;
                if ((chars = location.Host())) {
                    sockAddr = (this->*attach)(chars, port);
                } else {
                    sockAddr = (this->*attach)(0, port);
                }
            }
            return  sockAddr;
        }
        return  0;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach
    (SockAddrAttached (EndpointT::*attach)
     (const char* host, SockPort port), const String& host, SockPort port) {
        if ((attach)) {

            if (0 < (port)) {
                SockAddrAttached sockAddr = 0;
                const char* chars = 0;

                if ((chars = host.has_chars())) {
                    sockAddr = (this->*attach)(chars, port);
                } else {
                    sockAddr = (this->*attach)(0, port);
                }
                return  sockAddr;
            }
        }
        return  0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef EndpointT<> EndpointImplement;

///////////////////////////////////////////////////////////////////////
///  Class: Endpoint
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Endpoint: virtual public EndpointImplement {
public:
    typedef EndpointImplement Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Endpoint* SocketsEndpoint() const {
        return (Endpoint*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace sockets
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETS_ENDPOINT_HPP 
