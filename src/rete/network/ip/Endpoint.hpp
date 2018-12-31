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
#ifndef _RETE_NETWORK_IP_ENDPOINT_HPP
#define _RETE_NETWORK_IP_ENDPOINT_HPP

#include "rete/network/Endpoint.hpp"
#include "rete/network/ip/Address.hpp"

namespace rete {
namespace network {
namespace ip {

typedef network::Endpoint EndpointTImplements;
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
protected:
    SockPort m_socketAddressPort;
    SockLen m_socketAddressLen;
};

} // namespace ip 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_IP_ENDPOINT_HPP 
