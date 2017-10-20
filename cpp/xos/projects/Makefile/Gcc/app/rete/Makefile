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
# generic Gcc Makefile for rete Executable rete
########################################################################


#
# target
#
rete_exe_EXETARGET = rete

########################################################################

#
# user c++ flags
#
rete_exe_USRCXXFLAGS += \
${rete_USRCXXFLAGS} \

#
# user defines
#
rete_exe_USRDEFINES += \
${rete_USRDEFINES} \
-DXOS_APP_CONSOLE_RETE_THE_MAIN \

#
# user includes
#
rete_exe_USRINCLUDES += \
${rete_USRINCLUDES} \

#
# user libdirs
#
rete_exe_USRLIBDIRS += \
${rete_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#rete_exe_EXE_C_SOURCES += \
#${RETE_SRC}/rete/base/Base.c \

#
# Executable .cc sources
#
#rete_exe_EXE_CC_SOURCES += \
#${RETE_SRC}/rete/base/Base.cc \

#
# Executable .cxx sources
#
#rete_exe_EXE_CXX_SOURCES += \
#${RETE_SRC}/rete/base/Base.cxx \

#
# Executable .cpp sources
#
rete_exe_EXE_CPP_SOURCES += \
${FILA_SRC}/xos/console/mt/Main_main.cpp \
${RETE_SRC}/xos/app/console/rete/Main.cpp \
${RETE_SRC}/xos/app/console/rete/MainOpt.cpp \

#
# Executable .m sources
#
#rete_exe_EXE_M_SOURCES += \
#${RETE_SRC}/rete/base/Base.m \

#
# Executable .mm sources
#
#rete_exe_EXE_MM_SOURCES += \
#${RETE_SRC}/rete/base/Base.mm \


########################################################################

#
# Executable libraries
#
rete_exe_LIBS += \
${rete_LIBS}



