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
///   File: Connection.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETS_CONNECTION_HPP
#define _RETE_NETWORK_SOCKETS_CONNECTION_HPP

#include "rete/network/Connection.hpp"
#include "rete/network/os/Socket.hpp"

namespace rete {
namespace network {
namespace sockets {

typedef network::Connection ConnectionImplements;
typedef Base ConnectionExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ConnectionT
///////////////////////////////////////////////////////////////////////
template 
<class TSocket = os::Socket, 
 class TImplements = network::Connection, class TExtends = Base>
class _EXPORT_CLASS ConnectionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ConnectionT(const ConnectionT& copy): m_socket(copy.m_socket) {
    }
    ConnectionT() {
    }
    virtual ~ConnectionT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(const void* message, size_t length) {
        ssize_t count = 0;
        count = m_socket.Send(message, length, this->SendFlags());
        return count;
    }
    virtual ssize_t Recv(void* message, size_t size) {
        ssize_t count = 0;
        count = m_socket.Recv(message, size, this->RecvFlags());
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual typename TSocket::SendFlags SendFlags() const {
        return 0;
    }
    virtual typename TSocket::RecvFlags RecvFlags() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TSocket& Socket() const {
        return (TSocket&)m_socket;
    }
    virtual operator TSocket& () const {
        return (TSocket&)m_socket;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TSocket m_socket;
};
typedef ConnectionT<> ConnectionExtend;

///////////////////////////////////////////////////////////////////////
///  Class: Connection
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Connection: public ConnectionExtend {
public:
    typedef ConnectionExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Connection(const Connection& copy): Extends(copy) {
    }
    Connection() {
    }
    virtual ~Connection() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Connection* SocketsConnection() const {
        return (Connection*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace sockets 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETS_CONNECTION_HPP 
