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
#ifndef _XOS_NETWORK_SOCKETS_IP_V4_ENDPOINT_HPP
#define _XOS_NETWORK_SOCKETS_IP_V4_ENDPOINT_HPP

#include "xos/network/sockets/ip/v4/Address.hpp"
#include "xos/network/sockets/ip/Endpoint.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace ip {
namespace v4 {

typedef struct sockaddr_in SockAddr;

typedef ip::EndpointTImplements EndpointTImplements;
typedef ip::EndpointT<Address> EndpointTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: EndpointT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = EndpointTImplements, class TExtends = EndpointTExtends>

class _EXPORT_CLASS EndpointT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    EndpointT(const String& host, AddrIndex index, SockPort port) {
        ::memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->Attach(host, index, port))) {
        }
    }
    EndpointT(const String& host, SockPort port) {
        ::memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->AttachFirst(host, port))) {
        }
    }
    ///////////////////////////////////////////////////////////////////////
    EndpointT(const char* host, AddrIndex index, SockPort port) {
        ::memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->Attach(host, index, port))) {
        }
    }
    EndpointT(const char* host, SockPort port) {
        ::memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->AttachFirst(host, port))) {
        }
    }
    ///////////////////////////////////////////////////////////////////////
    EndpointT
    (const SockAddrAttachedTo socketAddress, SockLen socketAddressLen, SockPort port) {
        ::memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->Attach(socketAddress, socketAddressLen, port))) {
        }
    }
    EndpointT(SockPort port) {
        memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->Attach(port))) {
        }
    }
    ///////////////////////////////////////////////////////////////////////
    EndpointT(const EndpointT& copy) {
        ::memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        this->Attach
        ((SockAddrAttachedTo)&copy.m_socketAddress,
         copy.m_socketAddressLen, copy.m_socketAddressPort);
    }
    EndpointT() {
        ::memset(&m_socketAddress, 0, sizeof(m_socketAddress));
    }
    virtual ~EndpointT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Attach;
    virtual SockAddrAttachedTo Attach
    (const SockAddrAttachedTo socketAddress, SockLen socketAddressLen, SockPort port) {
        if ((socketAddress) && (socketAddressLen == (this->SocketAddressLen()))) {
            if (this->Family() == (socketAddress->sa_family)) {
                SockAddrAttachedTo attached = 0;
                if ((attached = this->Attach(port))) {
                    const SockAddr& sockAddr = (const SockAddr&)(*socketAddress);
                    m_socketAddress.sin_addr.s_addr = sockAddr.sin_addr.s_addr;
                }
                return attached;
            }
        }
        return 0;
    }
    virtual SockAddrAttachedTo Attach(SockPort port) {
        ::memset(&m_socketAddress, 0, this->m_socketAddressLen = (sizeof(m_socketAddress)));
        m_socketAddress.sin_family = this->Family();
        m_socketAddress.sin_addr.s_addr = INADDR_ANY;
        m_socketAddress.sin_port = htons(this->m_socketAddressPort = port);
        return Extends::Attach((SockAddrAttachedTo)(&m_socketAddress));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockLen SocketAddressLen() const {
        return ((SockLen)sizeof(m_socketAddress));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    SockAddr m_socketAddress;
};
typedef EndpointT<> Endpoint;

} // namespace v4
} // namespace ip 
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_IP_V4_ENDPOINT_HPP 
