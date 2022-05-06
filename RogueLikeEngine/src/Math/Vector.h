#pragma once

// standard library includes
#include <array>

// rle library includes
#include "Math/Algebra.h"



namespace rle
{
	namespace detail // TODO: eventually all this needs to be hidden
	{

		// base vector class
		template<class T, std::size_t DIM>
		class Vector_base
		{
		public:
			Vector_base() : m_Dimensions({ 0 }) {}

			template<class... Targs,
				class =
				std::enable_if_t<sizeof...(Targs) <= DIM && (std::is_same_v<T, std::decay_t<Targs>> && ...)>
			>
			Vector_base(Targs&&... args) : m_Dimensions({ std::forward<Targs>(args)... }) {}

		protected:
			std::array<T, DIM> m_Dimensions;
		};



		// vector specialization class
		template<class T, std::size_t DIM>
		class Vector_spec : public Vector_base<T, DIM>
		{
			// empty Vector_base struct
		};
	}





	// vector class
	// represents a vector in, DIM, dimensional space
	template<class T, std::size_t DIM>
	class Vector : public detail::Vector_spec<T, DIM>
	{
	public:
		// local indicies for named dimension positions within
		// the underlying array
		static constexpr std::size_t X_POS = 0;
		static constexpr std::size_t Y_POS = 1;
		static constexpr std::size_t Z_POS = 2;
		static constexpr std::size_t W_POS = 3;

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// default ctor
		Vector();

		// ctor, takes elements to populate the array elements
		template<class... Targs>
		Vector(Targs&&... args);

		// default dtor
		~Vector() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - ALGEBRAIC FUNCTIONS -------------------------------------------------------

		// get the magnitude (distance) of the vector
		T magnitude() const;

		// return a normalized version of the vector
		Vector<T, DIM> getUnitVector() const;

		// normalize the vector
		// sets the vector to it's unit vector
		Vector<T, DIM>& normalize();



		////////////////////////////////////////////////////////////////////////////////
		// - COMPARISON OPERATORS ------------------------------------------------------

		// comparison operator
		bool operator==(const Vector<T, DIM>& other) const;

		// decomparison operator
		bool operator!=(const Vector<T, DIM>& other) const;



		////////////////////////////////////////////////////////////////////////////////
		// - ARITHMETIC OPERATORS ------------------------------------------------------

		// overloaded addition operators
		Vector<T, DIM> operator+(T&& scalar) const;
		Vector<T, DIM> operator+(const Vector<T, DIM>& other) const;

		// subtraction operator
		Vector<T, DIM> operator-(const Vector<T, DIM>& other) const;

		// multiplication operator
		Vector<T, DIM> operator*(const Vector<T, DIM>& other) const;

		// overloaded division operators
		Vector<T, DIM> operator/(T&& scalar) const;
		Vector<T, DIM> operator/(const Vector<T, DIM>& other) const;

		// addition assignment operator
		Vector<T, DIM>& operator+=(const Vector<T, DIM>& other);

		// subtraction assignment operator
		Vector<T, DIM>& operator-=(const Vector<T, DIM>& other);

		// multiplication assignment operator
		Vector<T, DIM>& operator*=(const Vector<T, DIM>& other);

		// division assignment operator
		Vector<T, DIM>& operator/=(const Vector<T, DIM>& other);



		////////////////////////////////////////////////////////////////////////////////
		// - ELEMENT ACCESS ------------------------------------------------------------

		// retireve a reference to the element at location
		T& at(const std::size_t i);

		// retrieve a constant reference to the element at location
		const T& at(const std::size_t i) const;

		// operator[] overload
		T& operator[](const std::size_t i);

		// constant operator[] overload
		const T& operator[](const std::size_t i) const;
	};



	template<class T, std::size_t DIM>
	inline Vector<T, DIM>::Vector() : 
		detail::Vector_spec<T, DIM>()
	{

	}



