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
///   Date: 8/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_ADDRESS_INTERFACE_HPP
#define _XOS_NETWORK_SOCKETS_ADDRESS_INTERFACE_HPP

#include "xos/network/sockets/address/Family.hpp"
#include "xos/network/sockets/address/Version.hpp"
#include "xos/network/address/Interface.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace address {

typedef network::address::Interface InterfaceTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template
<class TFamily = Family,
 class TVersion = Version,
 class TImplements = InterfaceTImplements>

class _EXPORT_CLASS InterfaceT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TFamily family_t;
    typedef TVersion version_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual family_t Family() const {
        return FamilyUnspec();
    }
    virtual version_t Version() const {
        return VersionUnspec();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static family_t FamilyUnspec() {
        family_t family(AF_UNSPEC);
        return family;
    }
    static version_t VersionUnspec() {
        version_t version(0);
        return version;
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
    virtual Interface* socketsInterface() const {
        return (Interface*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace address
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_ADDRESS_INTERFACE_HPP 
