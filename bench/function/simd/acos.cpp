// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/acos.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
//#define LIST float
//#define LIST double
#define LIST NS_BENCH_IEEE_TYPES

DEFINE_SIMD_BENCH(simd_acos, boost::simd::acos);
DEFINE_SCALAR_BENCH(scalar_acos, boost::simd::acos);
DEFINE_SCALAR_BENCH(std_scalar_acos, bs::std_(boost::simd::acos));
DEFINE_SIMD_BENCH(fast_simd_acos, bs::fast_(boost::simd::acos));
DEFINE_SCALAR_BENCH(fast_scalar_acos, bs::fast_(boost::simd::acos));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<fast_scalar_acos, LIST>(-1, 1);
  nsb::for_each<std_scalar_acos, LIST>(-1, 1);
  nsb::for_each<scalar_acos, LIST>(-1, 1);
  nsb::for_each<fast_simd_acos, LIST>(-1, 1);
  nsb::for_each<simd_acos, LIST>(-1, 1);
}
