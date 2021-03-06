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
///   File: Sockets.hpp
///
/// Author: $author$
///   Date: 11/28/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_OS_SOCKETS_HPP
#define _XOS_NETWORK_OS_SOCKETS_HPP

#include "xos/network/Sockets.hpp"
#include "xos/network/os/Os.hpp"

#if defined(WINDOWS)
// Windows
#include "xos/network/microsoft/windows/Sockets.hpp"
#elif defined(MACOSX)
// MacOSX
#include "xos/network/apple/osx/Sockets.hpp"
#else // defined(WINDOWS)
// Posix
#include "xos/network/posix/Sockets.hpp"
#endif // defined(WINDOWS)

namespace xos {
namespace network {
namespace os {

typedef os::Sockets Sockets;

} // namespace os 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_OS_SOCKETS_HPP 

        

