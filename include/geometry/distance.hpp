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

namespace yemerge::geometry {
  /**
   * @brief The class for abstract distance
   */
  class Distance{
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

    protected:
    private:
  }

}

#endif  // YEMERGE__GEOMETRY__DISTANCE_HPP_
