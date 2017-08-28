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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 8/26/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_APP_CONSOLE_MT_HELLO_MAINOPT_HPP
#define _RETE_APP_CONSOLE_MT_HELLO_MAINOPT_HPP

#include "crono/app/console/mt/hello/MainOpt.hpp"
#include "rete/console/mt/getopt/MainOpt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define RETE_CONSOLE_HELLO_MAIN_OPTIONS_CHARS \
    HELLO_MAIN_MESSAGE_OPTVAL_S \
    RETE_CONSOLE_MAIN_OPTIONS_CHARS

#define RETE_CONSOLE_HELLO_MAIN_OPTIONS_OPTIONS \
    HELLO_MAIN_MESSAGE_OPTION \
    RETE_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace rete {
namespace app {
namespace console {
namespace mt {
namespace hello {

typedef nadir::app::console::hello::MainOptT
<rete::console::mt::getopt::MainOpt> MainOptImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOptT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainOptImplements>

class _EXPORT_CLASS MainOptT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = RETE_CONSOLE_HELLO_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            RETE_CONSOLE_HELLO_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainOptT<> MainOpt;

} // namespace hello
} // namespace mt 
} // namespace console 
} // namespace app 
} // namespace rete 

#endif // _RETE_APP_CONSOLE_MT_HELLO_MAINOPT_HPP 
