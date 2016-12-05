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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 12/2/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_APP_CONSOLE_HELLO_MAIN_HPP
#define _RETE_APP_CONSOLE_HELLO_MAIN_HPP

#include "rete/console/getopt/Main.hpp"
#include "rete/network/ip/v6/Endpoint.hpp"
#include "rete/network/ip/v4/Endpoint.hpp"
#include "rete/network/ip/tcp/Transport.hpp"
#include "rete/network/ip/udp/Transport.hpp"
#include "rete/network/posix/Socket.hpp"

namespace rete {
namespace app {
namespace console {
namespace hello {

typedef rete::console::getopt::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: public MainExtends {
public:
    typedef MainExtends Extends;
    typedef Main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main()
    : m_run(&Derives::DefaultRun),
      m_endpoint(&Derives::DefaultEndpoint),
      m_transport(&Derives::DefaultTransport),
      m_host("localhost"),
      m_port(8080) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        if ((m_run)) {
            err = (this->*m_run)(argc, argv, env);
        } else {
            err = Usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int DefaultRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        network::Endpoint& ep = this->Endpoint(argc, argv, env);
        network::Transport& tp = this->Transport(argc, argv, env);
        network::Socket& sock = this->Socket(argc, argv, env);
        if ((ep.AttachFirst(m_host.chars(), m_port))) {
            if ((sock.Open(tp))) {
                if ((sock.Listen(ep))) {
                    network::Socket* accepted = 0;
                    if ((accepted = sock.Accept(ep))) {
                        String m_message("HTTP/1.0 200 OK\n\n\nHello\n");
                        accepted->Send(m_message.chars(), m_message.length(), 0);
                        accepted->Close();
                    }
                }
                sock.Close();
            }
            ep.Detach();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Endpoint&
    Endpoint(int argc, char_t **argv, char_t **env) {
        if ((m_endpoint)) {
            return (this->*m_endpoint)(argc, argv, env);
        }
        return DefaultEndpoint(argc, argv, env);
    }
    virtual network::Endpoint&
    Ip4Endpoint(int argc, char_t **argv, char_t **env) {
        return m_ip4;
    }
    virtual network::Endpoint&
    Ip6Endpoint(int argc, char_t **argv, char_t **env) {
        return m_ip6;
    }
    virtual network::Endpoint&
    DefaultEndpoint(int argc, char_t **argv, char_t **env) {
        return Ip4Endpoint(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Transport&
    Transport(int argc, char_t **argv, char_t **env) {
        if ((m_transport)) {
            return (this->*m_transport)(argc, argv, env);
        }
        return DefaultTransport(argc, argv, env);
    }
    virtual network::Transport&
    TcpTransport(int argc, char_t **argv, char_t **env) {
        return m_tcp;
    }
    virtual network::Transport&
    UdpTransport(int argc, char_t **argv, char_t **env) {
        return m_udp;
    }
    virtual network::Transport&
    DefaultTransport(int argc, char_t **argv, char_t **env) {
        return TcpTransport(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Socket&
    Socket(int argc, char_t **argv, char_t **env) {
        return m_sock;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*MRun)(int argc, char_t **argv, char_t **env);
    typedef network::Endpoint& (Derives::*MEndpoint)(int argc, char_t **argv, char_t **env);
    typedef network::Transport& (Derives::*MTransport)(int argc, char_t **argv, char_t **env);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    MRun m_run;
    MEndpoint m_endpoint;
    MTransport m_transport;
    String m_host;
    short m_port;
    network::ip::v4::Endpoint m_ip4;
    network::ip::v6::Endpoint m_ip6;
    network::ip::tcp::Transport m_tcp;
    network::ip::udp::Transport m_udp;
    network::posix::Socket m_sock;
};

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace rete 

#endif // _RETE_APP_CONSOLE_HELLO_MAIN_HPP 
