#pragma once

// standard library includes
#include <array>

// rle library includes
#include "Math/Constants.h"
#include "Math/Vector.h"



namespace rle
{
	////////////////////////////////////////////////////////////////////////////////
	// - ALGEBRAIC / GEOMETRIC DEFINES ---------------------------------------------

	// define a triangle
	//     T    - type that will compose the values of the triangle's verticies
	//     DIM  - the number of dimensions the trinangle will exist in
	template<class T, std::size_t DIM>
	using Triangle = std::array<rle::Vector<T, DIM>, math::constants::TRI_VERTS>;

	// common definitions of Triangle
	template<class T> using Triangle2 = Triangle<T, 2>;
	template<class T> using Triangle3 = Triangle<T, 3>;

	// common definitions of Triangle2
	using Triangle2f = Triangle2<float>;
	using Triangle2i = Triangle2<int>;

	// common definitions of Triangle3
	using Triangle3f = Triangle3<float>;
	using Triangle3i = Triangle3<int>;
}