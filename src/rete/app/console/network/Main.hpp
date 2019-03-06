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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_APP_CONSOLE_NETWORK_MAIN_HPP
#define _RETE_APP_CONSOLE_NETWORK_MAIN_HPP

#include "rete/app/console/network/MainOpt.hpp"

namespace rete {
namespace app {
namespace console {
namespace network {

typedef MainOpt MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: public MainExtends {
public:
    typedef MainExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main(): m_host("localhost"), m_port(8080) {
    }
    virtual ~Main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnSetHost(const String& to) {}
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            m_host.assign(optarg);
            OnSetHost(m_host);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void OnSetPort(const ushort& to) {}
    virtual int OnPortOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            short port = 0;
            std::stringstream ss(optarg);
            ss >> port;
            if (0 < (port)) {
                m_port = port;
                OnSetPort(m_port);
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* host() const {
        return m_host.has_chars();
    }
    virtual ushort port() const {
        return m_port;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_host;
    ushort m_port;
};

} // namespace network 
} // namespace console 
} // namespace app 
} // namespace rete 

#endif // _RETE_APP_CONSOLE_NETWORK_MAIN_HPP 
