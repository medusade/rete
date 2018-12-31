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
///   File: Socket.cpp
///
/// Author: $author$
///   Date: 12/3/2016
///////////////////////////////////////////////////////////////////////
#include "rete/network/microsoft/windows/Socket.hpp"

#if !defined(WINDOWS)
int closesocket(
  _In_ SOCKET s
) {
    return close(s);
}
int WSAGetLastError(void) {
    return errno;
}
#endif // !defined(WINDOWS)

namespace rete {
namespace network {
namespace microsoft {
namespace windows {

///////////////////////////////////////////////////////////////////////
///  Class: SocketT
///////////////////////////////////////////////////////////////////////

} // namespace windows 
} // namespace microsoft 
} // namespace network 
} // namespace rete 
