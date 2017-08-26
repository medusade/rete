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
///   File: Family.hpp
///
/// Author: $author$
///   Date: 8/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_ADDRESS_FAMILY_HPP
#define _XOS_NETWORK_SOCKETS_ADDRESS_FAMILY_HPP

#include "xos/network/address/Family.hpp"
#include "xos/network/Sockets.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace address {

typedef network::address::Family FamilyTImplements;
typedef Base FamilyTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: FamilyT
///////////////////////////////////////////////////////////////////////
template
<typename TWhich = int,
 class TImplements = FamilyTImplements, class TExtends = FamilyTExtends>

class _EXPORT_CLASS FamilyT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhich which_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FamilyT(which_t which): m_which(which) {
    }
    FamilyT(const FamilyT& copy): m_which(copy.m_which) {
    }
    FamilyT(): m_which(AF_UNSPEC) {
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

typedef FamilyTImplements FamilyImplements;
typedef FamilyT<> FamilyExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Family
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Family
: virtual public FamilyImplements, public FamilyExtends {
public:
    typedef FamilyImplements Implements;
    typedef FamilyExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Family(which_t which): Extends(which) {
    }
    Family(const Family& copy): Extends(copy.m_which) {
    }
    Family() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace address
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_ADDRESS_FAMILY_HPP 
