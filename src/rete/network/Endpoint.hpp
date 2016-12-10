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

#include "rete/network/Address.hpp"
#include "rete/base/Attached.hpp"
#include "crono/io/Logger.hpp"

namespace rete {
namespace network {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef int AddrIndex;
enum {
    FirstAddrIndex = 0,
    LastAddrIndex = -1
};
typedef u_short SockPort;
typedef socklen_t SockLen;
typedef struct sockaddr SockAddr;

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
    virtual SockAddrAttached AttachFirst(const String& host, SockPort port) {
        const char* chars = host.has_chars();
        if ((chars)) { return this->AttachFirst(chars, port); }
        return  0;
    }
    virtual SockAddrAttached AttachLast(const String& host, SockPort port) {
        const char* chars = host.has_chars();
        if ((chars)) { return this->AttachLast(chars, port); }
        return  0;
    }
    virtual SockAddrAttached AttachFirst(const char* host, SockPort port) {
        return this->Attach(host, FirstAddrIndex, port);
    }
    virtual SockAddrAttached AttachLast(const char* host, SockPort port) {
        return this->Attach(host, LastAddrIndex, port);
    }
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
};
typedef EndpointT<> Endpoint;

} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_ENDPOINT_HPP 
