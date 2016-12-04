///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: Socket.hpp
///
/// Author: $author$
///   Date: 12/3/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_MICROSOFT_WINDOWS_SOCKET_HPP
#define _RETE_NETWORK_MICROSOFT_WINDOWS_SOCKET_HPP
#include "rete/network/Socket.hpp"

namespace rete {
namespace network {
namespace microsoft {
namespace windows {


///////////////////////////////////////////////////////////////////////
///  Class: SocketT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = SocketTImplements, class TExtends = SocketTExtends>
class _EXPORT_CLASS SocketT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    SocketT() {
    }
    virtual ~SocketT() {
    }
};


} // namespace windows 
} // namespace microsoft 
} // namespace network 
} // namespace rete 


#endif // _RETE_NETWORK_MICROSOFT_WINDOWS_SOCKET_HPP 
        

