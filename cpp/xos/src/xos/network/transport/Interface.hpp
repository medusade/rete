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
///   File: Interface.hpp
///
/// Author: $author$
///   Date: 8/23/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_TRANSPORT_INTERFACE_HPP
#define _XOS_NETWORK_TRANSPORT_INTERFACE_HPP

#include "xos/network/transport/Domain.hpp"
#include "xos/network/transport/Type.hpp"
#include "xos/network/transport/Protocol.hpp"
#include "xos/network/Sockets.hpp"

namespace xos {
namespace network {
namespace transport {

typedef ImplementBase InterfaceTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template
<class TDomain = Domain,
 class TType = Type,
 class TProtocol = Protocol,
 class TImplements = InterfaceTImplements>

class _EXPORT_CLASS InterfaceT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TDomain domain_t;
    typedef TType type_t;
    typedef TProtocol protocol_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const sockets::transport::Interface* const_SocketsInterface() const {
        return SocketsInterface();
    }
    virtual sockets::transport::Interface* SocketsInterface() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef InterfaceT<> Interface;

} // namespace transport 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_TRANSPORT_INTERFACE_HPP 
