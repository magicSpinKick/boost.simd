
//==============================================================================
//         Copyright 2016        Numscale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/simd/acospi.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/pack.hpp>
#include <exhaustive.hpp>

#include <cmath>
#include <cstdlib>

struct raw_acospi
{
  float operator()(float x) const
  {
    return bs::acospi(double(x));
  }
};

int main(int argc, char* argv[])
{
  float mini = bs::Mone<float>(); // acospi is Nan under
  float maxi = bs::One<float>();  // acospi is Nan above
  if(argc >= 2) mini = std::atof(argv[1]);
  if(argc >= 3) maxi = std::atof(argv[2]);
  bs::exhaustive_test<bs::pack<float>> ( mini
                                       , maxi
                                       , bs::acospi
                                       , raw_acospi()
                                       );

  return 0;
}
