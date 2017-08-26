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
///   File: Protocol.hpp
///
/// Author: $author$
///   Date: 8/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_TRANPORT_PROTOCOL_HPP
#define _XOS_NETWORK_SOCKETS_TRANPORT_PROTOCOL_HPP

#include "xos/network/transport/Protocol.hpp"
#include "xos/network/Sockets.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace transport {

typedef network::transport::Protocol ProtocolTImplements;
typedef Base ProtocolTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ProtocolT
///////////////////////////////////////////////////////////////////////
template
<typename TWhich = int,
 class TImplements = ProtocolTImplements, class TExtends = ProtocolTExtends>

class _EXPORT_CLASS ProtocolT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhich which_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ProtocolT(which_t which): m_which(which) {
    }
    ProtocolT(const ProtocolT& copy): m_which(copy.m_which) {
    }
    ProtocolT(): m_which(0) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual which_t Which() const {
        return m_which;
    }
    virtual operator which_t() const {
        return Which();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    which_t m_which;
};

typedef ProtocolTImplements ProtocolImplements;
typedef ProtocolT<> ProtocolExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Protocol
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Protocol
: virtual public ProtocolImplements, public ProtocolExtends {
public:
    typedef ProtocolImplements Implements;
    typedef ProtocolExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Protocol(which_t which): Extends(which) {
    }
    Protocol(const Protocol& copy): Extends(copy.m_which) {
    }
    Protocol() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace transport
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_TRANPORT_PROTOCOL_HPP 
