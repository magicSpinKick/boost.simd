// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accomparging file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/arg.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

struct uarg
{
  template < typename T>
  T operator()(const T & a)
  {
    return bs::arg(bs::use_signbit_, a);
  }
};

DEFINE_SIMD_BENCH(simd_arg, boost::simd::arg);
DEFINE_SCALAR_BENCH(scalar_arg, boost::simd::arg);
DEFINE_SIMD_BENCH(usimd_arg, boost::simd::arg);
DEFINE_SCALAR_BENCH(uscalar_arg, boost::simd::arg);

int main(int argc, char** argv) {
  nsb::parse_args(argc, argv);
  nsb::for_each<simd_arg, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<scalar_arg, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<usimd_arg, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<uscalar_arg, NS_BENCH_IEEE_TYPES>(-10, 10);
  print_results();
  return 0;

}
