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
///   File: Connector.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_CONNECTOR_HPP
#define _RETE_NETWORK_CONNECTOR_HPP

#include "rete/network/Endpoint.hpp"
#include "rete/network/Connection.hpp"

namespace rete {
namespace network {

///////////////////////////////////////////////////////////////////////
///  Class: ConnectorT
///////////////////////////////////////////////////////////////////////
template
<class TImplement = ImplementBase,
 class TEndpoint = Endpoint,
 class TConnection = Connection, 
 class TImplements = TImplement>
class _EXPORT_CLASS ConnectorT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TEndpoint Endpoint;
    typedef TConnection Connection;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(Connection& connection, const Endpoint& endpoint) {
        bool success = false;
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ConnectorT<> Connector;

} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_CONNECTOR_HPP 
