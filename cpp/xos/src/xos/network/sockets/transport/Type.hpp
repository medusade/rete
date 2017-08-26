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
///   File: Type.hpp
///
/// Author: $author$
///   Date: 8/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_TRANPORT_TYPE_HPP
#define _XOS_NETWORK_SOCKETS_TRANPORT_TYPE_HPP

#include "xos/network/transport/Type.hpp"
#include "xos/network/Sockets.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace transport {

typedef network::transport::Type TypeTImplements;
typedef Base TypeTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: TypeT
///////////////////////////////////////////////////////////////////////
template
<typename TWhich = int,
 class TImplements = TypeTImplements, class TExtends = TypeTExtends>

class _EXPORT_CLASS TypeT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhich which_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    TypeT(which_t which): m_which(which) {
    }
    TypeT(const TypeT& copy): m_which(copy.m_which) {
    }
    TypeT(): m_which(SOCK_RAW) {
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

typedef TypeTImplements TypeImplements;
typedef TypeT<> TypeExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Type
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Type
: virtual public TypeImplements, public TypeExtends {
public:
    typedef TypeImplements Implements;
    typedef TypeExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Type(which_t which): Extends(which) {
    }
    Type(const Type& copy): Extends(copy.m_which) {
    }
    Type() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace transport
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_TRANPORT_TYPE_HPP 
