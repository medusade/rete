########################################################################
# Copyright (c) 1988-2016 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: rete.pri
#
# Author: $author$
#   Date: 7/10/2017
########################################################################

########################################################################
# nadir
rete_HEADERS += \
$${NADIR_SRC}/nadir/base/to_string.hpp \

rete_SOURCES += \
$${NADIR_SRC}/nadir/base/to_string.cpp \

########################################################################
# crono
rete_HEADERS += \
$${CRONO_SRC}/crono/io/Logger.hpp \

rete_SOURCES += \

########################################################################
# base
rete_HEADERS += \
$${RETE_SRC}/rete/base/Opened.hpp \
$${RETE_SRC}/rete/base/Attached.hpp \
$${RETE_SRC}/rete/base/Base.hpp \

rete_SOURCES += \

########################################################################
# io
rete_HEADERS += \
$${RETE_SRC}/rete/io/socket/tcp/Writer.hpp \
$${RETE_SRC}/rete/io/socket/Writer.hpp \
$${RETE_SRC}/rete/io/socket/tcp/Reader.hpp \
$${RETE_SRC}/rete/io/socket/Reader.hpp \
$${RETE_SRC}/rete/io/socket/Base.hpp \

rete_SOURCES += \
$${RETE_SRC}/rete/io/socket/tcp/Writer.cpp \
$${RETE_SRC}/rete/io/socket/tcp/Reader.cpp \
$${RETE_SRC}/rete/io/socket/Base.cpp \

########################################################################
# network
rete_HEADERS += \
$${RETE_SRC}/rete/network/local/dgram/Transport.hpp \
$${RETE_SRC}/rete/network/local/stream/Transport.hpp \
$${RETE_SRC}/rete/network/local/Transport.hpp \
$${RETE_SRC}/rete/network/ip/Transports.hpp \
$${RETE_SRC}/rete/network/ip/v4/udp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/v6/udp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/udp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/v4/tcp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/v6/tcp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/tcp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/Transport.hpp \
$${RETE_SRC}/rete/network/Transport.hpp \

########################################################################
# network
rete_HEADERS += \
$${RETE_SRC}/rete/network/local/Address.hpp \
$${RETE_SRC}/rete/network/ip/Addresses.hpp \
$${RETE_SRC}/rete/network/ip/v6/Address.hpp \
$${RETE_SRC}/rete/network/ip/v4/Address.hpp \
$${RETE_SRC}/rete/network/ip/Address.hpp \
$${RETE_SRC}/rete/network/Address.hpp \

########################################################################
# network
rete_HEADERS += \
$${RETE_SRC}/rete/network/local/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/Endpoints.hpp \
$${RETE_SRC}/rete/network/ip/v6/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/v4/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/Endpoint.hpp \
$${RETE_SRC}/rete/network/Endpoint.hpp \

########################################################################
# network
rete_HEADERS += \
$${RETE_SRC}/rete/network/os/Sockets.hpp \
$${RETE_SRC}/rete/network/microsoft/windows/Sockets.hpp \
$${RETE_SRC}/rete/network/apple/osx/Sockets.hpp \
$${RETE_SRC}/rete/network/posix/Sockets.hpp \
$${RETE_SRC}/rete/network/Sockets.hpp \
$${RETE_SRC}/rete/network/os/Socket.hpp \
$${RETE_SRC}/rete/network/microsoft/windows/Socket.hpp \
$${RETE_SRC}/rete/network/apple/osx/Socket.hpp \
$${RETE_SRC}/rete/network/linux/Socket.hpp \
$${RETE_SRC}/rete/network/posix/Socket.hpp \
$${RETE_SRC}/rete/network/Socket.hpp \
$${RETE_SRC}/rete/network/os/Os.hpp \

rete_SOURCES += \
$${RETE_SRC}/rete/network/os/Sockets.cpp \
$${RETE_SRC}/rete/network/os/Socket.cpp \
$${RETE_SRC}/rete/network/ip/Endpoints.cpp \
$${RETE_SRC}/rete/network/ip/Transports.cpp \
$${RETE_SRC}/rete/network/ip/Addresses.cpp \
$${RETE_SRC}/rete/network/os/Os.cpp \

########################################################################
# network
rete_HEADERS += \
$${RETE_SRC}/rete/network/sockets/Interface.hpp \
$${RETE_SRC}/rete/network/sockets/Endpoint.hpp \
$${RETE_SRC}/rete/network/sockets/Location.hpp \
$${RETE_SRC}/rete/network/sockets/Address.hpp \
$${RETE_SRC}/rete/network/sockets/Transport.hpp \

rete_SOURCES += \
$${RETE_SRC}/rete/network/sockets/Interface.cpp \
$${RETE_SRC}/rete/network/sockets/Endpoint.cpp \
$${RETE_SRC}/rete/network/sockets/Location.cpp \
$${RETE_SRC}/rete/network/sockets/Address.cpp \
$${RETE_SRC}/rete/network/sockets/Transport.cpp \

########################################################################
rete_HEADERS += \
$${RETE_SRC}/rete/app/console/rete/Main.hpp \
$${RETE_SRC}/rete/app/console/rete/MainOpt.hpp \
$${RETE_SRC}/rete/app/console/network/MainOpt.hpp \
$${RETE_SRC}/rete/app/console/network/Main.hpp \
$${RETE_SRC}/rete/console/getopt/MainOpt.hpp \
$${RETE_SRC}/rete/console/getopt/Main.hpp \
$${RETE_SRC}/rete/console/Main.hpp \
$${RETE_SRC}/rete/console/Main_main.hpp \

rete_SOURCES += \
$${RETE_SRC}/rete/app/console/rete/Main.cpp \
$${RETE_SRC}/rete/app/console/rete/MainOpt.cpp \
$${RETE_SRC}/rete/console/Main_main.cpp \

########################################################################
