///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: base.hpp
///
/// Author: $author$
///   Date: 5/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_NADIR_BASE_BASE_HPP
#define _RETE_NADIR_BASE_BASE_HPP

#include "nadir/base/base.hpp"
#include "nadir/base/created.hpp"
#include "nadir/base/opened.hpp"
#include "nadir/base/attached.hpp"
#include "nadir/base/chars.hpp"
#include "nadir/base/array.hpp"
#include "nadir/base/string.hpp"
#include "nadir/base/to_string.hpp"

namespace rete {

typedef nadir::implement_base implement_base;
typedef nadir::base base;

typedef nadir::chars_t chars_t;
typedef nadir::tchars_t tchars_t;
typedef nadir::wchars_t wchars_t;

typedef nadir::char_array char_array;
typedef nadir::tchar_array tchar_array;
typedef nadir::wchar_array wchar_array;

typedef nadir::char_string char_string;
typedef nadir::tchar_string tchar_string;
typedef nadir::wchar_string wchar_string;

typedef nadir::chars_to_string chars_to_string;
typedef nadir::chars_to_tstring chars_to_tstring;
typedef nadir::chars_to_wstring chars_to_wstring;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef nadir::attach_status attach_status;
typedef nadir::attach_exception attach_exception;
const nadir::attach_status
    detach_success = nadir::detach_success,
    attach_success = nadir::attach_success,
    attach_failed = nadir::attach_failed,
    detach_failed = nadir::detach_failed;

} // namespace rete

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef nadir::opener opener;
typedef nadir::open_exception open_exception;
typedef nadir::open_status open_status;
const nadir::open_status
    close_success = nadir::close_success,
    open_success = nadir::open_success,
    open_failed = nadir::open_failed,
    close_failed = nadir::close_failed;

#endif // _RETE_NADIR_BASE_BASE_HPP
