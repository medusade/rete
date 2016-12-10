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

#include "rete/app/console/hello/MainOpt.hpp"
#include "rete/console/getopt/Main.hpp"
#include "rete/network/ip/v6/Endpoint.hpp"
#include "rete/network/ip/v4/Endpoint.hpp"
#include "rete/network/ip/tcp/Transport.hpp"
#include "rete/network/ip/udp/Transport.hpp"
#include "rete/network/os/Socket.hpp"
#include "rete/network/os/Sockets.hpp"

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
      m_port(8080),
      m_host("localhost"),
      m_request("GET / HTTP/1.0\n\n\n"),
      m_response("HTTP/1.0 200 OK\n\n\nHello\n")
    {
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
        int err = Usage(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int TcpClientRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        network::Sockets& sockets = this->Sockets(argc, argv, env);

        if ((sockets.Startup())) {
            network::Endpoint& ep = this->Endpoint(argc, argv, env);

            if ((ep.AttachFirst(m_host, m_port))) {
                network::Transport& tp = this->Transport(argc, argv, env);
                network::Socket& sock = this->Socket(argc, argv, env);

                if ((sock.Open(tp))) {
                    if ((sock.Connect(ep))) {
                        ssize_t count = 0;
                        if (0 < (count = sock.Send
                            (m_request.chars(), m_request.length(), 0))) {
                            Receive(sock);
                        }
                    }
                    sock.Close();
                }
                ep.Detach();
            }
            sockets.Cleanup();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int TcpServerRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        network::Sockets& sockets = this->Sockets(argc, argv, env);

        if ((sockets.Startup())) {
            network::Endpoint& ep = this->Endpoint(argc, argv, env);

            if ((ep.Attach(m_port))) {
                network::Transport& tp = this->Transport(argc, argv, env);
                network::Socket& sock = this->Socket(argc, argv, env);

                if ((sock.Open(tp))) {
                    if ((sock.Listen(ep))) {
                        network::Socket* accepted = 0;

                        if ((accepted = sock.Accept(ep))) {
                            Receive(*accepted);
                            accepted->Send(m_response.chars(), m_response.length(), 0);
                            accepted->Close();
                        }
                    }
                    sock.Close();
                }
                ep.Detach();
            }
            sockets.Cleanup();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Receive(network::Socket& sock) {
        ssize_t count = 0, amount = 0;
        do {
            if (0 < (amount = sock.Recv(m_chars, sizeof(m_chars), 0))) {
                this->Out(m_chars, amount);
                count += amount;
            }
        } while (amount >= sizeof(m_chars));
        return count;
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
    virtual network::Sockets&
    Sockets(int argc, char_t **argv, char_t **env) {
        return m_sockets;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnClientOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (&Transport(argc, argv, env) == &TcpTransport(argc, argv, env)) {
            m_run = &Derives::TcpClientRun;
        } else {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnServerOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (&Transport(argc, argv, env) == &TcpTransport(argc, argv, env)) {
            m_run = &Derives::TcpServerRun;
        } else {
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            m_host.assign(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnPortOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            short port = 0;
            std::stringstream ss(optarg);
            if (0 < (ss >> port)) {
                m_port = port;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnFamilyOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnTransportOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

#include "rete/app/console/hello/MainOpt.cpp"
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
    short m_port;
    String m_host, m_request, m_response;
    network::ip::v4::Endpoint m_ip4;
    network::ip::v6::Endpoint m_ip6;
    network::ip::tcp::Transport m_tcp;
    network::ip::udp::Transport m_udp;
    network::os::Socket m_sock;
    network::os::Sockets m_sockets;
    char m_chars[2049];
};

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace rete 

#endif // _RETE_APP_CONSOLE_HELLO_MAIN_HPP 
