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
# generic Gcc Makefile for rete
########################################################################

OTHER_VERSION_PKG = ${PKG}
OTHER_DEPENDS_PKG = ${PKG}/..
OTHER_THIRDPARTY_NAME = thirdparty
OTHER_THIRDPARTY_VERSION_PKG = ${OTHER_VERSION_PKG}/${OTHER_THIRDPARTY_NAME}

RETE_PKG = ${PKG}
RETE_SRC = ${RETE_PKG}/src
RETE_BLD = ${RETE_PKG}/${BLD}/${BUILD_TYPE}
RETE_LIB = ${RETE_BLD}/lib
RETE_BIN = ${RETE_BLD}/bin

########################################################################
# rostra
ROSTRA_VERSION_MAJOR = 0
ROSTRA_VERSION_MINOR = 0
ROSTRA_VERSION_RELEASE = 0
ROSTRA_VERSION = ${ROSTRA_VERSION_MAJOR}.${ROSTRA_VERSION_MINOR}.${ROSTRA_VERSION_RELEASE}
ROSTRA_NAME = rostra
ROSTRA_GROUP = ${ROSTRA_NAME}
ROSTRA_VERSION_DIR = ${ROSTRA_GROUP}/${ROSTRA_NAME}-${ROSTRA_VERSION}
ROSTRA_DEPENDS_DIR = ${ROSTRA_NAME}

#ROSTRA_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${ROSTRA_VERSION_DIR}
#ROSTRA_PKG = ${OTHER_VERSION_PKG}/${ROSTRA_VERSION_DIR}
ROSTRA_PKG = ${OTHER_DEPENDS_PKG}/${ROSTRA_DEPENDS_DIR}
#ROSTRA_SRC = ${ROSTRA_PKG}/src/${BN_GROUP}/${BN_NAME}
ROSTRA_SRC = ${ROSTRA_PKG}/src
ROSTRA_BLD = ${ROSTRA_PKG}/${BLD}/${BUILD_TYPE}
ROSTRA_LIB = ${ROSTRA_BLD}/lib
ROSTRA_BIN = ${ROSTRA_BLD}/bin

# rostra USRDEFINES
#
rostra_USRDEFINES += \

# rostra USRINCLUDES
#
rostra_USRINCLUDES += \
-I${ROSTRA_SRC} \

# rostra USRCXXFLAGS
#
rostra_USRCXXFLAGS += \

# rostra USRLIBDIRS
#
rostra_USRLIBDIRS += \
-L${ROSTRA_LIB} \

# rostra LIBS
#
rostra_LIBS += \
-lrostra \

# rostra FRAMEWORKS
#
rostra_FRAMEWORKS += \

########################################################################
# nadir
NADIR_VERSION_MAJOR = 0
NADIR_VERSION_MINOR = 0
NADIR_VERSION_RELEASE = 0
NADIR_VERSION = ${NADIR_VERSION_MAJOR}.${NADIR_VERSION_MINOR}.${NADIR_VERSION_RELEASE}
NADIR_NAME = nadir
NADIR_GROUP = ${NADIR_NAME}
NADIR_VERSION_DIR = ${NADIR_GROUP}/${NADIR_NAME}-${NADIR_VERSION}
NADIR_DEPENDS_DIR = ${NADIR_NAME}

#NADIR_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${NADIR_VERSION_DIR}
#NADIR_PKG = ${OTHER_VERSION_PKG}/${NADIR_VERSION_DIR}
NADIR_PKG = ${OTHER_DEPENDS_PKG}/${NADIR_DEPENDS_DIR}
#NADIR_SRC = ${NADIR_PKG}/src/${BN_GROUP}/${BN_NAME}
NADIR_SRC = ${NADIR_PKG}/src
NADIR_BLD = ${NADIR_PKG}/${BLD}/${BUILD_TYPE}
NADIR_LIB = ${NADIR_BLD}/lib
NADIR_BIN = ${NADIR_BLD}/bin

# nadir USRDEFINES
#
nadir_USRDEFINES += \

# nadir USRINCLUDES
#
nadir_USRINCLUDES += \
-I${NADIR_SRC} \

# nadir USRCXXFLAGS
#
nadir_USRCXXFLAGS += \

# nadir USRLIBDIRS
#
nadir_USRLIBDIRS += \
-L${NADIR_LIB} \

# nadir LIBS
#
nadir_LIBS += \
-lnadir \

# nadir FRAMEWORKS
#
nadir_FRAMEWORKS += \

########################################################################
# patrona
PATRONA_VERSION_MAJOR = 0
PATRONA_VERSION_MINOR = 0
PATRONA_VERSION_RELEASE = 0
PATRONA_VERSION = ${PATRONA_VERSION_MAJOR}.${PATRONA_VERSION_MINOR}.${PATRONA_VERSION_RELEASE}
PATRONA_NAME = patrona
PATRONA_GROUP = ${PATRONA_NAME}
PATRONA_VERSION_DIR = ${PATRONA_GROUP}/${PATRONA_NAME}-${PATRONA_VERSION}
PATRONA_DEPENDS_DIR = ${PATRONA_NAME}

#PATRONA_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${PATRONA_VERSION_DIR}
#PATRONA_PKG = ${OTHER_VERSION_PKG}/${PATRONA_VERSION_DIR}
PATRONA_PKG = ${OTHER_DEPENDS_PKG}/${PATRONA_DEPENDS_DIR}
#PATRONA_SRC = ${PATRONA_PKG}/src/${BN_GROUP}/${BN_NAME}
PATRONA_SRC = ${PATRONA_PKG}/src
PATRONA_BLD = ${PATRONA_PKG}/${BLD}/${BUILD_TYPE}
PATRONA_LIB = ${PATRONA_BLD}/lib
PATRONA_BIN = ${PATRONA_BLD}/bin

