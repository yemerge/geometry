/**
 * @file geometry/distance.hpp
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

#ifndef YEMERGE__GEOMETRY__DISTANCE_HPP_
#define YEMERGE__GEOMETRY__DISTANCE_HPP_

#include <cstdint>

namespace yemerge::geometry {
/**
 * @brief The class for abstract distance
 */
class Distance {
 public:
  /**
   * @brief The enum class for distance type.
   */
  enum class Type {
    kKilometer = 0,   ///< Kilometer
    kMeter = 1,       ///< Meter
    kCentimeter = 2,  ///< Centimeter
    kMillimeter = 3,  ///< Millimeter
    kMicrometer = 4,  ///< Micrometer
    kNanometer = 5    ///< Nanometer
  };                  ///< Distance type

  /**
   * @brief Construct a new Distance object
   */
  Distance() = default;

  explicit Distance(double input_value, Type input_type = Type::kMeter);

  /**
   * @brief The copy constructor
   * @param other The other distance object
   */
  Distance(const Distance& other) = default;
  /**
   * @brief The move constructor
   * @param other The other distance object
   */
  Distance(Distance&& other) noexcept = default;

  /**
   * @brief Destroy the Distance object
   */
  // The destructor must be made virtual.
  virtual ~Distance() = default;

  /**
   * @brief The copy assignment operator
   * @param other The other distance object
   * @return The reference of distance object
   */
  auto operator=(const Distance& other) -> Distance& = default;

  /**
   * @brief The move assignment operator
   * @param other The other distance object
   * @return The reference of distance object
   */
  auto operator=(Distance&& other) -> Distance& = default;

  /**
   * @brief Get the Distance value for distance type
   * @param input_type The distance type
   * @return double The distance value
   */
  [[nodiscard]] auto GetValue(const Type& input_type) const -> double;

  /**
   * @brief Set the Distance value for distance type
   * @param input_value The distance value
   * @param input_type The distance type
   */
  auto SetValue(double input_value, const Type& input_type) -> void;

  /**
   * @brief Compare with other distance object for equality
   * @param other The other distance object
   * @return true If equal
   * @return false If not equal
   */
  auto operator==(const Distance& other) const -> bool;

  /**
   * @brief Compare with other distance object for inequality.
   * @param other The other distance object.
   * @return true If not equal.
   * @return false If equal.
   */
  auto operator!=(const Distance& other) const -> bool;

  /**
   * @brief Check if this distance object is less than the other.
   * @param other The other distance object to compare with.
   * @return true If this distance object is less than the other.
   * @return false Otherwise.
   */
  auto operator<(const Distance& other) const -> bool;

  /**
   * @brief Check if this distance object is less than or equal to the other.
   * @param other The other distance object to compare with.
   * @return true If this distance object is less than or equal to the other.
   * @return false Otherwise.
   */
  auto operator<=(const Distance& other) const -> bool;

  /**
   * @brief Check if this distance object is greater than the other.
   * @param other The other distance object to compare with.
   * @return true If this distance object is greater than the other.
   * @return false Otherwise.
   */
  auto operator>(const Distance& other) const -> bool;

  /**
   * @brief Check if this distance object is greater than or equal to the other.
   * @param other The other distance object to compare with.
   * @return true If this distance object is greater than or equal to the other.
   * @return false Otherwise.
   */
  auto operator>=(const Distance& other) const -> bool;

  /**
   * @brief Add other distance object
   * @param other The other distance object
   * @return Distance The result of addition
   */
  auto operator+(const Distance& other) const -> Distance;

  /**
   * @brief Subtract another distance object from this one.
   * @param other The other distance object.
   * @return Distance The result of subtraction.
   */
  auto operator-(const Distance& other) const -> Distance;

  /**
   * @brief Multiply this distance by a scalar value.
   * @param scale The scalar value to multiply by.
   * @return Distance The result of multiplication.
   */
  auto operator*(double scale) const -> Distance;

  /**
   * @brief Divide this distance by a scalar value.
   * @param scale The scalar value to divide by.
   * @return Distance The result of division.
   * @throw std::runtime_error If scale is zero.
   */
  auto operator/(double scale) const -> Distance;

  /**
   * @brief Add another distance object to this one and update this object.
   * @param other The other distance object.
   * @return void
   */
  // auto operator+=(const Distance& other) const -> void;
  auto operator+=(const Distance& other) -> void;

  /**
   * @brief Subtract another distance object from this one and update this
   * object.
   * @param other The other distance object.
   * @return void
   */
  // auto operator-=(const Distance& other) const -> void;
  auto operator-=(const Distance& other) -> void;

  /**
   * @brief Multiply this distance by a scalar value and update this object.
   * @param scale The scalar value to multiply by.
   * @return void
   */
  // auto operator*=(double scale) const -> void;
  auto operator*=(double scale) -> void;

  /**
   * @brief Divide this distance by a scalar value and update this object.
   * @param scale The scalar value to divide by.
   * @return void
   * @throw std::runtime_error If scale is zero.
   */
  // auto operator/=(double scale) const -> void;
  auto operator/=(double scale) -> void;

 protected:
 private:
  int64_t nanometer_{0};  ///< nanometer
};

}  // namespace yemerge::geometry

#endif  // YEMERGE__GEOMETRY__DISTANCE_HPP_
