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
///   Date: 8/23/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_TRANSPORT_HPP
#define _XOS_NETWORK_SOCKETS_TRANSPORT_HPP

#include "xos/network/sockets/transport/Interface.hpp"
#include "xos/network/Transport.hpp"

namespace xos {
namespace network {
namespace sockets {

///////////////////////////////////////////////////////////////////////
///  Class: TransportTImplements
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS TransportTImplements
: virtual public network::Transport, virtual public transport::Interface {
public:
};

///////////////////////////////////////////////////////////////////////
///  Class: TransportT
///////////////////////////////////////////////////////////////////////
template <class TImplements = TransportTImplements>

class _EXPORT_CLASS TransportT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef transport::Domain domain_t;
    typedef transport::Type type_t;
    typedef transport::Protocol protocol_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef TransportT<> TransportImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Transport
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Transport: virtual public TransportImplements {
public:
    typedef TransportImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sockets::Transport* SocketsTransport() const {
        return (sockets::Transport*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_TRANSPORT_HPP 
