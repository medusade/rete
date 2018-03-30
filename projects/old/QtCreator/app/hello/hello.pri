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
#   File: hello.pri
#
# Author: $author$
#   Date: 11/30/2016
########################################################################

hello_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

hello_DEFINES += \
$${rete_DEFINES} \

########################################################################
hello_HEADERS += \
$${NADIR_SRC}/nadir/base/to_string.hpp \

hello_SOURCES += \
$${NADIR_SRC}/nadir/base/to_string.cpp \

########################################################################
hello_HEADERS += \
$${RETE_SRC}/rete/base/Opened.hpp \
$${RETE_SRC}/rete/base/Attached.hpp \
$${RETE_SRC}/rete/base/Base.hpp \

hello_SOURCES += \

########################################################################
hello_HEADERS += \
$${CRONO_SRC}/crono/io/Logger.hpp \

hello_SOURCES += \

########################################################################
hello_HEADERS += \
$${RETE_SRC}/rete/io/socket/tcp/Writer.hpp \
$${RETE_SRC}/rete/io/socket/Writer.hpp \
$${RETE_SRC}/rete/io/socket/tcp/Reader.hpp \
$${RETE_SRC}/rete/io/socket/Reader.hpp \
$${RETE_SRC}/rete/io/socket/Base.hpp \

hello_SOURCES += \
$${RETE_SRC}/rete/io/socket/tcp/Writer.cpp \
$${RETE_SRC}/rete/io/socket/tcp/Reader.cpp \
$${RETE_SRC}/rete/io/socket/Base.cpp \

########################################################################
hello_HEADERS += \
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

hello_HEADERS += \
$${RETE_SRC}/rete/network/local/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/Endpoints.hpp \
$${RETE_SRC}/rete/network/ip/v6/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/v4/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/Endpoint.hpp \
$${RETE_SRC}/rete/network/Endpoint.hpp \

hello_HEADERS += \
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

hello_HEADERS += \
$${RETE_SRC}/rete/network/local/Address.hpp \
$${RETE_SRC}/rete/network/ip/Addresses.hpp \
$${RETE_SRC}/rete/network/ip/v6/Address.hpp \
$${RETE_SRC}/rete/network/ip/v4/Address.hpp \
$${RETE_SRC}/rete/network/ip/Address.hpp \
$${RETE_SRC}/rete/network/Address.hpp \
$${RETE_SRC}/rete/network/os/Os.hpp \

hello_SOURCES += \
$${RETE_SRC}/rete/network/os/Sockets.cpp \
$${RETE_SRC}/rete/network/os/Socket.cpp \
$${RETE_SRC}/rete/network/ip/Endpoints.cpp \
$${RETE_SRC}/rete/network/ip/Transports.cpp \
$${RETE_SRC}/rete/network/ip/Addresses.cpp \
$${RETE_SRC}/rete/network/local/Endpoint.cpp \
$${RETE_SRC}/rete/network/local/dgram/Transport.cpp \
$${RETE_SRC}/rete/network/local/Address.cpp \
$${RETE_SRC}/rete/network/os/Os.cpp \

########################################################################
hello_HEADERS += \
$${RETE_SRC}/rete/console/getopt/MainOpt.hpp \
$${RETE_SRC}/rete/console/getopt/Main.hpp \
$${RETE_SRC}/rete/console/Main.hpp \
$${RETE_SRC}/rete/console/Main_main.hpp \
$${RETE_SRC}/rete/app/console/hello/MainOpt.hpp \
$${RETE_SRC}/rete/app/console/hello/Main.hpp \

hello_SOURCES += \
$${RETE_SRC}/rete/app/console/hello/Main.cpp \

########################################################################
hello_LIBS += \
$${rete_LIBS} \

