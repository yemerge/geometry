// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : yemerge

#include "geometry/distance.hpp"

#include "gtest/gtest.h"

namespace {
constexpr uint32_t kTestCount = 1000U;
}

namespace yemerge::geometry {
TEST(GeometryDistance, Constructor) {
  Distance distance1;
  Distance distance2(distance1);
  Distance distance3(std::move(Distance()));
}

TEST(GeometryDistance, ConstructorWithInputValue) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    Distance distance1(static_cast<double>(std::rand()));
    Distance distance2(static_cast<double>(std::rand()),
                       Distance::Type::kKilometer);
    Distance distance3(static_cast<double>(std::rand()),
                       Distance::Type::kMeter);
    Distance distance4(static_cast<double>(std::rand()),
                       Distance::Type::kCentimeter);
    Distance distance5(static_cast<double>(std::rand()),
                       Distance::Type::kMillimeter);
    Distance distance6(static_cast<double>(std::rand()),
                       Distance::Type::kMicrometer);
    Distance distance7(static_cast<double>(std::rand()),
                       Distance::Type::kNanometer);
  }
}

TEST(GeometryDistance, AssignmentOperator) {
  Distance distance1;
  auto distance2 = distance1;
  auto pistance3 = std::move(Distance());
}

TEST(GeometryDistance, GetValue) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance1(KInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2(KInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(KInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3(KInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4(KInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5(KInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6(KInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance6.GetValue(Distance::Type::kNanometer));

  // for (uint32_t i = 0; i < kTestCount; ++i)
  // {
  //   const auto kInputValue = static_cast<double>(std::rand());
  //   Distance distance1(static_cast<double>(kInputValue),
  //   Distance::Type::kKilometer); Distance
  //   distance2(static_cast<double>(kInputValue), Distance::Type::kMeter);
  //   Distance distance3(static_cast<double>(kInputValue),
  //   Distance::Type::kCentimeter); Distance
  //   distance4(static_cast<double>(kInputValue), Distance::Type::kMillimeter);
  //   Distance distance5(static_cast<double>(kInputValue),
  //   Distance::Type::kMicrometer); Distance
  //   distance6(static_cast<double>(kInputValue), Distance::Type::kNanometer);
  // 1.222 (nanometer input) -> nanometer value is 1. When we get nanometer as
  // get, the output is 1.0.
  // }
}

TEST(GeometryDistance, SetValue) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance1;
  distance1.SetValue(KInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2;
  distance2.SetValue(KInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(KInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3;
  distance3.SetValue(KInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4;
  distance4.SetValue(KInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5;
  distance5.SetValue(KInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6;
  distance6.SetValue(KInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance6.GetValue(Distance::Type::kNanometer));
}

TEST(GeometryDistance, OperatorEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo == distance);
  EXPECT_TRUE(distance_by_kilo == distance_by_nano);
  EXPECT_TRUE(distance == distance_by_nano);
  // Distance distance1;
  // Distance distance2;
  // EXPECT_TRUE(distance1 == distance2);

  // Distance distance3(static_cast<double>(std::rand()));
  // Distance distance4(distance3);
  // EXPECT_TRUE(distance1 == distance2);

  // Distance distance5(static_cast<double>(std::rand()));
  // Distance distance6(distance5);
  // EXPECT_TRUE(distance5 == distance6);
}

TEST(GeometryDistance, OperatorNotEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  Distance different_distance(2039.0, Distance::Type::kKilometer);

  EXPECT_FALSE(distance_by_kilo != distance);
  EXPECT_FALSE(distance_by_kilo != distance_by_nano);
  EXPECT_FALSE(distance != distance_by_nano);
  EXPECT_TRUE(distance_by_kilo != different_distance);
}

TEST(GeometryDistance, OperatorLessThan) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance smaller_distance(KInputValue - 1.0, Distance::Type::kKilometer);

  EXPECT_TRUE(smaller_distance < distance_by_kilo);
  EXPECT_FALSE(distance_by_kilo < smaller_distance);
}

TEST(GeometryDistance, OperatorLessThanOrEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance same_distance(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance smaller_distance(KInputValue - 1.0, Distance::Type::kKilometer);

  EXPECT_TRUE(smaller_distance <= distance_by_kilo);
  EXPECT_TRUE(distance_by_kilo <= same_distance);
  EXPECT_FALSE(distance_by_kilo <= smaller_distance);
}

TEST(GeometryDistance, OperatorGreaterThan) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance larger_distance(KInputValue + 1.0, Distance::Type::kKilometer);

  EXPECT_TRUE(larger_distance > distance_by_kilo);
  EXPECT_FALSE(distance_by_kilo > larger_distance);
}

TEST(GeometryDistance, OperatorGreaterThanOrEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance same_distance(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance larger_distance(KInputValue + 1.0, Distance::Type::kKilometer);

  EXPECT_TRUE(larger_distance >= distance_by_kilo);
  EXPECT_TRUE(distance_by_kilo >= same_distance);
  EXPECT_FALSE(smaller_distance >= distance_by_kilo);
}

TEST(GeometryDistance, OperatorAdd) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto Distance1 = distance_by_kilo + distance;
  const auto Distance2 = distance_by_kilo + distance_by_nano;
  const auto Distance3 = distance + distance_by_nano;

  EXPECT_DOUBLE_EQ(Distance1.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
  EXPECT_DOUBLE_EQ(Distance2.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
  EXPECT_DOUBLE_EQ(Distance3.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
}

TEST(GeometryDistance, OperatorSubtract) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance subtracted_distance = distance_by_kilo - distance;

  EXPECT_DOUBLE_EQ(subtracted_distance.GetValue(Distance::Type::kKilometer),
                   0.0);
}

TEST(GeometryDistance, OperatorMultiply) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance(KInputValue, Distance::Type::kKilometer);
  auto multiplied_distance = distance * 2.0;

  EXPECT_DOUBLE_EQ(multiplied_distance.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
}

TEST(GeometryDistance, OperatorDivide) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance(KInputValue, Distance::Type::kKilometer);
  auto divided_distance = distance / 2.0;

  EXPECT_DOUBLE_EQ(divided_distance.GetValue(Distance::Type::kKilometer),
                   KInputValue / 2.0);
}

TEST(GeometryDistance, OperatorDivideByZero) {
  Distance distance(1, Distance::Type::kKilometer);
  EXPECT_THROW(distance / 0.0, std::runtime_error);
}

TEST(GeometryDistance, OperatorPlusEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  distance_by_kilo += Distance(KInputValue, Distance::Type::kKilometer);

  EXPECT_DOUBLE_EQ(distance_by_kilo.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
}

TEST(GeometryDistance, OperatorMinusEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  distance_by_kilo -= Distance(KInputValue / 2.0, Distance::Type::kKilometer);

  EXPECT_DOUBLE_EQ(distance_by_kilo.GetValue(Distance::Type::kKilometer),
                   KInputValue / 2.0);
}

TEST(GeometryDistance, OperatorMultiplyEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance(KInputValue, Distance::Type::kKilometer);
  distance *= 2.0;

  EXPECT_DOUBLE_EQ(distance.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
}

TEST(GeometryDistance, OperatorDivideEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance(KInputValue, Distance::Type::kKilometer);
  distance /= 2.0;

  EXPECT_DOUBLE_EQ(distance.GetValue(Distance::Type::kKilometer),
                   KInputValue / 2.0);
}
}  // namespace yemerge::geometry
