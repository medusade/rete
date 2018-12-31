///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 12/1/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_ENDPOINT_HPP
#define _RETE_NETWORK_ENDPOINT_HPP

#include "rete/network/local/Location.hpp"
#include "rete/network/sockets/Location.hpp"
#include "rete/network/Location.hpp"
#include "rete/network/Address.hpp"
#include "rete/base/Attached.hpp"
#include "crono/io/Logger.hpp"

namespace rete {
namespace network {

typedef SockAddr* SockAddrAttached;
typedef patrona::AttacherT<SockAddrAttached, int, 0, Address> SockAddrAttacher;
typedef SockAddrAttacher EndpointTImplements;
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
    virtual SockAddrAttached AttachFirst(const Location& location) {
        SockAddrAttached (EndpointT::*attach)
        (const char* host, SockPort port) = &EndpointT::AttachFirst;
        return this->Attach(attach, location);
    }
    virtual SockAddrAttached AttachLast(const Location& location) {
        SockAddrAttached (EndpointT::*attach)
        (const char* host, SockPort port) = &EndpointT::AttachLast;
        return this->Attach(attach, location);
    }
    virtual SockAddrAttached Attach(const Location& location) {
        SockAddrAttached (EndpointT::*attach)
        (const char* host, SockPort port) = &EndpointT::Attach;
        const local::Location* localLocation = 0;
        if ((localLocation = location.LocalLocation())) {
            return this->Attach(*localLocation);
        }
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
    virtual SockAddrAttached Attach(const String& path) {
        const char* chars = 0;
        if ((chars = path.has_chars())) {
            return this->Attach(chars);
        }
        return 0;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached AttachFirst(const char* host, SockPort port) {
        return this->Attach(host, FirstAddrIndex, port);
    }
    virtual SockAddrAttached AttachLast(const char* host, SockPort port) {
        return this->Attach(host, LastAddrIndex, port);
    }
    virtual SockAddrAttached Attach(const char* host, SockPort port) {
        return this->Attach(host, FirstAddrIndex, port);
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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const sockets::Endpoint* const_SocketsEndpoint() const {
        return this->SocketsEndpoint();
    }
    virtual sockets::Endpoint* SocketsEndpoint() const {
        return 0;
    }
    
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach
    (SockAddrAttached (EndpointT::*attach)
     (const char* host, SockPort port), const Location& location) {
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
    virtual SockAddrAttached Attach(const local::Location& location) {
        const char* chars = 0;
        if ((chars = location.Path())) {
            SockAddrAttached sockAddr = 0;
            sockAddr = this->Attach(chars);
            return  sockAddr;
        }
        return  0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef EndpointT<> Endpoint;

} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_ENDPOINT_HPP 
