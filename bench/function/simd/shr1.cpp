// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/shift_right.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

struct shr1
{
  template < typename T>
  T operator()(const T & a) const
  {
    return bs::shift_right(a, 1);
  }
};


DEFINE_SIMD_BENCH(simd_shr1, shr1());
DEFINE_SCALAR_BENCH(scalar_shr1, shr1());

int main(int argc, char** argv) {
  nsb::parse_args(argc, argv);
  nsb::for_each<simd_shr1, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10);
  nsb::for_each<simd_shr1, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10);
  nsb::for_each<scalar_shr1, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10);
  nsb::for_each<scalar_shr1, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10);
  print_results();
  return 0;
}
