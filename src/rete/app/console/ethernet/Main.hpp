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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 2/9/2020
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_APP_CONSOLE_ETHERNET_MAIN_HPP
#define _RETE_APP_CONSOLE_ETHERNET_MAIN_HPP

#include "rete/app/console/ethernet/MainOpt.hpp"
#include "rete/network/ethernet/os/Address.hpp"

namespace rete {
namespace app {
namespace console {
namespace ethernet {

///////////////////////////////////////////////////////////////////////
///  Class: Maint
///////////////////////////////////////////////////////////////////////
template <class TExtends = MainOpt, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Maint() {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t**argv, char_t** env) {
        int err = 0;
        network::ethernet::Address::String adapter;
        network::ethernet::os::Address address;

        this->OutL("address.SetToAdapter(\"", adapter.chars(), "\")...", "\n", NULL);
        if ((address.SetToAdapter(adapter))) {
            this->OutL("...address.SetToAdapter(\"", address.adapterName().chars(), "\")", "\n", NULL);
            this->OutL("...address = ", xos::base::X_to_string(&address.actual(), address.actualSize()).chars(), "\n", NULL);
        } else {
            this->OutL("...failed on address.SetToAdapter(\"", adapter.chars(), "\")", "\n", NULL);
        }
        return err;
    } 
}; /// class _EXPORT_CLASS Maint
typedef Maint<> Main;

} /// namespace ethernet
} /// namespace console
} /// namespace app
} /// namespace rete

#endif /// _RETE_APP_CONSOLE_ETHERNET_MAIN_HPP 
