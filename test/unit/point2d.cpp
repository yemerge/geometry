// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : yemerge
#include "geometry/point2d.hpp"

#include <cmath>
#include <stdexcept>

#include "gtest/gtest.h"

// Variables that can only be used within the source file.
// If you do not set a namespace, it becomes a global variable.
namespace {
constexpr uint32_t kTestCount = 1000U;
}

namespace yemerge::geometry {
TEST(GeometryPoint2D, Constructor) {
  Point2D point1;
  Point2D point2(0.0, 1.0);
  Point2D point3(point2);  // Copied
  Point2D point4(std::move(Point2D()));
  // point1 disappears and is replaced by point4
  // EXPECT_EQ(point.x(), 0);
  // EXPECT_EQ(point.y(), 0);

  // Point2D point2(1,2);
  // EXPECT_EQ(point2.x(), 1);
  // EXPECT_EQ(point2.y(), 2);

  // Point2D point3(point2);
  // EXPECT_EQ(point3.x(), 1);
  // EXPECT_EQ(point3.y(), 2);

  // Point2D point4(std::move(point2));
  // EXPECT_EQ(point4.x(), 1);
  // EXPECT_EQ(point4.y(), 2);
}
TEST(GeometryPoint2D, AssignmentOperator) {
  Point2D point1;
  auto point2 = point1;
  auto point3 = std::move(Point2D());
}

TEST(GeometryPoint2D, CalculateDistance) {
  // Implementing random operations using for loops
  // constexpr uint32_t kTestCount = 1000U; // Created an unnamed namespace.
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());
    const auto KTargetX = static_cast<double>(std::rand());
    const auto KTargetY = static_cast<double>(std::rand());
    // constexpr auto KSourceX = static_cast<double>(std::rand());
    // constexpr auto KSourceY = static_cast<double>(std::rand());
    // constexpr auto KTargetX = static_cast<double>(std::rand());
    // constexpr auto KTargetY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KTargetX, KTargetY);

    EXPECT_FLOAT_EQ(std::sqrt((KSourceX - KTargetX) * (KSourceX - KTargetX) +
                              (KSourceY - KTargetY) * (KSourceY - KTargetY)),
                    source.CalculateDistance(target));
  }
  // constexpr double kSourceX = 1.0;
  // constexpr double kSourceY = 2.0;
  // constexpr double kTargetX = 4.0;
  // constexpr double kTargetY = 6.0;

  // Point2D source(kSourceX, kSourceY);
  // Point2D target(kTargetX, kTargetY);

  // EXPECT_FLOAT_EQ(std::sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
  //                           (kSourceY - kTargetY) * (kSourceY - kTargetY)),
  //                 source.CalculateDistance(target));
}

TEST(GeometryPoint2D, StaticCalculateDistance) {
  // constexpr uint32_t kTestCount = 1000U; // Created an unnamed namespace.
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());
    const auto KTargetX = static_cast<double>(std::rand());
    const auto KTargetY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KTargetX, KTargetY);

    EXPECT_FLOAT_EQ(std::sqrt((KSourceX - KTargetX) * (KSourceX - KTargetX) +
                              (KSourceY - KTargetY) * (KSourceY - KTargetY)),
                    Point2D::CalculateDistance(source, target));
  }
}

TEST(GeometryPoint2D, GetX) {
  // constexpr uint32_t kTestCount = 1000U; // Created an unnamed namespace.
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());

    Point2D source(KSourceX, 0.0);

    EXPECT_FLOAT_EQ(KSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, GetY) {
  // constexpr uint32_t kTestCount = 1000U; // Created an unnamed namespace.
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceY = static_cast<double>(std::rand());

    Point2D source(0.0, KSourceY);

    EXPECT_FLOAT_EQ(KSourceY, source.GetY());
  }
}

