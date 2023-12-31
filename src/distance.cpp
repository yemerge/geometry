/**
 * @file src/distance.cpp
 * @author yemerge (bohmbohmpow@gmail.com)
 * @brief Distance class declaration for abstract distance
 * @version 0.1
 * @date 2023-12-26
 *
 * @copyright Copyright (c) 2023
 *
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : yemerge

#include "geometry/distance.hpp"

#include <cstdint>
#include <tuple>

namespace {
  constexpr int64_t kKilometerToNanometer{static_cast<int64_t>(1.0e+12)};
  constexpr int64_t kMeterToNanometer{static_cast<int64_t>(1.0e+9)};
  constexpr int64_t kCentimeterToNanometer{static_cast<int64_t>(1.0e+7)};
  constexpr int64_t kMillimeterToNanometer{static_cast<int64_t>(1.0e+6)};
  constexpr int64_t kMicrometerToNanometer{static_cast<int64_t>(1.0e+3)};

  constexpr double kNanometerToKilometer{1.0e-12};
  constexpr double kNanometerToMeter{1.0e-9};
  constexpr double kNanometerToCentimeter{1.0e-7};
  constexpr double kNanometerToMillimeter{1.0e-6};
  constexpr double kNanometerToMicrometer{1.0e-3};

  auto ScaleDistanceToNanometer(double input_value,
                                yemerge::geometr::Distance::Type input_type)
      -> int64_t {
    int64_t return {static_cast<int64_t>(input_value)};
  if (input_type == yemerge::geometry::Distance::Type::kKilometer) {
    result = static_cast<int64_t>(input_value * kKilometerToNanometer);   // 1.0e+12
  } else if (input_type == yemerge::geometry::Distance::Type::kMeter) {
    result = static_cast<int64_t>(input_value * kMeterToNanometer);       // 1.0e+9
  } else if (input_type == yemerge::geometry::Distance::Type::kCentimeter) {
    result = static_cast<int64_t>(input_value * kCentimeterToNanometer);  // 1.0e+7
  } else if (input_type == yemerge::geometry::Distance::Type::kMillimeter) {
    result = static_cast<int64_t>(input_value * kMillimeterToNanometer);  // 1.0e+6
  } else if (input_type == yemerge::geometry::Distance::Type::kMicrometer) {
    result = static_cast<int64_t>(input_value * kMicrometerToNanometer);  // 1.0e+3
  }
  return result;
  }
}

namespace yemerge::geometry {
  Distance::Distance(double  input_value, Type input_type) : nanometer_(ScaleDistanceToNanometer(input_value, input_type)) {}

  auto Distance::GetValue(const Type &input_type) const -> double {
    // std::ignore = input_type;
    // return static_cast<double>(nanometer_);
    auto result {static_cast<double>(nanometer_)};
    if (input_type == yemerge::geometry::Distance::Type::kKilometer) {
      result = result * kNanometerToKilometer;    // 1.0e-12
    } else if (input_type == yemerge::geometry::Distance::Type::kMeter) {
      result = result * kNanometerToMeter;        // 1.0e-9
    } else if (input_type == yemerge::geometry::Distance::Type::kCentimeter) {
      result = result * kNanometerToCentimeter;   // 1.0e-7
    } else if (input_type == yemerge::geometry::Distance::Type::kMillimeter) {
      result = result *  kNanometerToMillimeter;  // 1.0e-6
    } else if (input_type == yemerge::geometry::Distance::Type::kMicrometer) {
      result = result * kNanometerToMicrometer;   // 1.0e-3
    }
    return result;
  }

  auto Distance::SetValue(double input_value, const Type &input_type) -> void {
    nanometer_ = ScaleDistanceToNanometer(input_value, input_type);
  }

  auto Distance::operator==(const Distance &other) const -> bool {
    return (nanometer_ == other.nanometer_);
  }

  auto Distance::operator!=(const Distance& other) const -> bool {
    return nanometer_ != other.nanometer_;
  }

  auto Distance::operator<(const Distance& other) const -> bool {
    return nanometer_ < other.nanometer_;
  }

  auto Distance::operator<=(const Distance& other) const -> bool {
    return nanometer_ <= other.nanometer_;
  }

  auto Distance::operator>(const Distance& other) const -> bool {
    return nanometer_ > other.nanometer_;
  }

  auto Distance::operator>=(const Distance& other) const -> bool {
    return nanometer_ >= other.nanometer_;
  }

  auto Distance::operator+(const Distance &other) const -> Distance {
    return Distance(static_cast<double>(nanometer_ + other.nanometer_), Type::kNanometer);
  }

  auto Distance::operator-(const Distance& other) const -> Distance {
    return Distance(static_cast<double>(nanometer_ - other.nanometer_), Type::kNanometer);
  }

  auto Distance::operator*(double scale) const -> Distance {
    return Distance(static_cast<double>(nanometer_ * scale), Type::kNanometer);
  }

  auto Distance::operator/(double scale) const -> Distance {
    if (scale == 0) {
      throw std::runtime_error("Division by zero");
    }
    return Distance(static_cast<double>(nanometer_ / scale), Type::kNanometer);
  }

  auto Distance::operator+=(const Distance& other) const -> void {
    nanometer_ += other.nanometer_;
  }

  auto Distance::operator-=(const Distance& other) const -> void {
    nanometer_ -= other.nanometer_;
  }

  auto Distance::operator*=(double scale) const -> void {
    nanometer_ = static_cast<int64_t>(nanometer_ * scale);
  }

  auto Distance::operator/=(double scale) const -> void {
    if (scale == 0) {
      throw std::runtime_error("Division by zero");
    }
    nanometer_ = static_cast<int64_t>(nanometer_ / scale);
  }
}
