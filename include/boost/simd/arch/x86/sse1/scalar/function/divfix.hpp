//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SCALAR_FUNCTION_DIVFIX_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SCALAR_FUNCTION_DIVFIX_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/div.hpp>
#include <boost/simd/function/simd/fix.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::fix_
                          , bd::scalar_<bd::single_<T>>
                          , bd::scalar_<bd::single_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(bd::functor<bs::tag::fix_> const&, T a0, T a1) const BOOST_NOEXCEPT
    {
      float r;
      bs::pack<T> tmp0 = _mm_load_ss( &a0 );
      bs::pack<T> tmp1 = _mm_load_ss( &a1 );
      _mm_store_ss( &r, bs::div(bs::fix, tmp0, tmp1) );
      return r;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::fix_
                          , bd::scalar_<bd::double_<T>>
                          , bd::scalar_<bd::double_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(bd::functor<bs::tag::fix_> const&, T a0, T a1) const BOOST_NOEXCEPT
    {
      double r;
      bs::pack<T> tmp0 = _mm_load_sd( &a0 );
      bs::pack<T> tmp1 = _mm_load_sd( &a1 );
      _mm_store_sd( &r, bs::div(bs::fix, tmp0, tmp1) );
      return r;
    }
  };

} } }

#endif
