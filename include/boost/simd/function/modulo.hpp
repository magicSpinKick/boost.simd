//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MODULO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MODULO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes modulo value of its parameter.

  **/
  template<typename T> auto modulo(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::modulo

      @see simd::modulo
    **/
    const boost::dispatch::functor<tag::modulo_> modulo = {};
  }
} }
#endif

#include <boost/simd/function/definition/modulo.hpp>
#include <boost/simd/arch/common/scalar/function/modulo.hpp>
//#include <boost/simd/arch/common/function/simd/modulo.hpp>

#endif