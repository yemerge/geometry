/**
 * @file geometry/src/point2d.cpp
 * @author yemerge (bohmbohmpow@gmail.com)
 * @brief Point class developments with 2-dimension
 * @version 0.1
 * @date 2023-12-26
 *
 * @copyright Copyright (c) 2023
 *
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : yemerge

#include "geometry/point2d.hpp"
#include <cmath>

namespace yemerge::geometry {
  Point2D::Point2D(double input_x, double input_y) : x_(input_x), y_(input_y) {};

  auto Point2D::CalculateDistance(const Point2D& target) const -> double {
    // return std::sqrt(std::pow((x_ - other.x_), 2) +
    //                 std::pow((y_ - other.y_), 2));
    return Point2D::CalculateDistance(*this, target);   // Removed duplicate implementations
  }
  
  auto Point2D::CalculateDistance(const Point2D& lhs, const Point2D& rhs) -> double {
    return std::sqrt(std::pow((lhs.x_ - rhs.x_), 2) +
                    std::pow((lhs.y_ - rhs.y_), 2));
  }

  auto Point2D::GetX() const -> double { return x_; }

  auto Point2D::GetY() const -> double { return y_; }
  
  auto Point2D::SetX(double input_x) -> void { x_ = input x_; }
  
  auto Point2D::SetY(double input_y) -> void { y_ = input y_; }

}
