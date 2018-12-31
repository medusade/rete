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
///   File: socket_observer.hpp
///
/// Author: $author$
///   Date: 5/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NADIR_NETWORK_SOCKET_OBSERVER_HPP
#define _RETE_NADIR_NETWORK_SOCKET_OBSERVER_HPP

#include "rete/nadir/network/socket.hpp"

namespace rete {
namespace network {

typedef implement_base socket_observert_implements;
///////////////////////////////////////////////////////////////////////
///  Class: socket_observert
///////////////////////////////////////////////////////////////////////
template <class TImplements = socket_observert_implements>

class _EXPORT_CLASS socket_observert: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_send(const void* buf, size_t len) {
    }
    virtual void on_recv(const void* buf, size_t len) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef socket_observert<> socket_observer;

} // namespace network 
} // namespace rete 

#endif // _RETE_NADIR_NETWORK_SOCKET_OBSERVER_HPP 
