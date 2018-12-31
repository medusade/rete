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
///   File: Writer.hpp
///
/// Author: $author$
///   Date: 12/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_IO_WRITER_HPP
#define _RETE_IO_WRITER_HPP

#include "rete/base/Base.hpp"
#include "patrona/cpp/xos/io/Writer.hpp"

namespace rete {
namespace io {

typedef patrona::io::Writer Writer;

typedef patrona::io::CharWriter CharWriter;
typedef patrona::io::TCharWriter TCharWriter;
typedef patrona::io::WCharWriter WCharWriter;

typedef patrona::io::ByteWriter ByteWriter;
typedef patrona::io::WordWriter WordWriter;

} // namespace io
} // namespace rete 

#endif // _RETE_IO_WRITER_HPP 
        

