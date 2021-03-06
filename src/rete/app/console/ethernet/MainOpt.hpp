///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   Date: 2/9/2020
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_APP_CONSOLE_ETHERNET_MAINOPT_HPP
#define _RETE_APP_CONSOLE_ETHERNET_MAINOPT_HPP

#include "rete/console/getopt/Main.hpp"

namespace rete {
namespace app {
namespace console {
namespace ethernet {

///////////////////////////////////////////////////////////////////////
///  Class: MainOptt
///////////////////////////////////////////////////////////////////////
template <class TExtends = rete::console::getopt::Main, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS MainOptt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef MainOptt Derives;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainOptt(const MainOptt &copy) {
    }
    MainOptt() {
    }
    virtual ~MainOptt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS MainOptt
typedef MainOptt<> MainOpt;

} /// namespace ethernet
} /// namespace console
} /// namespace app
} /// namespace rete

#endif /// _RETE_APP_CONSOLE_ETHERNET_MAINOPT_HPP 
