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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 7/11/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_APP_CONSOLE_RETE_MAIN_HPP
#define _RETE_APP_CONSOLE_RETE_MAIN_HPP

#include "rete/app/console/rete/MainOpt.hpp"
#include "rete/network/os/Sockets.hpp"

namespace rete {
namespace app {
namespace console {
namespace rete {

typedef MainOpt MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: public MainExtends {
public:
    typedef MainExtends Extends;
    typedef Main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main(): m_run(0) {
    }
    virtual ~Main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*m_run)(int argc, char_t **argv, char_t **env);
    virtual int Run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        if ((m_run)) {
            err = (this->*m_run)(argc, argv, env);
        } else {
            err = this->Usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int TcpClientRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        ::rete::network::Sockets& sockets = this->Sockets();
        if ((sockets.Startup())) {

            sockets.Cleanup();
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int TcpServerRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        ::rete::network::Sockets& sockets = this->Sockets();
        if ((sockets.Startup())) {

            sockets.Cleanup();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ::rete::network::os::Sockets m_sockets;
    virtual ::rete::network::Sockets& Sockets() {
        return m_sockets;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnClientOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::TcpClientRun;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnServerOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::TcpServerRun;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace rete 
} // namespace console 
} // namespace app 
} // namespace rete 

#endif // _RETE_APP_CONSOLE_RETE_MAIN_HPP 
