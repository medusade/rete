########################################################################
# Copyright (c) 1988-2017 $organization$
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
#   Date: 10/11/2017
#
# generic Gcc Makefile for rete
########################################################################


RETE_PKG = ${PKG}
RETE_SRC = ${RETE_PKG}/src
RETE_BLD = ${RETE_PKG}/${BLD}/${BUILD_TYPE}
RETE_LIB = ${RETE_BLD}/lib
RETE_BIN = ${RETE_BLD}/bin

########################################################################
# rostra
ROSTRA_PKG = ${RETE_PKG}/../../../rostra/cpp/xos
ROSTRA_SRC = ${ROSTRA_PKG}/src
ROSTRA_BLD = ${ROSTRA_PKG}/${BLD}/${BUILD_TYPE}
ROSTRA_LIB = ${ROSTRA_BLD}/lib
ROSTRA_BIN = ${ROSTRA_BLD}/bin

########################################################################
# nadir
NADIR_PKG = ${RETE_PKG}/../../../nadir/cpp/xos
NADIR_SRC = ${NADIR_PKG}/src
NADIR_BLD = ${NADIR_PKG}/${BLD}/${BUILD_TYPE}
NADIR_LIB = ${NADIR_BLD}/lib
NADIR_BIN = ${NADIR_BLD}/bin

########################################################################
# patrona
PATRONA_PKG = ${RETE_PKG}/../../../patrona/cpp/xos
PATRONA_SRC = ${PATRONA_PKG}/src
PATRONA_BLD = ${PATRONA_PKG}/${BLD}/${BUILD_TYPE}
PATRONA_LIB = ${PATRONA_BLD}/lib
PATRONA_BIN = ${PATRONA_BLD}/bin

########################################################################
# crono
CRONO_PKG = ${RETE_PKG}/../../../crono/cpp/xos
CRONO_SRC = ${CRONO_PKG}/src
CRONO_BLD = ${CRONO_PKG}/${BLD}/${BUILD_TYPE}
CRONO_LIB = ${CRONO_BLD}/lib
CRONO_BIN = ${CRONO_BLD}/bin

########################################################################
# fila
FILA_PKG = ${RETE_PKG}/../../../fila/cpp/xos
FILA_SRC = ${FILA_PKG}/src
FILA_BLD = ${FILA_PKG}/${BLD}/${BUILD_TYPE}
FILA_LIB = ${FILA_BLD}/lib
FILA_BIN = ${FILA_BLD}/bin


########################################################################
# rete
rete_USRDEFINES += \
${build_rete_USRDEFINES} \

rete_USRINCLUDES += \
-I${RETE_SRC} \
-I${FILA_SRC} \
-I${CRONO_SRC} \
-I${PATRONA_SRC} \
-I${NADIR_SRC} \
-I${ROSTRA_SRC} \
${build_rete_USRINCLUDES} \

rete_USRCXXFLAGS += \
${build_rete_USRCXXFLAGS} \

rete_USRLIBDIRS += \
-L${RETE_LIB} \
-L${FILA_LIB} \
-L${CRONO_LIB} \
-L${PATRONA_LIB} \
-L${NADIR_LIB} \
-L${ROSTRA_LIB} \
${build_rete_USRLIBDIRS} \

rete_LIBS += \
-lrete \
-lfila \
-lcrono \
-lnadir \
${build_rete_LIBS} \

########################################################################

