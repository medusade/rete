///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETS_IP_V4_ENDPOINT_HPP
#define _RETE_NETWORK_SOCKETS_IP_V4_ENDPOINT_HPP

#include "rete/network/sockets/ip/Endpoint.hpp"
#include "rete/network/sockets/ip/v4/Address.hpp"

namespace rete {
namespace network {
namespace sockets {
namespace ip {
namespace v4 {

typedef struct sockaddr_in SockAddr;
///////////////////////////////////////////////////////////////////////
///  Class: EndpointT
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = ip::EndpointTImplements, 
 class TExtends = ip::EndpointT<Address, TImplements> >

class _EXPORT_CLASS EndpointT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    EndpointT(const char* host, AddrIndex index, SockPort port) {
        this->Init();
        if (!(this->Attach(host, index, port))) {
        }
    }
    EndpointT(const char* host, SockPort port) {
        this->Init();
        if (!(this->AttachFirst(host, port))) {
        }
    }
    EndpointT
    (const SockAddrAttached socketAddress, SockLen socketAddressLen, SockPort port) {
        this->Init();
        if (!(this->Attach(socketAddress, socketAddressLen, port))) {
        }
    }
    EndpointT(SockPort port) {
        this->Init();
        if (!(this->Attach(port))) {
        }
    }
    EndpointT(const EndpointT& copy) {
        this->Init();
        this->Attach
        ((SockAddrAttached)&copy.m_socketAddress, 
         copy.m_socketAddressLen, copy.m_socketAddressPort);
    }
    EndpointT() {
        this->Init();
    }
    virtual ~EndpointT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Attach;
    virtual SockAddrAttached Attach
    (const SockAddrAttached socketAddress, SockLen socketAddressLen, SockPort port) {
        if ((socketAddress) && (socketAddressLen == (this->SocketAddressLen()))) {
            if (this->Family() == (socketAddress->sa_family)) {
                SockAddrAttached attached = 0;
                if ((attached = this->Attach(port))) {
                    const SockAddr& sockAddr = (const SockAddr&)(*socketAddress);
                    m_socketAddress.sin_addr.s_addr = sockAddr.sin_addr.s_addr;
                }
                return attached;
            }
        }
        return 0;
    }
    virtual SockAddrAttached Attach(SockPort port) {
        this->InitAddr(m_socketAddress, this->SetSocketAddressLen(this->SocketAddressLen()));
        m_socketAddress.sin_family = this->Family();
        m_socketAddress.sin_addr.s_addr = INADDR_ANY;
        m_socketAddress.sin_port = htons(this->SetSocketAddressPort(port));
        return Extends::Attach((SockAddrAttached)(&m_socketAddress));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockLen SocketAddressLen() const {
        return ((SockLen)sizeof(m_socketAddress));
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::InitAddr;
    virtual void InitAddr(SockAddr& addr, SockLen addrLen) const {
        this->InitAddr((typename Extends::SockAddr&)addr, addrLen);
    }
    virtual void Init() {
        this->InitAddr(m_socketAddress, this->SocketAddressLen());
    }
    virtual void Fini() {
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
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETS_IP_V4_ENDPOINT_HPP 
