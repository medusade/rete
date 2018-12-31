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
///   Date: 3/26/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_CONNECTION_HPP
#define _RETE_NETWORK_CONNECTION_HPP

#include "rete/network/Transport.hpp"
#include "rete/network/Endpoint.hpp"
#include "rete/base/Opened.hpp"

namespace rete {
namespace network {

typedef Opener ConnectionTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: ConnectionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ConnectionTImplements>
class _EXPORT_CLASS ConnectionT: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open(const Transport& transport) {
        return false;
    }
    virtual bool Close() {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const Endpoint& endpoint) {
        return false;
    }
    virtual bool Disconnect() {
        return false;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(const void* message, size_t length) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t Recv(void* message, size_t size) {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const sockets::Connection* const_SocketsConnection() const {
        return this->SocketsConnection();
    }
    virtual sockets::Connection* SocketsConnection() const {
        return 0;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ConnectionT<> Connection;

} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_CONNECTION_HPP 
