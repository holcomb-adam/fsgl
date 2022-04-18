#pragma once

#include <cmath>
#include <cstdint>

#include "Math/Algebra.h"



namespace rle
{
	// represents a vector in 3D space
	template<class T>
	struct Vector3 final
	{
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------
		
		// default ctor
		Vector3() = default;

		// ctor
		// sets the x, y, and z of the vector
		Vector3(const T x, const T y, const T z);

		// default dtor
		~Vector3() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - ALGEBRAIC FUNCTIONS -------------------------------------------------------

		// get the magnitude (distance) of the vector
		float magnitude() const;

		// return a normalized version of the vector
		Vector3<T> getUnitVector() const;

		// normalize the vector
		// sets the vector to it's unit vector
		Vector3<T>& normalize();



		////////////////////////////////////////////////////////////////////////////////
		// - COMPARISON OPERATORS ------------------------------------------------------

		// comparison operator
		bool operator==(const Vector3<T>& other) const;

		// decomparison operator
		bool operator!=(const Vector3<T>& other) const;



		////////////////////////////////////////////////////////////////////////////////
		// - ARITHMETIC OPERATORS ------------------------------------------------------

		// overloaded addition
		Vector3<T> operator+(T&& scalar) const;
		Vector3<T> operator+(const Vector3<T>& other) const;

		// subtraction operator
		Vector3<T> operator-(const Vector3<T>& other) const;

		// multiplication operator
		Vector3<T> operator*(const Vector3<T>& other) const;

		// division operator
		Vector3<T> operator/(const Vector3<T>& other) const;

		// addition assignment operator
		Vector3<T>& operator+=(const Vector3<T>& other);

		// subtraction assignment operator
		Vector3<T>& operator-=(const Vector3<T>& other);

		// multiplication assignment operator
		Vector3<T>& operator*=(const Vector3<T>& other);

		// division assignment operator
		Vector3<T>& operator/=(const Vector3<T>& other);



		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC MEMBERS ------------------------------------------------------------
		
		// data members
		T x{};
		T y{};
		T z{};
	};



	template<class T>
	inline Vector3<T>::Vector3(const T x, const T y, const T z) :
		x(x),
		y(y),
		z(z)
	{

	}



	template<class T>
	inline float Vector3<T>::magnitude() const
	{
		return math::distance(x, y, z);
	}



	template<class T>
	inline Vector3<T> Vector3<T>::getUnitVector() const
	{
		const auto m = magnitude();

		const auto ufx = static_cast<float>(x) / m;
		const auto ufy = static_cast<float>(y) / m;
		const auto ufz = static_cast<float>(z) / m;

		return Vector3<T>(static_cast<T>(ufx),
			static_cast<T>(ufy),
			static_cast<T>(ufz));
	}



	template<class T>
	inline Vector3<T>& Vector3<T>::normalize()
	{
		return *this = getUnitVector();
	}



	template<class T>
	inline bool Vector3<T>::operator==(const Vector3<T>& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}



	template<class T>
	inline bool Vector3<T>::operator!=(const Vector3<T>& other) const
	{
		return x != other.x && y != other.y && z != other.z;
	}



	template<class T>
	inline Vector3<T> Vector3<T>::operator+(T&& scalar) const
	{
		return Vector3<T>(x + scalar, y + scalar, z + scalar);
	}



	template<class T>
	inline Vector3<T> Vector3<T>::operator+(const Vector3<T>& other) const
	{
		return Vector3<T>(x + other.x, y + other.y, z + other.z);
	}



	template<class T>
	inline Vector3<T> Vector3<T>::operator-(const Vector3<T>& other) const
	{
		return Vector3<T>(x - other.x, y - other.y, z - other.z);
	}



	template<class T>
	inline Vector3<T> Vector3<T>::operator*(const Vector3<T>& other) const
	{
		return Vector3<T>(x * other.x, y * other.y, z * other.z);
	}



	template<class T>
	inline Vector3<T> Vector3<T>::operator/(const Vector3<T>& other) const
	{
		return Vector3<T>(x / other.x, y / other.y, z / other.z);
	}



	template<class T>
	inline Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}



	template<class T>
	inline Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}



	template<class T>
	inline Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}



	template<class T>
	inline Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}



	// common definitions of Vector3
	using Vector3f = Vector3<float>;
	using Vector3i = Vector3<float>;
	using Vector3u = Vector3<std::uint32_t>;
}
