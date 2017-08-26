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
///   File: Sockets.hpp
///
/// Author: $author$
///   Date: 8/21/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_HPP
#define _XOS_NETWORK_SOCKETS_HPP

#include "xos/base/Base.hpp"

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>

namespace xos {
namespace network {
namespace sockets {

namespace address {

class _EXPORT_CLASS Family;
class _EXPORT_CLASS Version;
class _EXPORT_CLASS Interface;

} // namespace address

namespace transport {

class _EXPORT_CLASS Domain;
class _EXPORT_CLASS Type;
class _EXPORT_CLASS Protocol;
class _EXPORT_CLASS Interface;

} // namespace transport

class _EXPORT_CLASS Endpoint;
class _EXPORT_CLASS Location;
class _EXPORT_CLASS Interface;
class _EXPORT_CLASS Platform;

} // namespace sockets

typedef ImplementBase SocketsTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: SocketsT
///////////////////////////////////////////////////////////////////////
template <class TImplements = SocketsTImplements>
class _EXPORT_CLASS SocketsT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Startup() { return true; }
    virtual bool Cleanup() { return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef SocketsT<> Sockets;

} // namespace network
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_HPP 
