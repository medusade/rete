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
#   File: xosrete.pri
#
# Author: $author$
#   Date: 6/14/2021
#
# QtCreator .pri file for xosrete
########################################################################

OTHER_PKG = ../../../../../..
OTHER_PRJ = ../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/source/$${THIRDPARTY_NAME}

########################################################################
# xosrostra
XOSROSTRA_VERSION_MAJOR = 0
XOSROSTRA_VERSION_MINOR = 0
XOSROSTRA_VERSION_RELEASE = 0
XOSROSTRA_VERSION = $${XOSROSTRA_VERSION_MAJOR}.$${XOSROSTRA_VERSION_MINOR}.$${XOSROSTRA_VERSION_RELEASE}
XOSROSTRA_NAME = rostra
XOSROSTRA_GROUP = $${XOSROSTRA_NAME}
XOSROSTRA_SOURCE = src
XOSROSTRA_DIR = $${XOSROSTRA_GROUP}/$${XOSROSTRA_NAME}-$${XOSROSTRA_VERSION}
XOSROSTRA_PKG_DIR = $${XOSROSTRA_NAME}
XOSROSTRA_HOME_BUILD = $${HOME}/build/$${XOSROSTRA_NAME}
XOSROSTRA_HOME_BUILD_INCLUDE = $${XOSROSTRA_HOME_BUILD}/include
XOSROSTRA_HOME_BUILD_LIB = $${XOSROSTRA_HOME_BUILD}/lib
XOSROSTRA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${XOSROSTRA_DIR}
XOSROSTRA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${XOSROSTRA_DIR}
XOSROSTRA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${XOSROSTRA_PKG_DIR}
XOSROSTRA_THIRDPARTY_SRC_GROUP = $${XOSROSTRA_NAME}
XOSROSTRA_THIRDPARTY_SRC_NAME = $${XOSROSTRA_NAME}
XOSROSTRA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${XOSROSTRA_THIRDPARTY_SRC_GROUP}/$${XOSROSTRA_THIRDPARTY_SRC_NAME} 
XOSROSTRA_PKG = $${OTHER_PKG}/$${XOSROSTRA_PKG_DIR}
XOSROSTRA_PRJ = $${OTHER_PRJ}/$${XOSROSTRA_PKG_DIR}
#XOSROSTRA_SRC = $${XOSROSTRA_THIRDPARTY_SRC_DIR}
#XOSROSTRA_SRC = $${XOSROSTRA_THIRDPARTY_PKG}/$${XOSROSTRA_SOURCE}
#XOSROSTRA_SRC = $${XOSROSTRA_THIRDPARTY_PRJ}/$${XOSROSTRA_SOURCE}
XOSROSTRA_SRC = $${XOSROSTRA_PKG}/$${XOSROSTRA_SOURCE}
#XOSROSTRA_SRC = $${XOSROSTRA_PRJ}/$${XOSROSTRA_SOURCE}

ROSTRA_SRC = $${XOSROSTRA_SRC}
XOSROSTRA_LIB_NAME = xos$${XOSROSTRA_NAME}

# xosrostra INCLUDEPATH
#
xosrostra_INCLUDEPATH += \
$${XOSROSTRA_SRC} \

# xosrostra DEFINES
#
xosrostra_DEFINES += \

########################################################################
# xosnadir
XOSNADIR_VERSION_MAJOR = 0
XOSNADIR_VERSION_MINOR = 0
XOSNADIR_VERSION_RELEASE = 0
XOSNADIR_VERSION = $${XOSNADIR_VERSION_MAJOR}.$${XOSNADIR_VERSION_MINOR}.$${XOSNADIR_VERSION_RELEASE}
XOSNADIR_NAME = nadir
XOSNADIR_GROUP = $${XOSNADIR_NAME}
XOSNADIR_SOURCE = src
XOSNADIR_DIR = $${XOSNADIR_GROUP}/$${XOSNADIR_NAME}-$${XOSNADIR_VERSION}
XOSNADIR_PKG_DIR = $${XOSNADIR_NAME}
XOSNADIR_HOME_BUILD = $${HOME}/build/$${XOSNADIR_NAME}
XOSNADIR_HOME_BUILD_INCLUDE = $${XOSNADIR_HOME_BUILD}/include
XOSNADIR_HOME_BUILD_LIB = $${XOSNADIR_HOME_BUILD}/lib
XOSNADIR_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${XOSNADIR_DIR}
XOSNADIR_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${XOSNADIR_DIR}
XOSNADIR_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${XOSNADIR_PKG_DIR}
XOSNADIR_THIRDPARTY_SRC_GROUP = $${XOSNADIR_NAME}
XOSNADIR_THIRDPARTY_SRC_NAME = $${XOSNADIR_NAME}
XOSNADIR_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${XOSNADIR_THIRDPARTY_SRC_GROUP}/$${XOSNADIR_THIRDPARTY_SRC_NAME} 
XOSNADIR_PKG = $${OTHER_PKG}/$${XOSNADIR_PKG_DIR}
XOSNADIR_PRJ = $${OTHER_PRJ}/$${XOSNADIR_PKG_DIR}
#XOSNADIR_SRC = $${XOSNADIR_THIRDPARTY_SRC_DIR}
#XOSNADIR_SRC = $${XOSNADIR_THIRDPARTY_PKG}/$${XOSNADIR_SOURCE}
#XOSNADIR_SRC = $${XOSNADIR_THIRDPARTY_PRJ}/$${XOSNADIR_SOURCE}
XOSNADIR_SRC = $${XOSNADIR_PKG}/$${XOSNADIR_SOURCE}
#XOSNADIR_SRC = $${XOSNADIR_PRJ}/$${XOSNADIR_SOURCE}

NADIR_SRC = $${XOSNADIR_SRC}
XOSNADIR_LIB_NAME = xos$${XOSNADIR_NAME}

# xosnadir INCLUDEPATH
#
xosnadir_INCLUDEPATH += \
$${XOSNADIR_SRC} \

# xosnadir DEFINES
#
xosnadir_DEFINES += \
NO_USE_NADIR_BASE \
NO_USE_XOS_LOGGER_INTERFACE \

########################################################################
# xosrete
XOSRETE_NAME = rete
XOSRETE_SOURCE = src

XOSRETE_PKG = ../../../../..
XOSRETE_BLD = ../..

XOSRETE_PRJ = $${XOSRETE_PKG}
XOSRETE_BIN = $${XOSRETE_BLD}/bin
XOSRETE_LIB = $${XOSRETE_BLD}/lib
XOSRETE_SRC = $${XOSRETE_PKG}/$${XOSRETE_SOURCE}

RETE_SRC = $${XOSRETE_SRC}
XOSRETE_LIB_NAME = xos$${XOSRETE_NAME}

# xosrete BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
xosrete_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
xosrete_DEFINES += RELEASE_BUILD
}

# xosrete INCLUDEPATH
#
xosrete_INCLUDEPATH += \
$${XOSRETE_SRC} \
$${xosnadir_INCLUDEPATH} \
$${xosrostra_INCLUDEPATH} \
$${build_xosrete_INCLUDEPATH} \

# xosrete DEFINES
#
xosrete_DEFINES += \
$${xosrostra_DEFINES} \
$${xosnadir_DEFINES} \
$${build_xosrete_DEFINES} \

# xosrete LIBS
#
xosrete_LIBS += \
-L$${XOSRETE_LIB}/lib$${XOSRETE_LIB_NAME} \
-l$${XOSRETE_LIB_NAME} \