TEST(GeometryPoint2D, SetX) {
  // constexpr uint32_t kTestCount = 1000U; // Created an unnamed namespace.
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());

    Point2D source;  // Initialized with default constructor

    source.SetX(KSourceX);

    EXPECT_FLOAT_EQ(KSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, SetY) {
  // constexpr uint32_t kTestCount = 1000U; // Created an unnamed namespace.
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceY = static_cast<double>(std::rand());

    Point2D source;  // Initialized with default constructor

    source.SetY(KSourceY);

    EXPECT_FLOAT_EQ(KSourceY, source.GetY());
  }
}

TEST(GeometryPoint2D, OperatorPlus) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());
    const auto KTargetX = static_cast<double>(std::rand());
    const auto KTargetY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KTargetX, KTargetY);
    Point2D result = source + target;

    EXPECT_FLOAT_EQ(result.GetX(), KSourceX + KTargetX);
    EXPECT_FLOAT_EQ(result.GetY(), KSourceY + KTargetY);
  }
}

TEST(GeometryPoint2D, OperatorMinus) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());
    const auto KTargetX = static_cast<double>(std::rand());
    const auto KTargetY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KTargetX, KTargetY);
    Point2D result = source - target;

    EXPECT_FLOAT_EQ(result.GetX(), KSourceX - KTargetX);
    EXPECT_FLOAT_EQ(result.GetY(), KSourceY - KTargetY);
  }
}

TEST(GeometryPoint2D, OperatorPlusEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    auto KSourceX = static_cast<double>(std::rand());
    auto KSourceY = static_cast<double>(std::rand());
    auto KTargetX = static_cast<double>(std::rand());
    auto KTargetY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KTargetX, KTargetY);
    source += target;

    EXPECT_FLOAT_EQ(source.GetX(), KSourceX + KTargetX);
    EXPECT_FLOAT_EQ(source.GetY(), KSourceY + KTargetY);
  }
}

TEST(GeometryPoint2D, OperatorMinusEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    auto KSourceX = static_cast<double>(std::rand());
    auto KSourceY = static_cast<double>(std::rand());
    auto KTargetX = static_cast<double>(std::rand());
    auto KTargetY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KTargetX, KTargetY);
    source -= target;

    EXPECT_FLOAT_EQ(source.GetX(), KSourceX - KTargetX);
    EXPECT_FLOAT_EQ(source.GetY(), KSourceY - KTargetY);
  }
}

TEST(GeometryPoint2D, OperatorMultiply) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    auto KSourceX = static_cast<double>(std::rand());
    auto KSourceY = static_cast<double>(std::rand());
    double scalar = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D result = source * scalar;

    EXPECT_FLOAT_EQ(result.GetX(), KSourceX * scalar);
    EXPECT_FLOAT_EQ(result.GetY(), KSourceY * scalar);
  }
}

TEST(GeometryPoint2D, OperatorDivide) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    auto KSourceX = static_cast<double>(std::rand());
    auto KSourceY = static_cast<double>(std::rand());
    double scalar = static_cast<double>(std::rand()) +
                    1;  // Adding 1 to avoid division by zero

    Point2D source(KSourceX, KSourceY);
    Point2D result = source / scalar;

    EXPECT_FLOAT_EQ(result.GetX(), KSourceX / scalar);
    EXPECT_FLOAT_EQ(result.GetY(), KSourceY / scalar);
  }
}

TEST(GeometryPoint2D, OperatorDivideByZero) {
  Point2D source(1.0, 1.0);
  EXPECT_THROW(source / 0, std::runtime_error);
}

TEST(GeometryPoint2D, OperatorEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    auto KSourceX = static_cast<double>(std::rand());
    auto KSourceY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KSourceX, KSourceY);

    EXPECT_TRUE(source == target);
  }
}

TEST(GeometryPoint2D, OperatorNotEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    auto KSourceX = static_cast<double>(std::rand());
    auto KSourceY = static_cast<double>(std::rand());
    auto KTargetX = static_cast<double>(std::rand());
    auto KTargetY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KTargetX, KTargetY);

    if (KSourceX != KTargetX || KSourceY != KTargetY) {
      EXPECT_TRUE(source != target);
    }
  }
}
}