# patrona USRDEFINES
#
patrona_USRDEFINES += \

# patrona USRINCLUDES
#
patrona_USRINCLUDES += \
-I${PATRONA_SRC} \

# patrona USRCXXFLAGS
#
patrona_USRCXXFLAGS += \

# patrona USRLIBDIRS
#
patrona_USRLIBDIRS += \
-L${PATRONA_LIB} \

# patrona LIBS
#
patrona_LIBS += \
-lpatrona \

# patrona FRAMEWORKS
#
patrona_FRAMEWORKS += \

########################################################################
# crono
CRONO_VERSION_MAJOR = 0
CRONO_VERSION_MINOR = 0
CRONO_VERSION_RELEASE = 0
CRONO_VERSION = ${CRONO_VERSION_MAJOR}.${CRONO_VERSION_MINOR}.${CRONO_VERSION_RELEASE}
CRONO_NAME = crono
CRONO_GROUP = ${CRONO_NAME}
CRONO_VERSION_DIR = ${CRONO_GROUP}/${CRONO_NAME}-${CRONO_VERSION}
CRONO_DEPENDS_DIR = ${CRONO_NAME}

#CRONO_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${CRONO_VERSION_DIR}
#CRONO_PKG = ${OTHER_VERSION_PKG}/${CRONO_VERSION_DIR}
CRONO_PKG = ${OTHER_DEPENDS_PKG}/${CRONO_DEPENDS_DIR}
#CRONO_SRC = ${CRONO_PKG}/src/${BN_GROUP}/${BN_NAME}
CRONO_SRC = ${CRONO_PKG}/src
CRONO_BLD = ${CRONO_PKG}/${BLD}/${BUILD_TYPE}
CRONO_LIB = ${CRONO_BLD}/lib
CRONO_BIN = ${CRONO_BLD}/bin

# crono USRDEFINES
#
crono_USRDEFINES += \

# crono USRINCLUDES
#
crono_USRINCLUDES += \
-I${CRONO_SRC} \

# crono USRCXXFLAGS
#
crono_USRCXXFLAGS += \

# crono USRLIBDIRS
#
crono_USRLIBDIRS += \
-L${CRONO_LIB} \

# crono LIBS
#
crono_LIBS += \
-lcrono \

# crono FRAMEWORKS
#
crono_FRAMEWORKS += \

########################################################################
# fila
FILA_VERSION_MAJOR = 0
FILA_VERSION_MINOR = 0
FILA_VERSION_RELEASE = 0
FILA_VERSION = ${FILA_VERSION_MAJOR}.${FILA_VERSION_MINOR}.${FILA_VERSION_RELEASE}
FILA_NAME = fila
FILA_GROUP = ${FILA_NAME}
FILA_VERSION_DIR = ${FILA_GROUP}/${FILA_NAME}-${FILA_VERSION}
FILA_DEPENDS_DIR = ${FILA_NAME}

#FILA_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${FILA_VERSION_DIR}
#FILA_PKG = ${OTHER_VERSION_PKG}/${FILA_VERSION_DIR}
FILA_PKG = ${OTHER_DEPENDS_PKG}/${FILA_DEPENDS_DIR}
#FILA_SRC = ${FILA_PKG}/src/${BN_GROUP}/${BN_NAME}
FILA_SRC = ${FILA_PKG}/src
FILA_BLD = ${FILA_PKG}/${BLD}/${BUILD_TYPE}
FILA_LIB = ${FILA_BLD}/lib
FILA_BIN = ${FILA_BLD}/bin

# fila USRDEFINES
#
fila_USRDEFINES += \

# fila USRINCLUDES
#
fila_USRINCLUDES += \
-I${FILA_SRC} \

# fila USRCXXFLAGS
#
fila_USRCXXFLAGS += \

# fila USRLIBDIRS
#
fila_USRLIBDIRS += \
-L${FILA_LIB} \

# fila LIBS
#
fila_LIBS += \
-lfila \

# fila FRAMEWORKS
#
fila_FRAMEWORKS += \


########################################################################
# rete

# rete USRDEFINES
#
rete_USRDEFINES += \
${rostra_USRDEFINES} \
${nadir_USRDEFINES} \
${patrona_USRDEFINES} \
${crono_USRDEFINES} \
${fila_USRDEFINES} \
${build_rete_USRDEFINES} \

# rete USRINCLUDES
#
rete_USRINCLUDES += \
-I${RETE_SRC} \
${fila_USRINCLUDES} \
${crono_USRINCLUDES} \
${patrona_USRINCLUDES} \
${nadir_USRINCLUDES} \
${rostra_USRINCLUDES} \
${build_rete_USRINCLUDES} \

# rete USRCXXFLAGS
#
rete_USRCXXFLAGS += \
${rostra_USRCXXFLAGS} \
${nadir_USRCXXFLAGS} \
${patrona_USRCXXFLAGS} \
${crono_USRCXXFLAGS} \
${fila_USRCXXFLAGS} \
${build_rete_USRCXXFLAGS} \

# rete USRLIBDIRS
#
rete_USRLIBDIRS += \
-L${RETE_LIB} \
${fila_USRLIBDIRS} \
${crono_USRLIBDIRS} \
${patrona_USRLIBDIRS} \
${nadir_USRLIBDIRS} \
${rostra_USRLIBDIRS} \
${build_rete_USRLIBDIRS} \

# rete LIBS
#
rete_LIBS += \
-lrete \
${fila_LIBS} \
${crono_LIBS} \
${patrona_LIBS} \
${nadir_LIBS} \
${rostra_LIBS} \
${build_rete_LIBS} \

########################################################################

