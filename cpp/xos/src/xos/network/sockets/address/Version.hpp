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
///   File: Version.hpp
///
/// Author: $author$
///   Date: 8/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_ADDRESS_VERSION_HPP
#define _XOS_NETWORK_SOCKETS_ADDRESS_VERSION_HPP

#include "xos/network/address/Version.hpp"
#include "xos/network/Sockets.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace address {

typedef network::address::Version VersionTImplements;
typedef Base VersionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: VersionT
///////////////////////////////////////////////////////////////////////
template
<typename TWhich = int,
 class TImplements = VersionTImplements, class TExtends = VersionTExtends>

class _EXPORT_CLASS VersionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhich which_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    VersionT(which_t which): m_which(which) {
    }
    VersionT(const VersionT& copy): m_which(copy.m_which) {
    }
    VersionT(): m_which(0) {
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

typedef VersionTImplements VersionImplements;
typedef VersionT<> VersionExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Version
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Version
: virtual public VersionImplements, public VersionExtends {
public:
    typedef VersionImplements Implements;
    typedef VersionExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Version(which_t which): Extends(which) {
    }
    Version(const Version& copy): Extends(copy.m_which) {
    }
    Version() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace address 
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_ADDRESS_VERSION_HPP 

        

