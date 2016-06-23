// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/log.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
DEFINE_SIMD_BENCH(simd_log, bs::log);
DEFINE_SCALAR_BENCH(scalar_log, bs::log);
DEFINE_SCALAR_BENCH(scalar_std_log, bs::std_(bs::log));

int main(int argc, char** argv) {
  nsb::parse_args(argc, argv);
  nsb::for_each<simd_log, NS_BENCH_IEEE_TYPES>(0, 10000);
  nsb::for_each<scalar_log, NS_BENCH_IEEE_TYPES>(0, 10000);
  nsb::for_each<scalar_std_log, NS_BENCH_IEEE_TYPES>(0, 10000);
  print_results();
  return 0;
}
