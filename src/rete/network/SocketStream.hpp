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
///   File: SocketStream.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NETWORK_SOCKETSTREAM_HPP
#define _RETE_NETWORK_SOCKETSTREAM_HPP

#include "rete/network/SocketReader.hpp"
#include "rete/network/SocketWriter.hpp"
#include "rete/io/Stream.hpp"

namespace rete {
namespace network {

typedef io::CharStream SocketStreamTImplements;
typedef Base SocketStreamTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: SocketStreamT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = SocketStreamTImplements, class TExtends = SocketStreamTExtends>

class _EXPORT_CLASS SocketStreamT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Implements::what_t what_t;
    typedef typename Implements::sized_t sized_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    SocketStreamT(Socket& sock): m_sock(sock) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(what_t* what, size_t size) {
        ssize_t count = m_sock.Recv(what, size, 0);
        return count;
    }
    virtual ssize_t Write(const what_t* what, size_t size) {
        ssize_t count = m_sock.Send(what, size, 0);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Socket& m_sock;
};
typedef SocketStreamT<> SocketStream;

} // namespace network 
} // namespace rete 

#endif // _RETE_NETWORK_SOCKETSTREAM_HPP 
