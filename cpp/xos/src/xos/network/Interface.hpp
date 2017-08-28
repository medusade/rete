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
#ifndef _XOS_NETWORK_INTERFACE_HPP
#define _XOS_NETWORK_INTERFACE_HPP

#include "xos/network/Endpoint.hpp"
#include "xos/network/Transport.hpp"
#include "xos/network/Sockets.hpp"
#include "xos/logger/Interface.hpp"

namespace xos {
namespace network {

class _EXPORT_CLASS Interface;
typedef ImplementBase InterfaceTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template <class TImplements = InterfaceTImplements>

class _EXPORT_CLASS InterfaceT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open(const Transport& tp) {
        XOS_LOG_ERROR("...unimplemented return false...");
        return false;
    }
    virtual bool Close() {
        XOS_LOG_ERROR("...unimplemented return false...");
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const Endpoint& ep) {
        XOS_LOG_ERROR("...unimplemented return false...");
        return false;
    }
    virtual bool Listen(const Endpoint& ep) {
        XOS_LOG_ERROR("...unimplemented return false...");
        return false;
    }
    virtual bool Accept(Interface& in, const Endpoint& ep) {
        XOS_LOG_ERROR("...unimplemented return false...");
        return false;
    }
    virtual bool Shutdown() {
        XOS_LOG_ERROR("...unimplemented return false...");
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendTo(const void* buf, size_t len, const Endpoint& ep) {
        XOS_LOG_ERROR("...unimplemented return -1...");
        return -1;
    }
    virtual ssize_t RecvFrom(void* buf, size_t len, const Endpoint& ep) {
        XOS_LOG_ERROR("...unimplemented return -1...");
        return -1;
    }
    virtual ssize_t Send(const void* buf, size_t len) {
        XOS_LOG_ERROR("...unimplemented return -1...");
        return -1;
    }
    virtual ssize_t Recv(void* buf, size_t len) {
        XOS_LOG_ERROR("...unimplemented return -1...");
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const sockets::Interface* const_SocketsInterface() const {
        return SocketsInterface();
    }
    virtual sockets::Interface* SocketsInterface() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef InterfaceT<> InterfaceImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Interface: virtual public InterfaceImplements {
public:
    typedef InterfaceImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef Interface InterfaceBaseTImplements;
typedef Base InterfaceBaseTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceBaseT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = InterfaceBaseTImplements, class TExtends = InterfaceBaseTExtends>

class _EXPORT_CLASS InterfaceBaseT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: InterfaceBaseT
    ///////////////////////////////////////////////////////////////////////
    InterfaceBaseT() {
    }
    virtual ~InterfaceBaseT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef InterfaceBaseT<> InterfaceBase;

} // namespace network
} // namespace xos 

#endif // _XOS_NETWORK_INTERFACE_HPP 
