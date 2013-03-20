/*
 *  Copyright (C) 2012  Elvis M. Teixeira
 * 
 *  The Q Scientific Library is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  The Q Scientific Library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


#ifndef QSL_GLOBAL_H
#define QSL_GLOBAL_H

#include <QtCore/QtGlobal>
#ifndef QSL_NO_DEBUG
#  include <QtCore/QDebug>
#endif


#define _QSL_
#define QSL_VERSION 0.1
#define QSL_VERSION_STRING "0.1.0"


#if defined (QSL_COMPILE_LIB)
#  define QSL_LIB_DECL Q_DECL_EXPORT
#elif defined (QSL_USE_LIB)
#  define QSL_LIB_DECL Q_DECL_IMPORT
#else
#  define QSL_LIB_DECL
#endif


typedef qint32 qint;
typedef quint32 quint;


#endif //QSL_GLOBAL_H