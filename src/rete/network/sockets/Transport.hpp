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
///   File: Transport.hpp
///
/// Author: $author$
///   Date: 7/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETS_TRANSPORT_HPP
#define _RETE_NETWORK_SOCKETS_TRANSPORT_HPP

#include "rete/network/Sockets.hpp"

namespace rete {
namespace network {
namespace sockets {

typedef int TransportDomain;
typedef int TransportType;
typedef int TransportProtocol;
typedef ImplementBase TransportTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: TransportT
///////////////////////////////////////////////////////////////////////
template
<typename TDomain = TransportDomain,
 typename TType = TransportType,
 typename TProtocol = TransportProtocol,
 class TImplements = TransportTImplements>

class _EXPORT_CLASS TransportT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TDomain tDomain;
    typedef TType tType;
    typedef TProtocol tProtocol;
    static const tDomain DomainUnspec = PF_UNSPEC;
    static const tType TypeUnspec = SOCK_RAW;
    static const tProtocol ProtocolUnspec = 0;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tDomain Domain() const {
        return DomainUnspec;
    }
    virtual tType Type() const {
        return TypeUnspec;
    }
    virtual tProtocol Protocol() const {
        return ProtocolUnspec;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef TransportT<> Transport;

} // namespace sockets
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETS_TRANSPORT_HPP 
