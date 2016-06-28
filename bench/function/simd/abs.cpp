// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
DEFINE_SIMD_BENCH(simd_abs, boost::simd::abs);
DEFINE_SCALAR_BENCH(scalar_abs, boost::simd::abs);
DEFINE_SIMD_BENCH(saturated_simd_abs, bs::saturated_(boost::simd::abs));
DEFINE_SCALAR_BENCH(saturated_scalar_abs, bs::saturated_(boost::simd::abs));
DEFINE_SIMD_BENCH(std_simd_abs, bs::std_(boost::simd::abs));
DEFINE_SCALAR_BENCH(std_scalar_abs, bs::std_(boost::simd::abs));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_abs, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10);
  nsb::for_each<simd_abs, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10);
  nsb::for_each<scalar_abs, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10);
  nsb::for_each<scalar_abs, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10);

  nsb::for_each<saturated_simd_abs, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10);
  nsb::for_each<saturated_simd_abs, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10);
  nsb::for_each<saturated_scalar_abs, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10);
  nsb::for_each<saturated_scalar_abs, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10);

  nsb::for_each<std_simd_abs, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10);
  nsb::for_each<std_simd_abs, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10);
  nsb::for_each<std_scalar_abs, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10);
  nsb::for_each<std_scalar_abs, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10);
}
