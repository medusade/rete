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
///   File: Domain.hpp
///
/// Author: $author$
///   Date: 8/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_TRANPORT_DOMAIN_HPP
#define _XOS_NETWORK_SOCKETS_TRANPORT_DOMAIN_HPP

#include "xos/network/transport/Domain.hpp"
#include "xos/network/Sockets.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace transport {

typedef network::transport::Domain DomainTImplements;
typedef Base DomainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: DomainT
///////////////////////////////////////////////////////////////////////
template
<typename TWhich = int,
 class TImplements = DomainTImplements, class TExtends = DomainTExtends>

class _EXPORT_CLASS DomainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhich which_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    DomainT(which_t which): m_which(which) {
    }
    DomainT(const DomainT& copy): m_which(copy.m_which) {
    }
    DomainT(): m_which(PF_UNSPEC) {
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

typedef DomainTImplements DomainImplements;
typedef DomainT<> DomainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Domain
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Domain
: virtual public DomainImplements, public DomainExtends {
public:
    typedef DomainImplements Implements;
    typedef DomainExtends Extends;
    typedef Extends::which_t which_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Domain(which_t which): Extends(which) {
    }
    Domain(const Domain& copy): Extends(copy.m_which) {
    }
    Domain() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace transport
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_TRANPORT_DOMAIN_HPP 
