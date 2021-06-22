########################################################################
# Copyright (c) 1988-2021 $organization$
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
#   File: libxosrete.pri
#
# Author: $author$
#   Date: 6/14/2021
#
# QtCreator .pri file for xosrete library libxosrete
########################################################################

########################################################################
# libxosrete

# libxosrete TARGET
#
libxosrete_TARGET = xosrete
libxosrete_TEMPLATE = lib
libxosrete_CONFIG += staticlib

# libxosrete INCLUDEPATH
#
libxosrete_INCLUDEPATH += \
$${xosrete_INCLUDEPATH} \

# libxosrete DEFINES
#
libxosrete_DEFINES += \
$${xosrete_DEFINES} \
XOS_LIB_RETE_VERSION_NAME=lib$${XOSRETE_LIB_NAME}
DEFAULT_LOG_ERROR \

########################################################################
# libxosrete OBJECTIVE_HEADERS
#
#libxosrete_OBJECTIVE_HEADERS += \
#$${XOSRETE_SRC}/xos/app/console/xosrete/main.hh \

# libxosrete OBJECTIVE_SOURCES
#
#libxosrete_OBJECTIVE_SOURCES += \
#$${XOSRETE_SRC}/xos/app/console/xosrete/main.mm \

########################################################################
# libxosrete HEADERS
#
libxosrete_HEADERS += \
$${RETE_SRC}/xos/lib/rete/version.hpp \

# libxosrete SOURCES
#
libxosrete_SOURCES += \
$${RETE_SRC}/xos/lib/rete/version.cpp \

########################################################################
