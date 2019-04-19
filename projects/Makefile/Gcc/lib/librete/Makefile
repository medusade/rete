########################################################################
# Copyright (c) 1988-2019 $organization$
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
#   File: Makefile
#
# Author: $author$
#   Date: 4/9/2019
#
# generic Gcc Makefile for rete Library librete
########################################################################


#
# target
#
librete_LIBTARGET = librete.${LIBEXT}

########################################################################

#
# user c++ flags
#
librete_USRCXXFLAGS += \
${rete_USRCXXFLAGS} \

#
# user defines
#
librete_USRDEFINES += \
${rete_USRDEFINES} \

#
# user includes
#
librete_USRINCLUDES += \
${rete_USRINCLUDES} \

#
# user libdirs
#
librete_USRLIBDIRS += \
${rete_USRLIBDIRS} \

########################################################################

#
# Library .c sources
#
#librete_LIB_C_SOURCES += \
#${RETE_SRC}/rete/base/Base.c \

#
# Library .cc sources
#
#librete_LIB_CC_SOURCES += \
#${RETE_SRC}/rete/base/Base.cc \

#
# Library .cxx sources
#
#librete_LIB_CXX_SOURCES += \
#${RETE_SRC}/rete/base/Base.cxx \

#
# Library .cpp sources
#
librete_LIB_CPP_SOURCES += \
${RETE_SRC}/rete/base/Attached.cpp \
${RETE_SRC}/rete/base/Base.cpp \
${RETE_SRC}/rete/base/Opened.cpp \
\
${RETE_SRC}/rete/io/Reader.cpp \
${RETE_SRC}/rete/io/Stream.cpp \
${RETE_SRC}/rete/io/Writer.cpp \
\
${RETE_SRC}/rete/network/Address.cpp \
${RETE_SRC}/rete/network/Endpoint.cpp \
${RETE_SRC}/rete/network/Location.cpp \
${RETE_SRC}/rete/network/Socket.cpp \
${RETE_SRC}/rete/network/SocketReader.cpp \
${RETE_SRC}/rete/network/Sockets.cpp \
${RETE_SRC}/rete/network/SocketStream.cpp \
${RETE_SRC}/rete/network/SocketWriter.cpp \
${RETE_SRC}/rete/network/Transport.cpp \
\
${RETE_SRC}/rete/lib/rete/Version.cpp \
\
${RETE_SRC}/rete/console/lib/rete/version/Main.cpp \

#
# Library .m sources
#
#librete_LIB_M_SOURCES += \
#${RETE_SRC}/rete/base/Base.m \

#
# Library .mm sources
#
#librete_LIB_MM_SOURCES += \
#${RETE_SRC}/rete/base/Base.mm \


########################################################################




