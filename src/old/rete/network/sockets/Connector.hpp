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
///   Date: 3/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETS_CONNECTOR_HPP
#define _RETE_NETWORK_SOCKETS_CONNECTOR_HPP

#include "rete/network/sockets/Connection.hpp"
#include "rete/network/Connector.hpp"

namespace rete {
namespace network {
namespace sockets {

typedef network::Connector ConnectorTImplements;
typedef Base ConnectorTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ConnectorT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ConnectorTImplements, class TExtends = ConnectorTExtends>
class _EXPORT_CLASS ConnectorT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ConnectorT() {
    }
    virtual ~ConnectorT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect
    (network::Connection& connection, const network::Endpoint& endpoint) {
        bool success = false;
        const Endpoint* socketsEndpoint = 0;

        if ((socketsEndpoint = endpoint.const_SocketsEndpoint())) {
            const Endpoint& endpoint = *socketsEndpoint;
            Connection* socketsConnection = 0;

            if ((socketsConnection = connection.SocketsConnection())) {
                Connection& connection = *socketsConnection;
                
                /*if ((connection.Socket().Connect(endpoint))) {
                    success = true;
                }*/
            }
        }
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ConnectorT<> ConnectorExtend;

///////////////////////////////////////////////////////////////////////
///  Class: Connector
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Connector: public ConnectorExtend {
public:
    typedef ConnectorExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Connector() {
    }
    virtual ~Connector() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace sockets 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETS_CONNECTOR_HPP 
