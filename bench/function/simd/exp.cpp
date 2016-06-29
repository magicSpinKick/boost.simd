// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/exp.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs = boost::simd;

DEFINE_SCALAR_BENCH(scalar_exp, boost::simd::exp);
DEFINE_SIMD_BENCH(simd_exp, boost::simd::exp);
DEFINE_SIMD_BENCH(std_scalar_exp, bs::std_(boost::simd::exp));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_exp, NS_BENCH_IEEE_TYPES>(-10,10);
  nsb::for_each<scalar_exp, NS_BENCH_IEEE_TYPES>(-10,10);
  nsb::for_each<std_scalar_exp, NS_BENCH_IEEE_TYPES>(-10,10);
}
