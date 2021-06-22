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
# QtCreator .pri file for xosrete executable xosrete
########################################################################

########################################################################
# xosrete

# xosrete_exe TARGET
#
xosrete_exe_TARGET = xosrete

# xosrete_exe INCLUDEPATH
#
xosrete_exe_INCLUDEPATH += \
$${xosrete_INCLUDEPATH} \

# xosrete_exe DEFINES
#
xosrete_exe_DEFINES += \
$${xosrete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_RETE_HELLO_MAIN_INSTANCE \

########################################################################
# xosrete_exe OBJECTIVE_HEADERS
#
#xosrete_exe_OBJECTIVE_HEADERS += \
#$${XOSRETE_SRC}/xos/app/console/xosrete/main.hh \

# xosrete_exe OBJECTIVE_SOURCES
#
#xosrete_exe_OBJECTIVE_SOURCES += \
#$${XOSRETE_SRC}/xos/app/console/xosrete/main.mm \

########################################################################
# xosrete_exe HEADERS
#
xosrete_exe_HEADERS += \
$${NADIR_SRC}/xos/console/lib/version/main_opt.hpp \
$${NADIR_SRC}/xos/console/lib/version/main.hpp \
\
$${NADIR_SRC}/xos/app/console/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/main.hpp \
\
$${NADIR_SRC}/xos/app/console/lib/version/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/lib/version/main.hpp \
\
$${RETE_SRC}/xos/app/console/rete/main_opt.hpp \
$${RETE_SRC}/xos/app/console/rete/main.hpp \
\
$${RETE_SRC}/xos/app/console/rete/hello/message.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/request.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/response.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/signaler.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/processor.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/tcp/connections.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/tcp/processor.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/tcp/service.hpp \
\
$${RETE_SRC}/xos/app/console/rete/hello/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/base/main.hpp \
\
$${RETE_SRC}/xos/app/console/rete/hello/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/client/main.hpp \
\
$${RETE_SRC}/xos/app/console/rete/hello/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/server/main.hpp \
\
$${RETE_SRC}/xos/app/console/rete/hello/main_opt.hpp \
$${RETE_SRC}/xos/app/console/rete/hello/main.hpp \
\
$${NADIR_SRC}/xos/base/main_main.hpp \

# xosrete_exe SOURCES
#
xosrete_exe_SOURCES += \
$${RETE_SRC}/xos/app/console/rete/hello/message.cpp \
$${RETE_SRC}/xos/app/console/rete/hello/request.cpp \
$${RETE_SRC}/xos/app/console/rete/hello/response.cpp \
$${RETE_SRC}/xos/app/console/rete/hello/signaler.cpp \
$${RETE_SRC}/xos/app/console/rete/hello/tcp/connections.cpp \
$${RETE_SRC}/xos/app/console/rete/hello/tcp/processor.cpp \
$${RETE_SRC}/xos/app/console/rete/hello/tcp/service.cpp \
\
$${RETE_SRC}/xos/app/console/rete/hello/main_opt.cpp \
$${RETE_SRC}/xos/app/console/rete/hello/main.cpp \
\
$${NADIR_SRC}/xos/base/main_main.cpp \

########################################################################
# xosrete_exe FRAMEWORKS
#
xosrete_exe_FRAMEWORKS += \
$${xosrete_FRAMEWORKS} \

# xosrete_exe LIBS
#
xosrete_exe_LIBS += \
$${xosrete_LIBS} \


