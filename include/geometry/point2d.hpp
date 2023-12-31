/**
 * @file geometry/point2d.hpp
 * @author yemerge (bohmbohmpow@gmail.com)
 * @brief Point class declaration with 2-dimension
 * @version 0.1
 * @date 2023-12-26
 *
 * @copyright Copyright (c) 2023
 *
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : yemerge

#ifndef YEMERGE__GEOMETRY__POINT_2D_HPP_
#define YEMERGE__GEOMETRY__POINT_2D_HPP_

namespace yemerge::geometry {

/**
 * @brief Point class with 2-dimension
 *
 */
class Point2D {
 public:
  /**
   * @brief Construct a new Point 2D object
   *
   */
  Point2D() = default;
  /**
   * @brief Construct a new Point 2D object with x, y value
   * @param x Double type x coordinate value
   * @param y Double type y coordinate value
   */
  Point2D(double input_x, double input_y);

  /**
   * @brief Copy construct a new Point 2D object with othe Point2D object
   * @param other Point2D object
   */
  Point2D(const Point2D& other) = default;
  /**
   * @brief Move construct a new Point 2D object with othe Point2D object
   * @param other Point2D object
   */
  Point2D(Point2D&& other) noexcept = default;

  /**
   * @brief Destroy the Point 2d object
   *
   */
  virtual ~Point2D() = default;

  /**
   * @brief Copy assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  // Point2D new_one = old_one;
  // new_one.Getx();
  // old_one.Getx();
  auto operator=(const Point2D& other) -> Point2D& = default;

  /**
   * @brief Move assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  // Point2D new_one = std::move(old_one);
  // new_one.Getx();
  // old_one.Getx();    xxxxxxx
  auto operator=(Point2D&& other) -> Point2D& = default;

  /**
   * @brief Calculate distance between this point and target point
   * @param target Other Point2D object to calculate distance
   * @return double Euclidean distance between this point and target point
   */
  [[nodiscard]] auto CalculateDistance(const Point2D& target) const -> double;

  /**
   * @brief Calculate distance between lhs point and rhs point
   * @param lhs Left hand side Point2D object
   * @param rhs Right hand side Point2D object
   * @return double Euclidean distance between lhs point and rhs point
   */
  [[nodiscard]] static auto CalculateDistance(const Point2D& lhs,
                                              const Point2D& rhs) -> double;

  /**
   * @brief Set x coordinate value
   * @param x Double type input x coordinate value
   */
  void SetX(double input_x);
  /**
   * @brief Set y coordinate value
   * @param y Double type input y coordinate value
   */
  void SetY(double input_y);

  /**
   * @brief Get x coordinate value of this point
   * @return double x coordinate value of this point
   */
  [[nodiscard]] auto GetX() const -> double;
  /**
   * @brief Get y coordinate value of this point
   * @return double y coordinate value of this point
   */
  [[nodiscard]] auto GetY() const -> double;

  /**
   * @brief Adds two Point2D objects.
   * @param other The Point2D object to add.
   * @return Point2D A new Point2D object with the sum of the coordinates.
   */
  auto operator+(const Point2D& other) const -> Point2D;
  /**
   * @brief Subtracts two Point2D objects.
   * @param other The Point2D object to subtract.
   * @return Point2D A new Point2D object with the result of the subtraction.
   */
  auto operator-(const Point2D& other) const -> Point2D;
  
  /**
   * @brief Adds a Point2D object to the current object.
   * @param other The Point2D object to add.
   * @return Point2D& A reference to the current object after addition.
   */
  auto operator+=(const Point2D& other) -> Point2D&;
  /**
   * @brief Subtracts a Point2D object from the current object.
   * @param other The Point2D object to subtract.
   * @return Point2D& A reference to the current object after subtraction.
   */
  auto operator-=(const Point2D& other) -> Point2D&;

  /**
   * @brief Multiplies the coordinates of the Point2D object by a scalar.
   * @param scalar The scalar value to multiply with.
   * @return Point2D A new Point2D object with the multiplied coordinates.
   */
  auto operator*(double scalar) const -> Point2D;
  /**
   * @brief Divides the coordinates of the Point2D object by a scalar.
   * @param scalar The scalar value to divide by.
   * @return Point2D A new Point2D object with the divided coordinates.
   */
  auto operator/(double scalar) const -> Point2D;

  /**
   * @brief Checks if two Point2D objects are equal.
   * @param other The Point2D object to compare with.
   * @return true If both Point2D objects have the same coordinates
   * @return false Otherwise
   */
  auto operator==(const Point2D& other) const -> bool;
  /**
   * @brief Checks if two Point2D objects are not equal.
   * @param other The Point2D object to compare with.
   * @return true If the Point2D objects do not have the same coordinates
   * @return false Oherwise.
   */
  auto operator!=(const Point2D& other) const -> bool;

 protected:
 private:
  double x_{0.0};  ///< x coordinate
  double y_{0.0};  ///< y coordinate
};

}  // namespace yemerge::geometry

#endif
