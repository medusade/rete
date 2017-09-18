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
///   File: InterfaceReader.hpp
///
/// Author: $author$
///   Date: 9/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_INTERFACEREADER_HPP
#define _XOS_NETWORK_INTERFACEREADER_HPP

#include "xos/network/Interface.hpp"
#include "xos/io/Reader.hpp"

namespace xos {
namespace network {

typedef io::Reader InterfaceReaderTImplements;
typedef Base InterfaceReaderTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceReaderT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = InterfaceReaderTImplements, class TExtends = InterfaceReaderTExtends>

class _EXPORT_CLASS InterfaceReaderT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef network::Interface interface_t;
    typedef typename Implements::sized_t sized_t;
    typedef typename Implements::what_t what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    InterfaceReaderT(interface_t& in): m_in(in) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(what_t* what, size_t size) {
        ssize_t count = m_in.Recv(what, size);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    interface_t& m_in;
};
typedef InterfaceReaderT<> InterfaceReader;
typedef InterfaceReaderT<io::CharReader> InterfaceCharReader;

} // namespace network
} // namespace xos 

#endif // _XOS_NETWORK_INTERFACEREADER_HPP 
