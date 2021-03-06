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
///   File: Address.hpp
///
/// Author: $author$
///   Date: 3/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETS_IP_V4_ADDRESS_HPP
#define _RETE_NETWORK_SOCKETS_IP_V4_ADDRESS_HPP

#include "rete/network/sockets/ip/Address.hpp"

namespace rete {
namespace network {
namespace sockets {
namespace ip {
namespace v4 {

///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ip::Address::Implements, class TExtends = ip::Address>
class _EXPORT_CLASS AddressT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Implements::tFamily tFamily;
    typedef typename Implements::tVersion tVersion;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AddressT() {
    }
    virtual ~AddressT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tFamily Family() const {
        return AF_INET;
    }
    virtual tVersion Version() const {
        return 4;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace v4 
} // namespace ip 
} // namespace sockets 
} // namespace network 
} // namespace rete 


#endif // _RETE_NETWORK_SOCKETS_IP_V4_ADDRESS_HPP 

        

