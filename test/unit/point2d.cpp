// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : yemerge
#include <limits>
#include <stdexcept>

#include "math/utils.hpp"

#include "gtest/gtest.h"

namespace yemerge::geometry {
  TEST(MathUtils, Add) {
  // double type, return lhs + rhs
  // inf, nan, lhs + rhs != inf or lhs + rhs != nan
  // lhs, rhs -> nan, inf => exception std::invalid_argument

  EXPECT_THROW(Add(0.0, std::nan("")), std::invalid_argument);
  EXPECT_THROW(Add(std::nan(""), 0.0), std::invalid_argument);
  EXPECT_THROW(Add(std::nan(""), std::nan("")), std::invalid_argument);
  EXPECT_THROW(Add(0.0, std::numeric_limits<double>::infinity()), std::invalid_argument);
  EXPECT_THROW(Add(std::numeric_limits<double>::infinity(), 0.0), std::invalid_argument);
  EXPECT_THROW(Add(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()), std::invalid_argument);
  EXPECT_THROW(Add(1.0/0.0, 1.0), std::invalid_argument);

  EXPECT_EQ(Add(0.0, 0.0), 0.0);
  EXPECT_EQ(Add(1.0, 0.0), 1.0);
  EXPECT_EQ(Add(0.0, 1.0), 1.0);
  EXPECT_EQ(Add(0.5, 0.5), 1.0);

  EXPECT_NE(Add(0.0, 0.0), 1.0);
  EXPECT_NE(Add(0.0, 1.0), 1.1);
  EXPECT_NE(Add(0.5, 0.3), 1.0);
  EXPECT_NE(Add(0.0, 2.0), 1.0);
  }

  TEST(MathUtils, Subtract) {
  EXPECT_THROW(Subtract(0.0, std::nan("")), std::invalid_argument);
  EXPECT_THROW(Subtract(std::nan(""), 0.0), std::invalid_argument);
  EXPECT_THROW(Subtract(std::nan(""), std::nan("")), std::invalid_argument);
  EXPECT_THROW(Subtract(0.0, std::numeric_limits<double>::infinity()), std::invalid_argument);
  EXPECT_THROW(Subtract(std::numeric_limits<double>::infinity(), 0.0), std::invalid_argument);
  EXPECT_THROW(Subtract(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()), std::invalid_argument);
  EXPECT_THROW(Subtract(1.0/0.0, 1.0), std::invalid_argument);

  EXPECT_EQ(Subtract(1.0, 0.0), 1.0);
  EXPECT_EQ(Subtract(1.0, 1.0), 0.0);
  EXPECT_EQ(Subtract(0.5, 0.3), 0.2);

  EXPECT_NE(Subtract(1.0, 0.0), 0.0);
  EXPECT_NE(Subtract(1.0, 0.5), 1.0);
  EXPECT_NE(Subtract(0.0, 1.0), 1.0);
}

TEST(MathUtils, Multiply) {
  EXPECT_THROW(Multiply(0.0, std::nan("")), std::invalid_argument);
  EXPECT_THROW(Multiply(std::nan(""), 0.0), std::invalid_argument);
  EXPECT_THROW(Multiply(std::nan(""), std::nan("")), std::invalid_argument);
  EXPECT_THROW(Multiply(0.0, std::numeric_limits<double>::infinity()), std::invalid_argument);
  EXPECT_THROW(Multiply(std::numeric_limits<double>::infinity(), 0.0), std::invalid_argument);
  EXPECT_THROW(Multiply(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()), std::invalid_argument);
  EXPECT_THROW(Multiply(1.0/0.0, 1.0), std::invalid_argument);

  EXPECT_EQ(Multiply(1.0, 0.0), 0.0);
  EXPECT_EQ(Multiply(1.0, 1.0), 1.0);
  EXPECT_EQ(Multiply(2.0, 3.0), 6.0);

  EXPECT_NE(Multiply(1.0, 1.0), 0.0);
  EXPECT_NE(Multiply(2.0, 2.0), 5.0);
  EXPECT_NE(Multiply(0.0, 1.0), 1.0);
}

TEST(MathUtils, Divide) {
  EXPECT_THROW(Divide(0.0, std::nan("")), std::invalid_argument);
  EXPECT_THROW(Divide(std::nan(""), 0.0), std::invalid_argument);
  EXPECT_THROW(Divide(std::nan(""), std::nan("")), std::invalid_argument);
  EXPECT_THROW(Divide(0.0, std::numeric_limits<double>::infinity()), std::invalid_argument);
  EXPECT_THROW(Divide(std::numeric_limits<double>::infinity(), 0.0), std::invalid_argument);
  EXPECT_THROW(Divide(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()), std::invalid_argument);
  EXPECT_THROW(Divide(1.0, 0.0), std::invalid_argument);
  EXPECT_THROW(Divide(1.0/0.0, 1.0), std::invalid_argument);

  EXPECT_EQ(Divide(1.0, 1.0), 1.0);
  EXPECT_EQ(Divide(4.0, 2.0), 2.0);
  EXPECT_EQ(Divide(6.0, 3.0), 2.0);

  EXPECT_NE(Divide(1.0, 1.0), 0.0);
  EXPECT_NE(Divide(4.0, 4.0), 0.5);
  EXPECT_NE(Divide(0.0, 1.0), 1.0);
}

  // TEST(MathUtils, IsEqual) {
  //   // EXPECT_TRUE(IsEqual(double lhs, double rhs));
  //   EXPECT_TRUE(IsEqual(0.00005+0.00005, 0.0001));  // When it is a floating type, it may not come out as true.
  // }
}
