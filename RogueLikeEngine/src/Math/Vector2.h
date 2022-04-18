#pragma once

#include <cstdint>



namespace rle
{
	template<class T>
	struct Vector2 final
	{
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------
		
		// default ctor
		Vector2() = default;

		// ctor
		// sets the x and y of the vector
		Vector2(const T px, const T py);

		// default dtor
		~Vector2() = default;

		// comparison operator
		bool operator==(const Vector2<T>& other) const;

		// decomparison operator
		bool operator!=(const Vector2<T>& other) const;

		// addition operator
		Vector2<T> operator+(const Vector2<T>& other) const;

		// subtraction operator
		Vector2<T> operator-(const Vector2<T>& other) const;

		// multiplication operator
		Vector2<T> operator*(const Vector2<T>& other) const;

		// division operator
		Vector2<T> operator/(const Vector2<T>& other) const;

		// addition assignment operator
		Vector2<T>& operator+=(const Vector2<T>& other);

		// subtraction assignment operator
		Vector2<T>& operator-=(const Vector2<T>& other);

		// multiplication assignment operator
		Vector2<T>& operator*=(const Vector2<T>& other);

		// division assignment operator
		Vector2<T>& operator/=(const Vector2<T>& other);



		// data members
		T x{};
		T y{};
	};



	template<class T>
	inline Vector2<T>::Vector2(const T px, const T py) :
		x(px),
		y(py)
	{

	}



	template<class T>
	inline bool Vector2<T>::operator==(const Vector2<T>& other) const
	{
		return x == other.x && y == other.y;
	}



	template<class T>
	inline bool Vector2<T>::operator!=(const Vector2<T>& other) const
	{
		return x != other.x && y != other.y;
	}



	template<class T>
	inline Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) const
	{
		return Vector2<T>(x + other.x, y + other.y);
	}



	template<class T>
	inline Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) const
	{
		return Vector2<T>(x - other.x, y - other.y);
	}



	template<class T>
	inline Vector2<T> Vector2<T>::operator*(const Vector2<T>& other) const
	{
		return Vector2<T>(x * other.x, y * other.y);
	}



	template<class T>
	inline Vector2<T> Vector2<T>::operator/(const Vector2<T>& other) const
	{
		return Vector2<T>(x / other.y, y / other.y);
	}



	template<class T>
	inline Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}



	template<class T>
	inline Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}



	template<class T>
	inline Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}



	template<class T>
	inline Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}



	// common definitions of Vector2
	using Vector2f = Vector2<float>;
	using Vector2i = Vector2<int>;
	using Vector2u = Vector2<std::uint32_t>;
}