	template<class T, std::size_t DIM>
	template<class ...Targs>
	inline Vector<T, DIM>::Vector(Targs&&... args) :
		detail::Vector_spec<T, DIM>( std::forward<Targs>(args)... )
	{

	}



	template<class T, std::size_t DIM>
	inline T Vector<T, DIM>::magnitude() const
	{
		return math::distance(
			this->m_Dimensions[X_POS],
			this->m_Dimensions[Y_POS],
			this->m_Dimensions[Z_POS]);
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM> Vector<T, DIM>::getUnitVector() const
	{
		const auto m = magnitude();
		return *this / m;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM>& Vector<T, DIM>::normalize()
	{
		return *this = getUnitVector();
	}



	template<class T, std::size_t DIM>
	inline bool Vector<T, DIM>::operator==(const Vector<T, DIM>& other) const
	{
		for (std::size_t i = 0; i < DIM; i++)
			if ((*this)[i] != other[i])
				return false;
		return true;
	}



	template<class T, std::size_t DIM>
	inline bool Vector<T, DIM>::operator!=(const Vector<T, DIM>& other) const
	{
		for (std::size_t i = 0; i < DIM; i++)
			if ((*this)[i] == other[i])
				return false;
		return true;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM> Vector<T, DIM>::operator+(T&& scalar) const
	{
		Vector<T, DIM> nv;
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			nv[i] = (*this)[i] + std::forward<T>(scalar);
		return nv;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM> Vector<T, DIM>::operator+(const Vector<T, DIM>& other) const
	{
		Vector<T, DIM> nv;
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			nv[i] = (*this)[i] + other[i];	
		return nv;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM> Vector<T, DIM>::operator-(const Vector<T, DIM>& other) const
	{
		Vector<T, DIM> nv;
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			nv[i] = (*this)[i] - other[i];
		return nv;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM> Vector<T, DIM>::operator*(const Vector<T, DIM>& other) const
	{
		Vector<T, DIM> nv;
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			nv[i] = (*this)[i] * other[i];
		return nv;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM> Vector<T, DIM>::operator/(T&& scalar) const
	{
		Vector<T, DIM> nv;
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			nv[i] = (*this)[i] / std::forward<T>(scalar);
		return nv;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM> Vector<T, DIM>::operator/(const Vector<T, DIM>& other) const
	{
		Vector<T, DIM> nv;
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			nv[i] = (*this)[i] / other[i];
		return nv;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM>& Vector<T, DIM>::operator+=(const Vector<T, DIM>& other)
	{
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			(*this)[i] += other[i];
		return *this;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM>& Vector<T, DIM>::operator-=(const Vector<T, DIM>& other)
	{
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			(*this)[i] -= other[i];
		return *this;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM>& Vector<T, DIM>::operator*=(const Vector<T, DIM>& other)
	{
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			(*this)[i] *= other[i];
		return *this;
	}



	template<class T, std::size_t DIM>
	inline Vector<T, DIM>& Vector<T, DIM>::operator/=(const Vector<T, DIM>& other)
	{
		for (std::size_t i = 0; i < this->m_Dimensions.size(); i++)
			(*this)[i] /= other[i];
		return *this;
	}



	template<class T, std::size_t DIM>
	inline T& Vector<T, DIM>::at(const std::size_t i)
	{
		return this->m_Dimensions.at(i);
	}



	template<class T, std::size_t DIM>
	inline const T& Vector<T, DIM>::at(const std::size_t i) const
	{
		return this->m_Dimensions.at(i);
	}



	template<class T, std::size_t DIM>
	inline T& Vector<T, DIM>::operator[](const std::size_t i)
	{
		return this->m_Dimensions[i];
	}



	template<class T, std::size_t DIM>
	inline const T& Vector<T, DIM>::operator[](const std::size_t i) const
	{
		return this->m_Dimensions[i];
	}





	////////////////////////////////////////////////////////////////////////////////
	// - COMMON VECTOR DEFINITIONS -------------------------------------------------

	// templated common vectors
	template<class T> using Vector2 = Vector<T, 2>;
	template<class T> using Vector3 = Vector<T, 3>;

	// common definitions of Vector2
	using Vector2f = Vector2<float>;
	using Vector2i = Vector2<std::int32_t>;
	using Vector2u = Vector2<std::uint32_t>;

	// common definitions of Vector3
	using Vector3f = Vector3<float>;
	using Vector3i = Vector3<std::int32_t>;
	using Vector3u = Vector3<std::uint32_t>;





	////////////////////////////////////////////////////////////////////////////////
	// - VECTOR BASE CLASS SPECIALIZATIONS -----------------------------------------

	// 1 dimensional vector should have just an x val
	template<class T>
	class detail::Vector_spec<T, 1> : public detail::Vector_base<T, 1>
	{
	public:
		Vector_spec() :
			x(this->m_Dimensions[rle::Vector<T, 1>::X_POS]) {}

		template<class... Targs>
		Vector_spec(Targs&&... args) :
			detail::Vector_base<T, 1>(std::forward<Targs>(args)...),
			x(this->m_Dimensions[rle::Vector<T, 2>::X_POS]) {}

		T& x;
	};

	// 2 dimensional vector should have x and y vals
	template<class T>
	class detail::Vector_spec<T, 2> : public detail::Vector_base<T, 2>
	{
	public:
		Vector_spec() :
			x(this->m_Dimensions[rle::Vector<T, 2>::X_POS]),
			y(this->m_Dimensions[rle::Vector<T, 2>::Y_POS]) {}

		template<class... Targs>
		Vector_spec(Targs&&... args) :
			detail::Vector_base<T, 2>(std::forward<Targs>(args)...),
			x(this->m_Dimensions[rle::Vector<T, 2>::X_POS]),
			y(this->m_Dimensions[rle::Vector<T, 2>::Y_POS]) {}

		T& x, & y;
	};

	// 3 dimensional vector should have x, y, and z vals
	template<class T>
	class detail::Vector_spec<T, 3> : public detail::Vector_base<T, 3>
	{
	public:
		Vector_spec() :
			x(this->m_Dimensions[rle::Vector<T, 3>::X_POS]),
			y(this->m_Dimensions[rle::Vector<T, 3>::Y_POS]),
			z(this->m_Dimensions[rle::Vector<T, 3>::Z_POS]) {}

		template<class... Targs>
		Vector_spec(Targs&&... args) :
			detail::Vector_base<T, 3>(std::forward<Targs>(args)...),
			x(this->m_Dimensions[rle::Vector<T, 3>::X_POS]),
			y(this->m_Dimensions[rle::Vector<T, 3>::Y_POS]),
			z(this->m_Dimensions[rle::Vector<T, 3>::Z_POS]) {}

		T& x, & y, & z;
	};

	// finally, 4 dimensional vector should have x, y, z, and w vals
	template<class T>
	class detail::Vector_spec<T, 4> : public detail::Vector_base<T, 4>
	{
	public:
		Vector_spec() :
			x(this->m_Dimensions[rle::Vector<T, 4>::X_POS]),
			y(this->m_Dimensions[rle::Vector<T, 4>::Y_POS]),
			z(this->m_Dimensions[rle::Vector<T, 4>::Z_POS]),
			w(this->m_Dimensions[rle::Vector<T, 4>::W_POS]) {}

		template<class... Targs>
		Vector_spec(Targs&&... args) :
			detail::Vector_base<T, 4>(std::forward<Targs>(args)...),
			x(this->m_Dimensions[rle::Vector<T, 4>::X_POS]),
			y(this->m_Dimensions[rle::Vector<T, 4>::Y_POS]),
			z(this->m_Dimensions[rle::Vector<T, 4>::Z_POS]),
			w(this->m_Dimensions[rle::Vector<T, 4>::W_POS]) {}

		T& x, & y, & z, & w;
	};
}
