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
///   File: Writer.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_IO_SOCKET_TCP_WRITER_HPP
#define _RETE_IO_SOCKET_TCP_WRITER_HPP

#include "rete/io/socket/Writer.hpp"

namespace rete {
namespace io {
namespace socket {
namespace tcp {

typedef socket::Writer WriterTImplements;
typedef socket::Base WriterTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: WriterT
///////////////////////////////////////////////////////////////////////
template <class TImplements = WriterTImplements, class TExtends = WriterTExtends>

class _EXPORT_CLASS WriterT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Implements::sized_t sized_t;
    typedef typename Implements::what_t what_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WriterT(network::Socket& sock): Extends(sock) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(network::Socket& sock, const void* what, size_t size) {
        size_t count = sock.Send(what, size, 0);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef WriterT<> Writer;

} // namespace tcp
} // namespace socket 
} // namespace io 
} // namespace rete 

#endif // _RETE_IO_SOCKET_TCP_WRITER_HPP 
