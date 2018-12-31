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
///   File: Address.hpp
///
/// Author: $author$
///   Date: 7/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETS_ADDRESS_HPP
#define _RETE_NETWORK_SOCKETS_ADDRESS_HPP

#include "rete/network/Address.hpp"

namespace rete {
namespace network {
namespace sockets {

typedef network::AddressFamily AddressFamily;
typedef network::AddressVersion AddressVersion;
typedef network::Address AddressTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template
<typename TFamily = AddressFamily,
 typename TVersion = AddressVersion,
 class TImplements = AddressTImplements>

class _EXPORT_CLASS AddressT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TFamily tFamily;
    typedef TVersion tVersion;
    static const tFamily FamilyUnspec = AF_UNSPEC;
    static const tVersion VersionUnspec = 0;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tFamily Family() const {
        return FamilyUnspec;
    }
    virtual tVersion Version() const {
        return VersionUnspec;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AddressT<> AddressImplement;

///////////////////////////////////////////////////////////////////////
///  Class: Address
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Address: virtual public AddressImplement {
public:
    typedef AddressImplement Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Address* SocketsAddress() const {
        return (Address*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef Base AddressExtend;

} // namespace sockets
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETS_ADDRESS_HPP 
