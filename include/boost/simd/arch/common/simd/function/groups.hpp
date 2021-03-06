//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GROUPS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GROUPS_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/saturate.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/detail/dispatch/meta/downgrade.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF( group_
                            , (typename A0, typename X)
                            , (bd::is_downgradable<A0>)
                            , bd::cpu_
                            , bs::saturated_tag
                            , bs::pack_<bd::arithmetic_<A0>, X>
                            , bs::pack_<bd::arithmetic_<A0>, X>
                            )
  {
    using result = bd::downgrade_t<A0>;

    BOOST_FORCEINLINE result
    operator()(const saturated_tag&, const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      return group(saturate<result>(a0), saturate<result>(a1));
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF( group_
                            , (typename A0, typename X)
                            , (bd::is_downgradable<A0>)
                            , bd::cpu_
                            , bs::saturated_tag
                            , bs::pack_<bd::floating_<A0>, X>
                            , bs::pack_<bd::floating_<A0>, X>
                            )
  {
    BOOST_FORCEINLINE bd::downgrade_t<A0>
    operator()(const saturated_tag&, const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      return group(a0, a1);
    }
  };
} } }

#endif
