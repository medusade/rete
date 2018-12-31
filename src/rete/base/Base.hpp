///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 12/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_BASE_BASE_HPP
#define _RETE_BASE_BASE_HPP

#include "patrona/base/Base.hpp"

namespace rete {

typedef ::patrona::pointer_t pointer_t;
typedef ::patrona::unsigned_t unsigned_t;
typedef ::patrona::signed_t signed_t;

inline const pointer_t& to_pointer(const pointer_t& v) { return v; }
inline const unsigned_t& to_unsigned(const unsigned_t& v) { return v; }
inline const signed_t& to_signed(const signed_t& v) { return v; }
inline const wchar_t& to_wchar(const wchar_t& v) { return v; }
inline const char& to_char(const char& v) { return v; }
inline const bool& to_bool(const bool& v) { return v; }

typedef ::patrona::implement_base ImplementBase;
typedef ::patrona::base Base;

typedef ::patrona::CharArray CharArray;
typedef ::patrona::TCharArray TCharArray;
typedef ::patrona::WCharArray WCharArray;

typedef ::patrona::String String;
typedef ::patrona::TString TString;
typedef ::patrona::WString WString;

typedef ::patrona::CharsToString CharsToString;
typedef ::patrona::CharsToTString CharsToTString;
typedef ::patrona::CharsToWString CharsToWString;

typedef ::patrona::BoolToString BoolToString;
typedef ::patrona::BoolToTString BoolToTString;
typedef ::patrona::BoolToWString BoolToWString;

typedef ::patrona::IntToString IntToString;
typedef ::patrona::IntToTString IntToTString;
typedef ::patrona::IntToWString IntToWString;

typedef ::patrona::SignedToString SignedToString;
typedef ::patrona::SignedToTString SignedToTString;
typedef ::patrona::SignedToWString SignedToWString;

typedef ::patrona::UnsignedToString UnsignedToString;
typedef ::patrona::UnsignedToTString UnsignedToTString;
typedef ::patrona::UnsignedToWString UnsignedToWString;

typedef ::patrona::PointerToString PointerToString;
typedef ::patrona::PointerToTString PointerToTString;
typedef ::patrona::PointerToWString PointerToWString;

} // namespace rete

#endif // _RETE_BASE_BASE_HPP 
