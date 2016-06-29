// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/log1p.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs = boost::simd;

DEFINE_SCALAR_BENCH(scalar_log1p, boost::simd::log1p);
DEFINE_SIMD_BENCH(simd_log1p, boost::simd::log1p);
DEFINE_SIMD_BENCH(std_scalar_log1p, bs::std_(boost::simd::log1p));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_log1p, NS_BENCH_IEEE_TYPES>(-1, 10000);
  nsb::for_each<scalar_log1p, NS_BENCH_IEEE_TYPES>(-1, 10000);
  nsb::for_each<std_scalar_log1p, NS_BENCH_IEEE_TYPES>(-1, 10000);
}
