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
///   File: Transport.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_IP_TCP_TRANSPORT_HPP
#define _RETE_NETWORK_IP_TCP_TRANSPORT_HPP

#include "rete/network/ip/Transport.hpp"

namespace rete {
namespace network {
namespace ip {
namespace tcp {

typedef ip::Transport TransportTImplements;
typedef Base TransportTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: TransportT
///////////////////////////////////////////////////////////////////////
template
<typename TDomain = TransportDomain,
 typename TType = TransportType, typename TProtocol = TransportProtocol,
 class TImplements = TransportTImplements, class TExtends = TransportTExtends>

class _EXPORT_CLASS TransportT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TDomain tDomain;
    typedef TType tType;
    typedef TProtocol tProtocol;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    TransportT() {
    }
    virtual ~TransportT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tType Type() const {
        return SOCK_STREAM;
    }
    virtual tProtocol Protocol() const {
        return IPPROTO_TCP;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef TransportT<> Transport;

} // namespace tcp 
} // namespace ip 
} // namespace network 
} // namespace rete 


#endif // _RETE_NETWORK_IP_TCP_TRANSPORT_HPP 
        

