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
///   File: Sockets.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_MICROSOFT_WINDOWS_SOCKETS_HPP
#define _RETE_NETWORK_MICROSOFT_WINDOWS_SOCKETS_HPP

#include "rete/network/Sockets.hpp"
#include "crono/io/Logger.hpp"

#if defined(WINSOCK_2)
#define WINSOCK_VERSION_MAJOR 2
#define WINSOCK_VERSION_MINOR 2
#else // defined(WINSOCK_2)
#define WINSOCK_VERSION_MAJOR 1
#define WINSOCK_VERSION_MINOR 1
#endif // defined(WINSOCK_2)

#if !defined(WINDOWS)
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum { SOCKET_ERROR = -1 };
enum {
    WSADESCRIPTION_LEN = 128,
    WSASYS_STATUS_LEN  = WSADESCRIPTION_LEN
};
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef struct WSAData {
  WORD           wVersion;
  WORD           wHighVersion;
  char           szDescription[WSADESCRIPTION_LEN+1];
  char           szSystemStatus[WSASYS_STATUS_LEN+1];
  unsigned short iMaxSockets;
  unsigned short iMaxUdpDg;
  char FAR       *lpVendorInfo;
} WSADATA, *LPWSADATA;
extern "C" {
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int WSAStartup(
  _In_  WORD      wVersionRequested,
  _Out_ LPWSADATA lpWSAData
);
int WSACleanup(void);
int WSAGetLastError(void);
}
#endif // !defined(WINDOWS)

namespace rete {
namespace network {
namespace microsoft {
namespace windows {

typedef network::Sockets SocketsTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: SocketsT
///////////////////////////////////////////////////////////////////////
template <class TImplements = SocketsTImplements>
class _EXPORT_CLASS SocketsT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Startup() {
        BYTE wsaVersionMajor = WINSOCK_VERSION_MAJOR, 
             wsaVersionMinor = WINSOCK_VERSION_MINOR;
        WORD wsaVersion = MAKEWORD(wsaVersionMajor, wsaVersionMinor);
        WSADATA wsaData;
        memset(&wsaData, 0, sizeof(WSADATA));
        CRONO_LOG_DEBUG("WSAStartup(wsaVersion = " << wsaVersion << ",...)...");
        if (SOCKET_ERROR != (WSAStartup(wsaVersion, &wsaData))) {
            CRONO_LOG_DEBUG("...WSAStartup(wsaVersion = " << wsaVersion << ",...)");
            return true;
        } else {
            int error = WSAGetLastError();
            CRONO_LOG_ERROR("...failed error = " << error << " on WSAStartup(wsaVersion = " << wsaVersion << ",...)");
        }
        return false;
    }
    virtual bool Cleanup() {
        CRONO_LOG_DEBUG("WSACleanup()...");
        if (SOCKET_ERROR != (WSACleanup())) {
            CRONO_LOG_DEBUG("...WSACleanup()");
        } else {
            int error = WSAGetLastError();
            CRONO_LOG_ERROR("...failed error = " << error << " on WSACleanup()");
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef SocketsT<> Sockets;

} // namespace windows 
} // namespace microsoft 
} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_MICROSOFT_WINDOWS_SOCKETS_HPP 
        

