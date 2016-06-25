//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_INDEG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_INDEG_HPP_INCLUDED

#include <boost/simd/constant/radindeg.hpp>
#include <boost/simd/constant/radindegr.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( indeg_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    A0 operator() ( A0 const& a0) const
    {
      A0 z = a0*Radindegr<A0>();
      return fms(a0, Radindeg<A0>(), z);
    }
  };
} } }


#endif
