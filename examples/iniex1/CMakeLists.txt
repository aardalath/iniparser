#=============================================================================
# CMakeLists.txt
# examples/simple
#
# Copyright (C) 2011-2013, J C Gonzalez
#
# This file is part of DPF v. 0.1 
# 
# DPF is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your
# option) any later version.
# 
# DPF is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
# License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with DPF.  If not, see <http://www.gnu.org/licenses/>
#=============================================================================

INCLUDE_DIRECTORIES(. ${INIPARSER_SOURCE_DIR}/src)
LINK_DIRECTORIES(${INIPARSER_BINARY_DIR}/src)

ADD_EXECUTABLE(iniex1 main.cpp)

TARGET_LINK_LIBRARIES(iniex1 iniparser)
