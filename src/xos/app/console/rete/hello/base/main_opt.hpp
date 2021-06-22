///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 6/15/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPT_HPP

#include "xos/app/console/rete/hello/message.hpp"
#include "xos/app/console/rete/hello/request.hpp"
#include "xos/app/console/rete/hello/response.hpp"
#include "xos/app/console/rete/main.hpp"

#include "xos/network/ip/v6/udp/transport.hpp"
#include "xos/network/ip/v6/tcp/transport.hpp"
#include "xos/network/ip/v6/endpoint.hpp"

#include "xos/network/ip/v4/udp/transport.hpp"
#include "xos/network/ip/v4/tcp/transport.hpp"
#include "xos/network/ip/v4/endpoint.hpp"

#include "xos/network/local/stream/transport.hpp"
#include "xos/network/local/dgram/transport.hpp"
#include "xos/network/local/endpoint.hpp"

#include "xos/network/os/sockets.hpp"
#include "xos/network/os/socket.hpp"

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_ACCEPT_HOST "*"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_ACCEPT_PORT 8080

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_CONNECT_HOST "localhost"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_CONNECT_PORT 80

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPT "request"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTARG "[text]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTUSE "Request"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTVAL_S "q::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTVAL_C 'q'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPT "respond"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTARG "[text]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTUSE "Respond"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPT "message"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTARG "[text]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTUSE "Message"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTVAL_S "m::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPT "host"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTUSE "Host name or address"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTVAL_S "o::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPT "port"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTARG "[{ 0..2^16-1 }]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTUSE "Port number"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP4 "(4)ip4"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP6 "(6)ip6"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX "(u)unix"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_LOCAL "(l)local"

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX_LOCAL \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX " " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_LOCAL

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPT "ip4"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTARG "[{ " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP6 " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP4 " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX_LOCAL " | ...}]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTUSE "Ipv4 address family"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTVAL_S "4::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTVAL_C '4'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPT "ip6"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTARG "[{ " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP4 " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP6 " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX_LOCAL " | ...}]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTUSE "Ipv6 address family"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTVAL_S "6::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTVAL_C '6'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPT "unix"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTARG "[{ " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP4 " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP6 " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX_LOCAL " | ...}]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTUSE "Unix address family"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTVAL_S "u::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTVAL_C 'u'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPT "family"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG "[{ " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP4 " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP6 " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX_LOCAL " | ...}]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTUSE "Address family"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTVAL_S "f::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTVAL_C 'f'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_RAW "(r)raw"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM "(d)dgram"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_UDP "(u)udp"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM "(s)stream"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_TCP "(t)tcp"

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM_UDP \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM \
    " " XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_UDP

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM_TCP \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM \
    " " XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_TCP

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPT "raw"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTARG "[{ " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM_UDP " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM_TCP " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_RAW "| ...}]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTUSE "Raw transport"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPT "dgram"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTARG "[{ " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM_TCP " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM_UDP " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_RAW " | ...}]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTUSE "Dgram transport"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTVAL_S "d::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPT "stream"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTARG "[{ " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM_UDP " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM_TCP " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_RAW " | ...}]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTUSE "Stream transport"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTVAL_C 's'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPT "transport"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG "[{ " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM_TCP " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM_UDP " | " \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_RAW " | ...}]"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTUSE "Transport"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTVAL_S "t::"
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTVAL_C 't'
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTION \
   {XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTVAL_S \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTVAL_S \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTVAL_S \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTVAL_S \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTVAL_S \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTVAL_S \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTVAL_S \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTVAL_S \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTVAL_S \
   /*XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTVAL_S \
   */XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTVAL_S \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTVAL_S \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTVAL_S \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTION \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTION \
    XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTION \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTION \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTION \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTION \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTION \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTION \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTION \
   /*XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTION \
   */XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTION \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTION \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTION \

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_RETE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_RETE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace rete {
namespace hello {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::rete::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef ushort short_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef xos::base::typest<char_t> chars_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt()
    : run_(0), default_run_(0), 
      restart_(false), stop_(false), once_(false),
      accept_host_(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_ACCEPT_HOST), 
      connect_host_(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_CONNECT_HOST),
      accept_port_(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_CONNECT_PORT),
      again_message_(XOS_APP_CONSOLE_HELLO_AGAIN_MESSAGE),
      bye_message_(XOS_APP_CONSOLE_HELLO_BYE_MESSAGE),
      hello_message_(XOS_APP_CONSOLE_HELLO_HELLO_MESSAGE),
      message_(XOS_APP_CONSOLE_HELLO_HELLO_MESSAGE),
      message_line_separator_(XOS_APP_CONSOLE_HELLO_MESSAGE_LINE_SEPARATOR),
      message_body_separator_(XOS_APP_CONSOLE_HELLO_MESSAGE_BODY_SEPARATOR) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    typedef hello::request request_t;
    typedef hello::response response_t;
    
    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }
    int (derives::*default_run_)(int argc, char_t** argv, char_t** env);
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((default_run_)) {
            err = (this->*default_run_)(argc, argv, env);
        } else {
            err = extends::default_run(argc, argv, env);
        }
        return err;
    }

    /// ...sockets_run
    int (derives::*sockets_run_)(int argc, char_t** argv, char_t** env);
    virtual int which_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (sockets_run_) {
            err = (this->*sockets_run_)(argc, argv, env);
        } else {
            err = default_sockets_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_client_run(argc, argv, env);
        return err;
    }
    virtual int sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_run(argc, argv, env);
            if ((err2 = after_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_sockets_run
    virtual int set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_sockets_run;
        return err;
    }
    virtual int before_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = set_sockets_run(argc, argv, env);
            if ((err2 = after_set_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...client_run
    virtual int client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_client_run(argc, argv, env))) {
            int err2 = 0;
            err = client_run(argc, argv, env);
            if ((err2 = after_client_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_client_run
    virtual int set_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_set_sockets_run(argc, argv, env))) {
            sockets_run_ = &derives::all_client_run;
        }
        return err;
    }
    virtual int before_set_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_client_run(argc, argv, env))) {
            int err2 = 0;
            err = set_client_run(argc, argv, env);
            if ((err2 = after_set_client_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_connect_run
    virtual int set_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_set_client_run(argc, argv, env);
        return err;
    }
    virtual int before_set_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_connect_run(argc, argv, env))) {
            int err2 = 0;
            err = set_connect_run(argc, argv, env);
            if ((err2 = after_set_connect_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...server_run
    virtual int server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_server_run(argc, argv, env))) {
            int err2 = 0;
            err = server_run(argc, argv, env);
            if ((err2 = after_server_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_server_run
    virtual bool is_set_server_run() const {
        if (!(sockets_run_ != &derives::all_server_run)) {
            return true;
        }
        return false;
    }
    virtual int set_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_set_sockets_run(argc, argv, env))) {
            sockets_run_ = &derives::all_server_run;
        }
        return err;
    }
    virtual int before_set_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_server_run(argc, argv, env))) {
            int err2 = 0;
            err = set_server_run(argc, argv, env);
            if ((err2 = after_set_server_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_accept_run
    virtual int set_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_set_server_run(argc, argv, env);
        return err;
    }
    virtual int before_set_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_accept_run(argc, argv, env))) {
            int err2 = 0;
            err = set_accept_run(argc, argv, env);
            if ((err2 = after_set_accept_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...serve_one_run
    virtual int serve_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_server_run(argc, argv, env);
        return err;
    }
    virtual int before_serve_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        set_once();
        return err;
    }
    virtual int after_serve_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        set_once(false);
        return err;
    }
    virtual int all_serve_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_serve_one_run(argc, argv, env))) {
            int err2 = 0;
            err = serve_one_run(argc, argv, env);
            if ((err2 = after_serve_one_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_serve_one_run
    virtual int set_serve_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_set_sockets_run(argc, argv, env))) {
            sockets_run_ = &derives::all_serve_one_run;
        }
        return err;
    }
    virtual int before_set_serve_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_serve_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_serve_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_serve_one_run(argc, argv, env))) {
            int err2 = 0;
            err = set_serve_one_run(argc, argv, env);
            if ((err2 = after_set_serve_one_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_accept_one_run
    virtual int set_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_set_serve_one_run(argc, argv, env);
        return err;
    }
    virtual int before_set_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_accept_one_run(argc, argv, env))) {
            int err2 = 0;
            err = set_accept_one_run(argc, argv, env);
            if ((err2 = after_set_accept_one_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...request_run
    virtual int request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = message().has_chars(length))) {
            int args = (optind < argc)?(argc - optind):(0);
            const char_t** arg = ((const char_t**)(argv + ((optind < argc)?(optind):(argc))));
            request_t request = this->request();
            
            if ((request.on_write(chars, length, args, arg))) {
                if ((chars = request.has_chars(length))) {
                    this->outln(chars, length);
                }
            }
        }
        return err;
    }
    virtual int before_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_request_run(argc, argv, env))) {
            int err2 = 0;
            err = request_run(argc, argv, env);
            if ((err2 = after_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_request_run
    virtual int set_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        default_run_ = &derives::all_request_run;
        return err;
    }
    virtual int before_set_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_request_run(argc, argv, env))) {
            int err2 = 0;
            err = set_request_run(argc, argv, env);
            if ((err2 = after_set_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...respond_run
    virtual int respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = message().has_chars(length))) {
            int args = (optind < argc)?(argc - optind):(0);
            const char_t** arg = ((const char_t**)(argv + ((optind < argc)?(optind):(argc))));
            response_t response = this->response();
            
            if ((response.on_write(chars, length, args, arg))) {
                if ((chars = response.has_chars(length))) {
                    this->outln(chars, length);
                }
            }
        }
        return err;
    }
    virtual int before_respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_respond_run(argc, argv, env))) {
            int err2 = 0;
            err = respond_run(argc, argv, env);
            if ((err2 = after_respond_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_respond_run
    virtual int set_respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        default_run_ = &derives::all_respond_run;
        return err;
    }
    virtual int before_set_respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_respond_run(argc, argv, env))) {
            int err2 = 0;
            err = set_respond_run(argc, argv, env);
            if ((err2 = after_set_respond_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...message_run
    virtual int message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = message().has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_message_run(argc, argv, env))) {
            int err2 = 0;
            err = message_run(argc, argv, env);
            if ((err2 = after_message_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_message_run
    virtual int set_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        default_run_ = &derives::all_message_run;
        return err;
    }
    virtual int before_set_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_message_run(argc, argv, env))) {
            int err2 = 0;
            err = set_message_run(argc, argv, env);
            if ((err2 = after_set_message_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...host_run
    virtual int host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = host().has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_host_run(argc, argv, env))) {
            int err2 = 0;
            err = host_run(argc, argv, env);
            if ((err2 = after_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_host_run
    virtual int set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        default_run_ = &derives::all_host_run;
        return err;
    }
    virtual int before_set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_host_run(argc, argv, env))) {
            int err2 = 0;
            err = set_host_run(argc, argv, env);
            if ((err2 = after_set_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...port_run
    virtual int port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        unsigned_to_string port(this->port());
        if ((chars = port.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_port_run(argc, argv, env))) {
            int err2 = 0;
            err = port_run(argc, argv, env);
            if ((err2 = after_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_port_run
    virtual int set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        default_run_ = &derives::all_port_run;
        return err;
    }
    virtual int before_set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_port_run(argc, argv, env))) {
            int err2 = 0;
            err = set_port_run(argc, argv, env);
            if ((err2 = after_set_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...family_run
    virtual int family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        if ((chars = family())) {
            this->outln(chars);
        }
        return err;
    }
    virtual int before_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_family_run(argc, argv, env))) {
            int err2 = 0;
            err = family_run(argc, argv, env);
            if ((err2 = after_family_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_family_run
    virtual int set_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        default_run_ = &derives::all_family_run;
        return err;
    }
    virtual int before_set_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_family_run(argc, argv, env))) {
            int err2 = 0;
            err = set_family_run(argc, argv, env);
            if ((err2 = after_set_family_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...transport_run
    virtual int transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        if ((chars = transport())) {
            this->outln(chars);
        }
        return err;
    }
    virtual int before_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_transport_run(argc, argv, env))) {
            int err2 = 0;
            err = transport_run(argc, argv, env);
            if ((err2 = after_transport_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_transport_run
    virtual int set_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        default_run_ = &derives::all_transport_run;
        return err;
    }
    virtual int before_set_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_transport_run(argc, argv, env))) {
            int err2 = 0;
            err = set_transport_run(argc, argv, env);
            if ((err2 = after_set_transport_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...family
    virtual void set_family(const char_t* to) {
        if ((to) && (to[0])) {
            if (!((to[1]) || (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP4[1] != to[0]))
                || !(xos::base::chars_t::compare
                     (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP4+3, to))) {
                set_family_ip_v4();
            } else {
                if (!((to[1]) || (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP6[1] != to[0]))
                    || !(xos::base::chars_t::compare
                         (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP6+3, to))) {
                    set_family_ip_v6();
                } else {
                    if (!((to[1]) || (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_LOCAL[1] != to[0]))
                        || !(xos::base::chars_t::compare
                             (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_LOCAL+3, to))) {
                        set_family_local();
                    } else {
                        if (!((to[1]) || (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX[1] != to[0]))
                            || !(xos::base::chars_t::compare
                                 (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX+3, to))) {
                            set_family_unix();
                        } else {
                        }
                    }
                }
            }
        }
    }

    /// ...transport
    virtual void set_transport(const char_t* to) {
        if (!((to[1]) || (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM[1] != to[0]))
            || !(xos::base::chars_t::compare
                 (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM+3, to))) {
            set_transport_tcp(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM+3);
        } else {
            if (!((to[1]) || (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM[1] != to[0]))
                || !(xos::base::chars_t::compare
                     (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM+3, to))) {
                set_transport_udp(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM+3);
            } else {
                if (!((to[1]) || (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_TCP[1] != to[0]))
                    || !(xos::base::chars_t::compare
                         (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_TCP+3, to))) {
                    set_transport_tcp(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_TCP+3);
                } else {
                    if (!((to[1]) || (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_UDP[1] != to[0]))
                        || !(xos::base::chars_t::compare
                             (XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_UDP+3, to))) {
                        set_transport_udp(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_UDP+3);
                    } else {
                    }
                }
            }
        }
    }

    /// ...option...
    virtual int on_request_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        all_set_request_run(argc, argv, env);
        return err;
    }
    virtual const char_t* request_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTARG;
        return chars;
    }
    virtual int on_respond_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        all_set_respond_run(argc, argv, env);
        return err;
    }
    virtual const char_t* respond_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTARG;
        return chars;
    }
    virtual int on_message_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_message(optarg);
        } else {
            all_set_message_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* message_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTARG;
        return chars;
    }
    virtual int on_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_host(optarg);
        } else {
            all_set_host_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTARG;
        return chars;
    }
    virtual int on_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_port(optarg);
        } else {
            all_set_port_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTARG;
        return chars;
    }
    virtual int on_ip4_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_family(optarg);
        } else {
            set_family_ip_v4();
        }
        return err;
    }
    virtual const char_t* ip4_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTARG;
        return chars;
    }
    virtual int on_ip6_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_family(optarg);
        } else {
            set_family_ip_v6();
        }
        return err;
    }
    virtual const char_t* ip6_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTARG;
        return chars;
    }
    virtual int on_unix_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_family(optarg);
        } else {
            set_family_unix();
        }
        return err;
    }
    virtual const char_t* unix_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTARG;
        return chars;
    }
    virtual int on_family_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_family(optarg);
        } else {
            all_set_family_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* family_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG;
        return chars;
    }
    virtual int on_raw_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_transport(optarg);
        } else {
        }
        return err;
    }
    virtual const char_t* raw_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTARG;
        return chars;
    }
    virtual int on_dgram_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_transport(optarg);
        } else {
            set_transport_udp(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_DGRAM+3);
        }
        return err;
    }
    virtual const char_t* dgram_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTARG;
        return chars;
    }
    virtual int on_stream_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_transport(optarg);
        } else {
            set_transport_tcp(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_STREAM+3);
        }
        return err;
    }
    virtual const char_t* stream_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTARG;
        return chars;
    }
    virtual int on_transport_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_transport(optarg);
        } else {
            all_set_transport_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* transport_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTVAL_C:
            err = this->on_request_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTVAL_C:
            err = this->on_respond_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTVAL_C:
            err = this->on_message_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTVAL_C:
            err = this->on_ip4_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTVAL_C:
            err = this->on_ip6_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTVAL_C:
            err = this->on_unix_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTVAL_C:
            err = this->on_family_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        /*case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTVAL_C:
            err = this->on_raw_option(optval, optarg, optname, optind, argc, argv, env);
            break;*/
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTVAL_C:
            err = this->on_dgram_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTVAL_C:
            err = this->on_stream_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTVAL_C:
            err = this->on_transport_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_REQUEST_OPTVAL_C:
            chars = request_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RESPOND_OPTVAL_C:
            chars = respond_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_MESSAGE_OPTVAL_C:
            chars = message_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_HOST_OPTVAL_C:
            chars = host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_PORT_OPTVAL_C:
            chars = port_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP4_OPTVAL_C:
            chars = ip4_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_IP6_OPTVAL_C:
            chars = ip6_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_UNIX_OPTVAL_C:
            chars = unix_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTVAL_C:
            chars = family_option_usage(optarg, longopt);
            break;
        /*case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_RAW_OPTVAL_C:
            chars = raw_option_usage(optarg, longopt);
            break;*/
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_DGRAM_OPTVAL_C:
            chars = dgram_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_STREAM_OPTVAL_C:
            chars = stream_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTVAL_C:
            chars = transport_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...send...
    typedef int (derives::*send_t)
    (network::socket& s, network::endpoint& ep,
     const char_t* chars, size_t length, int argc, char_t** argv, char_t** env);
    send_t send_;
    virtual send_t send() const {
        send_t send = 0;
        if (!(send = send_)) {
            send = default_send();
        }
        return send;
    }
    virtual send_t default_send() const {
        send_t send = &derives::client_tcp_send;
        return send;
    }
    virtual int client_tcp_send
    (network::socket& s, network::endpoint& ep,
     const char_t* chars, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int client_udp_send
    (network::socket& s, network::endpoint& ep,
     const char_t* chars, size_t length,  int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...listen...
    typedef int (derives::*listen_t)
    (network::socket& s, network::endpoint& ep, int argc, char_t** argv, char_t** env);
    listen_t listen_;
    virtual listen_t listen() const {
        listen_t listen = 0;
        if (!(listen = listen_)) {
            listen = default_listen();
        }
        return listen;
    }
    virtual listen_t default_listen() const {
        listen_t listen = &derives::server_tcp_listen;
        return listen;
    }
    virtual int server_tcp_listen
    (network::socket& s, network::endpoint& ep, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int server_udp_listen
    (network::socket& s, network::endpoint& ep, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    
    /// ...endpoint...
    network::endpoint* (derives::*ep_)();
    virtual network::endpoint* new_ep() {
        network::endpoint* ep = 0;
        if ((ep_)) {
            ep = (this->*ep_)();
        } else {
            ep = default_ep();
        }
        return ep;
    }
    virtual void delete_ep(network::endpoint*& p) {
        if ((p)) {
            delete p;
            p = 0;
        } else {
        }
    }
    virtual network::endpoint* default_ep() {
        network::endpoint* ep = ip_v4_ep();
        return ep;
    }
    virtual network::endpoint* ip_v4_ep() {
        const char_t* host;
        short_t port;
        if (!(is_set_server_run())) {
            if ((host = this->host().has_chars()) && (0 < (port = this->port()))) {
                network::endpoint* ep = new network::ip::v4::endpoint(host, port);
                return ep;
            }
        } else {
            if ((0 < (port = this->port()))) {
                network::endpoint* ep = new network::ip::v4::endpoint(port);
                return ep;
            }
        }
        return 0;
    }
    virtual network::endpoint* ip_v6_ep() {
        const char_t* host;
        short_t port;
        if (!(is_set_server_run())) {
            if ((host = this->host().has_chars()) && (0 < (port = this->port()))) {
                network::endpoint* ep = new network::ip::v6::endpoint(host, port);
                return ep;
            }
        } else {
            if ((0 < (port = this->port()))) {
                network::endpoint* ep = new network::ip::v6::endpoint(port);
                return ep;
            }
        }
        return 0;
    }
    virtual network::endpoint* local_ep() {
        const char_t* host;
        if ((host = this->host().has_chars())) {
            network::endpoint* ep = new network::local::endpoint(host);
            return ep;
        }
        return 0;
    }

    /// ...family...
    const char_t* family_;
    const char_t* family() const {
         const char_t* fam = 0;
         if (!(fam = family_)) {
             fam = default_family();
         }
         return fam;
    }
    const char_t* default_family() const {        
        const char_t* fam = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP4+3;
        return fam;
    }
    virtual void set_family_ip_v4() {
        family_ = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP4+3;
        ep_ = &derives::ip_v4_ep;
        if ((is_stream_tp())) {
            tp_ = &derives::ip_v4_tcp_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &derives::ip_v4_udp_tp;
            } else {
            }
        }
    }
    virtual void set_family_ip_v6() {
        family_ = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_IP6+3;
        ep_ = &derives::ip_v6_ep;
        if ((is_stream_tp())) {
            tp_ = &derives::ip_v6_tcp_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &derives::ip_v6_udp_tp;
            } else {
            }
        }
    }
    virtual void set_family_local(const char_t* to) {
        family_ = to;
        ep_ = &derives::local_ep;
        if ((is_stream_tp())) {
            tp_ = &derives::local_stream_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &derives::local_dgram_tp;
            } else {
            }
        }
    }
    virtual void set_family_local() {
        set_family_local(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_LOCAL+3);
    }
    virtual void set_family_unix() {
        set_family_local(XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_FAMILY_OPTARG_UNIX+3);
    }

    /// ...transport...
    const char_t* transport_;
    virtual const char_t* transport() {
        const char_t* tp = 0;
        if (!(tp = transport_)) {
            tp = default_transport();
        }
        return tp;
    }
    virtual const char_t* default_transport() {
        const char_t* tp = XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_TRANSPORT_OPTARG_TCP+3;
        return tp;
    }
    network::transport* (derives::*tp_)();
    virtual network::transport* new_tp() {
        network::transport* tp = 0;
        if ((tp_)) {
            tp = (this->*tp_)();
        } else {
            tp = default_tp();
        }
        return tp;
    }
    virtual void delete_tp(network::transport*& p) {
        if ((p)) {
            delete p;
            p = 0;
        } else {
        }
    }
    virtual network::transport* default_tp() {
        network::transport* tp = ip_v4_tcp_tp();
        return tp;
    }
    virtual network::transport* ip_v4_tcp_tp() {
        network::transport* tp = new network::ip::v4::tcp::transport();
        return tp;
    }
    virtual network::transport* ip_v4_udp_tp() {
        network::transport* tp = new network::ip::v4::udp::transport();
        return tp;
    }
    virtual network::transport* ip_v6_tcp_tp() {
        network::transport* tp = new network::ip::v6::tcp::transport();
        return tp;
    }
    virtual network::transport* ip_v6_udp_tp() {
        network::transport* tp = new network::ip::v6::udp::transport();
        return tp;
    }
    virtual network::transport* local_stream_tp() {
        network::transport* tp = new network::local::stream::transport();
        return tp;
    }
    virtual network::transport* local_dgram_tp() {
        network::transport* tp = new network::local::dgram::transport();
        return tp;
    }
    virtual void set_transport_tcp(const char_t* to) {
        transport_ = to;
        set_transport_tcp();
    }
    virtual void set_transport_tcp() {
        send_ = &derives::client_tcp_send;
        listen_ = &derives::server_tcp_listen;
        if ((&derives::ip_v4_ep == ep_)) {
            tp_ = &derives::ip_v4_tcp_tp;
        } else {
            if ((&derives::ip_v6_ep == ep_)) {
                tp_ = &derives::ip_v6_tcp_tp;
            } else {
            }
        }
    }
    virtual void set_transport_udp(const char_t* to) {
        transport_ = to;
        set_transport_udp();
    }
    virtual void set_transport_udp() {
        send_ = &derives::client_udp_send;
        listen_ = &derives::server_udp_listen;
        if ((&derives::ip_v4_ep == ep_)) {
            tp_ = &derives::ip_v4_udp_tp;
        } else {
            if ((&derives::ip_v6_ep == ep_)) {
                tp_ = &derives::ip_v6_udp_tp;
            } else {
            }
        }
    }
    virtual bool is_stream_tp() const {
        if ((&derives::ip_v4_tcp_tp == tp_)
            || (&derives::ip_v6_tcp_tp == tp_)
            || (&derives::local_stream_tp == tp_)) {
            return true;
        }
        return false;
    }
    virtual bool is_dgram_tp() const {
        if ((&derives::ip_v4_udp_tp == tp_)
            || (&derives::ip_v6_udp_tp == tp_)
            || (&derives::local_dgram_tp == tp_)) {
            return true;
        }
        return false;
    }

    /// host / port
    virtual string_t& set_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_host(chars);
    }
    virtual string_t& set_host(const char_t* to) {
        if ((to) && (to[0])) {
            accept_host().assign(to);
            connect_host().assign(to);
        } else {
            accept_host().clear();
            connect_host().clear();
        }
        return host();
    }
    virtual string_t& host() const {
        return this->connect_host();
    }
    virtual short_t& set_port(const char_t* to) {
        unsigned n = 0;
        string_t s(to);
        if (0 < (n = s.to_unsigned())) {
            accept_port() = n;
            connect_port() = n;
        }
        return port();
    }
    virtual short_t& set_port(const short_t& to) {
        unsigned n = 0;
        if (0 < (n = to)) {
            accept_port() = n;
            connect_port() = n;
        }
        return port();
    }
    virtual short_t& port() const {
        return this->connect_port();
    }

    /// ...accept_host / ...accept_port
    virtual string_t& set_accept_host(const string_t& to) {
        string_t& accept_host = this->accept_host();
        const char_t* chars = to.has_chars();
        if ((chars)) accept_host.assign(to);
        else accept_host.clear();
        return accept_host;
    }
    virtual string_t& set_accept_host(const char_t* to) {
        string_t& accept_host = this->accept_host();
        if ((to)) accept_host.assign(to);
        else accept_host.clear();
        return accept_host;
    }
    virtual string_t& accept_host() const {
        return (string_t&)accept_host_;
    }
    virtual short_t& set_accept_port(short to) {
        short_t& accept_port = this->accept_port();
        accept_port = to;
        return accept_port;
    }
    virtual short_t& accept_port() const {
        return (short_t&)accept_port_;
    }

    /// ...connect_host / ...connect_port
    virtual string_t& set_connect_host(const string_t& to) {
        string_t& connect_host = this->connect_host();
        const char_t* chars = to.has_chars();
        if ((chars)) connect_host.assign(to);
        else connect_host.clear();
        return connect_host;
    }
    virtual string_t& set_connect_host(const char_t* to) {
        string_t& connect_host = this->connect_host();
        if ((to)) connect_host.assign(to);
        else connect_host.clear();
        return connect_host;
    }
    virtual string_t& connect_host() const {
        return (string_t&)connect_host_;
    }
    virtual short_t& set_connect_port(short to) {
        short_t& connect_port = this->connect_port();
        connect_port = to;
        return connect_port;
    }
    virtual short_t& connect_port() const {
        return (short_t&)connect_port_;
    }

    /// ...again_message
    virtual string_t& set_again_message(const string_t& to) {
        string_t& again_message = this->again_message();
        const char_t* chars = to.has_chars();
        if ((chars)) again_message.assign(to);
        else again_message.clear();
        return again_message;
    }
    virtual string_t& set_again_message(const char_t* to) {
        string_t& again_message = this->again_message();
        if ((to)) again_message.assign(to);
        else again_message.clear();
        return again_message;
    }
    virtual string_t& again_message() const {
        return (string_t&)again_message_;
    }

    /// ...bye_message
    virtual string_t& set_bye_message(const string_t& to) {
        string_t& bye_message = this->bye_message();
        const char_t* chars = to.has_chars();
        if ((chars)) bye_message.assign(to);
        else bye_message.clear();
        return bye_message;
    }
    virtual string_t& set_bye_message(const char_t* to) {
        string_t& bye_message = this->bye_message();
        if ((to)) bye_message.assign(to);
        else bye_message.clear();
        return bye_message;
    }
    virtual string_t& bye_message() const {
        return (string_t&)bye_message_;
    }

    /// ...hello_message
    virtual string_t& set_hello_message(const string_t& to) {
        string_t& hello_message = this->hello_message();
        const char_t* chars = to.has_chars();
        if ((chars)) hello_message.assign(to);
        else hello_message.clear();
        return hello_message;
    }
    virtual string_t& set_hello_message(const char_t* to) {
        string_t& hello_message = this->hello_message();
        if ((to)) hello_message.assign(to);
        else hello_message.clear();
        return hello_message;
    }
    virtual string_t& hello_message() const {
        return (string_t&)hello_message_;
    }

    /// ...message
    virtual string_t& set_message(const string_t& to) {
        string_t& message = this->message();
        const char_t* chars = to.has_chars();
        if ((chars)) message.assign(to);
        else message.clear();
        return message;
    }
    virtual string_t& set_message(const char_t* to) {
        string_t& message = this->message();
        if ((to)) message.assign(to);
        else message.clear();
        return message;
    }
    virtual string_t& message() const {
        return (string_t&)message_;
    }

    /// ...message_line_separator
    virtual string_t& set_message_line_separator(const string_t& to) {
        string_t& message_line_separator = this->message_line_separator();
        const char_t* chars = to.has_chars();
        if ((chars)) message_line_separator.assign(to);
        else message_line_separator.clear();
        return message_line_separator;
    }
    virtual string_t& set_message_line_separator(const char_t* to) {
        string_t& message_line_separator = this->message_line_separator();
        if ((to)) message_line_separator.assign(to);
        else message_line_separator.clear();
        return message_line_separator;
    }
    virtual string_t& message_line_separator() const {
        return (string_t&)message_line_separator_;
    }

    /// ...message_body_separator
    virtual string_t& set_message_body_separator(const string_t& to) {
        string_t& message_body_separator = this->message_body_separator();
        const char_t* chars = to.has_chars();
        if ((chars)) message_body_separator.assign(to);
        else message_body_separator.clear();
        return message_body_separator;
    }
    virtual string_t& set_message_body_separator(const char_t* to) {
        string_t& message_body_separator = this->message_body_separator();
        if ((to)) message_body_separator.assign(to);
        else message_body_separator.clear();
        return message_body_separator;
    }
    virtual string_t& message_body_separator() const {
        return (string_t&)message_body_separator_;
    }

    /// ...request... / ...response...
    virtual request_t& request() const {
        return (request_t&)request_;
    }
    virtual response_t& response() const {
        return (response_t&)response_;
    }
    virtual char_t* chars(size_t& size) const {
        size  = sizeof(chars_);
        return ((char_t*)chars_);
    }

    /// restart / stop / done
    virtual bool& set_restart(bool to = true) {
        bool& restart = this->restart();
        restart = to;
        return restart;
    }
    virtual bool& restart() const {
        return ((bool&)restart_);
    }
    virtual bool& set_stop(bool to = true) {
        bool& stop = this->stop();
        stop = to;
        return stop;
    }
    virtual bool& stop() const {
        return ((bool&)stop_);
    }
    virtual bool& set_once(bool to = true) {
        bool& once = this->once();
        once = to;
        return once;
    }
    virtual bool& once() const {
        return ((bool&)once_);
    }

protected:
    bool restart_, stop_, once_;
    string_t accept_host_, connect_host_;
    short_t accept_port_, connect_port_;
    string_t again_message_, bye_message_, hello_message_, message_,
             message_line_separator_, message_body_separator_;
    request_t request_;
    response_t response_;
    char_t chars_[2048];
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace hello
} /// namespace rete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_RETE_HELLO_BASE_MAIN_OPT_HPP
