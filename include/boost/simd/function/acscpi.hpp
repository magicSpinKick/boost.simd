//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSCPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSCPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing acscpi capabilities

     inverse secant in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acscpi(x);
    @endcode

    is similar to:

    @code
    T r =  asinpi(rec(x));;
    @endcode

    @see asec, asecd

  **/
  Value acscpi(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/acscpi.hpp>
#include <boost/simd/function/simd/acscpi.hpp>

#endif
