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
#ifndef _RETE_NETWORK_SOCKETS_IP_ENDPOINT_HPP
#define _RETE_NETWORK_SOCKETS_IP_ENDPOINT_HPP

#include "rete/network/sockets/Endpoint.hpp"

namespace rete {
namespace network {
namespace sockets {
namespace ip {

typedef sockets::Endpoint EndpointTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: EndpointT
///////////////////////////////////////////////////////////////////////
template 
<class TAddress,
 class TImplements = EndpointTImplements,
 class TExtends = patrona::AttachedT
 <SockAddrAttached, int, 0, TImplements, TAddress> >

class _EXPORT_CLASS EndpointT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef sockets::SockAddr SockAddr;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    EndpointT(const EndpointT& copy)
    : m_socketAddressPort(0), m_socketAddressLen(0) {
    }
    EndpointT(): m_socketAddressPort(0), m_socketAddressLen(0) {
    }
    virtual ~EndpointT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockPort SetSocketAddressPort(SockPort to) {
        m_socketAddressPort = to;
        return m_socketAddressPort;
    }
    virtual SockPort SocketAddressPort() const {
        return m_socketAddressPort;
    }
    virtual SockLen SetSocketAddressLen(SockLen to) {
        m_socketAddressLen = to;
        return m_socketAddressLen;
    }
    virtual SockLen SocketAddressLen() const {
        return m_socketAddressLen;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void InitAddr(SockAddr& addr, SockLen addrLen) const {
        ::memset(&addr, 0, addrLen);
    }
    virtual void Init() {
    }
    virtual void Fini() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    SockPort m_socketAddressPort;
    SockLen m_socketAddressLen;
};

} // namespace ip 
} // namespace sockets 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETS_IP_ENDPOINT_HPP 
