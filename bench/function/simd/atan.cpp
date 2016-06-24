// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/atan.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
DEFINE_SIMD_BENCH(simd_atan, boost::simd::atan);
DEFINE_SCALAR_BENCH(scalar_atan, boost::simd::atan);
DEFINE_SCALAR_BENCH(std_scalar_atan, bs::std_(boost::simd::atan));

int main(int argc, char** argv) {
  nsb::parse_args(argc, argv);
  nsb::for_each<simd_atan, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<scalar_atan, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<std_scalar_atan, NS_BENCH_IEEE_TYPES>(-10, 10);
  print_results();
  return 0;
}
