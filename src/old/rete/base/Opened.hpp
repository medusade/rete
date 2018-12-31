///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: Opened.hpp
///
/// Author: $author$
///   Date: 12/3/2016
///////////////////////////////////////////////////////////////////////
#ifndef _RETE_BASE_OPENED_HPP
#define _RETE_BASE_OPENED_HPP

#include "rete/base/Base.hpp"
#include "patrona/cpp/xos/base/Opened.hpp"

namespace rete {

typedef ::patrona::OpenStatus OpenStatus;
static const OpenStatus OpenSuccess = ::patrona::OpenSuccess;
static const OpenStatus OpenFailed = ::patrona::OpenFailed;
static const OpenStatus CloseSuccess = ::patrona::CloseSuccess;
static const OpenStatus CloseFailed = ::patrona::CloseFailed;

typedef ::patrona::OpenException OpenException;
typedef ::patrona::Opener Opener;

} // namespace rete

#endif // _RETE_BASE_OPENED_HPP 
