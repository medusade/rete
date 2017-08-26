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
///   Date: 8/21/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_ENDPOINT_HPP
#define _XOS_NETWORK_ENDPOINT_HPP

#include "xos/network/Location.hpp"
#include "xos/network/Sockets.hpp"

namespace xos {
namespace network {

typedef ImplementBase EndpointTImplements;
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
    virtual const sockets::Endpoint* const_SocketsEndpoint() const {
        return SocketsEndpoint();
    }
    virtual sockets::Endpoint* SocketsEndpoint() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef EndpointT<> Endpoint;

} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_ENDPOINT_HPP 
