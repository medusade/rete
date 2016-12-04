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
///   Date: 12/2/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_IP_V6_ENDPOINT_HPP
#define _RETE_NETWORK_IP_V6_ENDPOINT_HPP

#include "rete/network/ip/Endpoint.hpp"
#include "rete/network/ip/v6/Address.hpp"

namespace rete {
namespace network {
namespace ip {
namespace v6 {

typedef struct sockaddr_in6 SockAddr;

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
    EndpointT(const char* host, AddrIndex index, SockPort port) {
        memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->Attach(host, index, port))) {
        }
    }
    EndpointT(const char* host, SockPort port) {
        memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->AttachFirst(host, port))) {
        }
    }
    EndpointT
    (const SockAddrAttached socketAddress, SockLen socketAddressLen, SockPort port) {
        memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->Attach(socketAddress, socketAddressLen, port))) {
        }
    }
    EndpointT(SockPort port) {
        memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        if (!(this->Attach(port))) {
        }
    }
    EndpointT(const EndpointT& copy) {
        memset(&m_socketAddress, 0, sizeof(m_socketAddress));
        this->Attach(copy.m_socketAddress, copy.m_socketAddressLen, copy.m_socketAddressPort);
    }
    EndpointT() {
        memset(&m_socketAddress, 0, sizeof(m_socketAddress));
    }
    virtual ~EndpointT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Attach;
    virtual SockAddrAttached Attach
    (const SockAddrAttached socketAddress, SockLen socketAddressLen, SockPort port) {
        if ((socketAddress) && (socketAddressLen == (this->SocketAddressLen()))) {
            if (this->Family() == (socketAddress->sa_family)) {
                SockAddrAttached attached = 0;
                if ((attached = this->Attach(port))) {
                    const SockAddr& sockAddr = (const SockAddr&)(*socketAddress);
                    m_socketAddress.sin6_addr = sockAddr.sin6_addr;
                }
                return attached;
            }
        }
        return 0;
    }
    virtual SockAddrAttached Attach(SockPort port) {
        memset(&m_socketAddress, 0, this->m_socketAddressLen = (sizeof(m_socketAddress)));
        m_socketAddress.sin6_family = this->Family();
        m_socketAddress.sin6_addr = in6addr_any;
        m_socketAddress.sin6_port = htons(this->m_socketAddressPort = port);
        return Extends::Attach((SockAddrAttached)(&m_socketAddress));
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

} // namespace v6 
} // namespace ip 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_IP_V6_ENDPOINT_HPP 
