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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_IO_SOCKET_BASE_HPP
#define _RETE_IO_SOCKET_BASE_HPP

#include "rete/network/Socket.hpp"

namespace rete {
namespace io {
namespace socket {

typedef rete::ImplementBase ImplementBaseTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: ImplementBaseT
///////////////////////////////////////////////////////////////////////
template <class TImplements = ImplementBaseTImplements>

class _EXPORT_CLASS ImplementBaseT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Socket& sock() const = 0;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ImplementBaseT<> ImplementBase;

typedef ImplementBase BaseTImplements;
typedef rete::Base BaseTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: BaseT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = BaseTImplements, class TExtends = BaseTExtends>

class _EXPORT_CLASS BaseT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BaseT(network::Socket& sock): m_sock(sock) {
    }
    virtual ~BaseT() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Socket& sock() const {
        return (network::Socket&)m_sock;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    network::Socket& m_sock;
};
typedef BaseT<> Base;

} // namespace socket
} // namespace io 
} // namespace rete 

#endif // _RETE_IO_SOCKET_BASE_HPP 
