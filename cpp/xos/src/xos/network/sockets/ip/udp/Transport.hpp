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
#ifndef _XOS_NETWORK_SOCKETS_IP_UDP_TRANSPORT_HPP
#define _XOS_NETWORK_SOCKETS_IP_UDP_TRANSPORT_HPP

#include "xos/network/sockets/ip/Transport.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace ip {
namespace udp {

typedef ip::Transport TransportTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: TransportT
///////////////////////////////////////////////////////////////////////
template <class TImplements = TransportTImplements>

class _EXPORT_CLASS TransportT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef typename Implements::domain_t domain_t;
    typedef typename Implements::type_t type_t;
    typedef typename Implements::protocol_t protocol_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual type_t Type() const {
        type_t type(SOCK_DGRAM);
        return type;
    }
    virtual protocol_t Protocol() const {
        protocol_t protocol(IPPROTO_UDP);
        return protocol;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef TransportT<> Transport;

} // namespace udp
} // namespace ip 
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_IP_UDP_TRANSPORT_HPP 
