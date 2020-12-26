########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   File: librete.pri
#
# Author: $author$
#   Date: 3/24/2018, 12/26/2020
#
# QtCreator .pri file for rete library librete
########################################################################

########################################################################
# librete

# librete TARGET
#
librete_TARGET = rete
librete_TEMPLATE = lib
librete_CONFIG += staticlib

# librete INCLUDEPATH
#
librete_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# librete DEFINES
#
librete_DEFINES += \
$${rete_DEFINES} \
XOS_DEFAULT_LOG_ERROR \

########################################################################
# librete OBJECTIVE_HEADERS
#
#librete_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/rete/base/Base.hh \

# librete OBJECTIVE_SOURCES
#
#librete_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/rete/base/Base.mm \

########################################################################
# librete HEADERS
#
librete_HEADERS += \
$${RETE_SRC}/rete/base/Attached.hpp \
$${RETE_SRC}/rete/base/Base.hpp \
$${RETE_SRC}/rete/base/Opened.hpp \
\
$${RETE_SRC}/rete/io/Reader.hpp \
$${RETE_SRC}/rete/io/socket/Base.hpp \
$${RETE_SRC}/rete/io/socket/Reader.hpp \
$${RETE_SRC}/rete/io/socket/tcp/Reader.hpp \
$${RETE_SRC}/rete/io/socket/tcp/Writer.hpp \
$${RETE_SRC}/rete/io/socket/Writer.hpp \
$${RETE_SRC}/rete/io/Stream.hpp \
$${RETE_SRC}/rete/io/Writer.hpp \
\
$${RETE_SRC}/rete/network/Address.hpp \
$${RETE_SRC}/rete/network/apple/osx/Socket.hpp \
$${RETE_SRC}/rete/network/apple/osx/Sockets.hpp \
$${RETE_SRC}/rete/network/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/Address.hpp \
$${RETE_SRC}/rete/network/ip/Addresses.hpp \
$${RETE_SRC}/rete/network/ip/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/Endpoints.hpp \
$${RETE_SRC}/rete/network/ip/tcp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/Transport.hpp \
$${RETE_SRC}/rete/network/ip/Transports.hpp \
$${RETE_SRC}/rete/network/ip/udp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/v4/Address.hpp \
$${RETE_SRC}/rete/network/ip/v4/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/v4/tcp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/v4/udp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/v6/Address.hpp \
$${RETE_SRC}/rete/network/ip/v6/Endpoint.hpp \
$${RETE_SRC}/rete/network/ip/v6/tcp/Transport.hpp \
$${RETE_SRC}/rete/network/ip/v6/udp/Transport.hpp \
$${RETE_SRC}/rete/network/linux/Socket.hpp \
$${RETE_SRC}/rete/network/local/Address.hpp \
$${RETE_SRC}/rete/network/local/dgram/Transport.hpp \
$${RETE_SRC}/rete/network/local/Endpoint.hpp \
$${RETE_SRC}/rete/network/local/stream/Transport.hpp \
$${RETE_SRC}/rete/network/local/Transport.hpp \
$${RETE_SRC}/rete/network/Location.hpp \
$${RETE_SRC}/rete/network/microsoft/windows/Socket.hpp \
$${RETE_SRC}/rete/network/microsoft/windows/Sockets.hpp \
$${RETE_SRC}/rete/network/os/Os.hpp \
$${RETE_SRC}/rete/network/os/Socket.hpp \
$${RETE_SRC}/rete/network/os/Sockets.hpp \
$${RETE_SRC}/rete/network/posix/Socket.hpp \
$${RETE_SRC}/rete/network/posix/Sockets.hpp \
$${RETE_SRC}/rete/network/Socket.hpp \
$${RETE_SRC}/rete/network/SocketReader.hpp \
$${RETE_SRC}/rete/network/sockets/Address.hpp \
$${RETE_SRC}/rete/network/sockets/apple/osx/Interface.hpp \
$${RETE_SRC}/rete/network/sockets/Connection.hpp \
$${RETE_SRC}/rete/network/sockets/Endpoint.hpp \
$${RETE_SRC}/rete/network/sockets/Interface.hpp \
$${RETE_SRC}/rete/network/sockets/Location.hpp \
$${RETE_SRC}/rete/network/sockets/microsoft/windows/Interface.hpp \
$${RETE_SRC}/rete/network/sockets/os/Interface.hpp \
$${RETE_SRC}/rete/network/sockets/posix/Interface.hpp \
$${RETE_SRC}/rete/network/sockets/Transport.hpp \
$${RETE_SRC}/rete/network/Sockets.hpp \
$${RETE_SRC}/rete/network/SocketStream.hpp \
$${RETE_SRC}/rete/network/SocketWriter.hpp \
$${RETE_SRC}/rete/network/Transport.hpp \
\
$${RETE_SRC}/rete/lib/Version.hpp \
$${RETE_SRC}/rete/lib/rete/Version.hpp \
\
$${RETE_SRC}/rete/console/lib/rete/version/Main.hpp \

# librete SOURCES
#
librete_SOURCES += \
$${RETE_SRC}/rete/base/Attached.cpp \
$${RETE_SRC}/rete/base/Base.cpp \
$${RETE_SRC}/rete/base/Opened.cpp \
\
$${RETE_SRC}/rete/io/Reader.cpp \
$${RETE_SRC}/rete/io/Stream.cpp \
$${RETE_SRC}/rete/io/Writer.cpp \
\
$${RETE_SRC}/rete/network/Address.cpp \
$${RETE_SRC}/rete/network/Endpoint.cpp \
$${RETE_SRC}/rete/network/Location.cpp \
$${RETE_SRC}/rete/network/Socket.cpp \
$${RETE_SRC}/rete/network/SocketReader.cpp \
$${RETE_SRC}/rete/network/Sockets.cpp \
$${RETE_SRC}/rete/network/SocketStream.cpp \
$${RETE_SRC}/rete/network/SocketWriter.cpp \
$${RETE_SRC}/rete/network/Transport.cpp \
\
$${RETE_SRC}/rete/lib/rete/Version.cpp \
\
$${RETE_SRC}/rete/console/lib/rete/version/Main.cpp \

########################################################################



