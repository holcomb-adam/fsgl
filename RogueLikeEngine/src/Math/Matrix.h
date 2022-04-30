#pragma once

#include <array>



namespace rle
{
	template<class T, std::size_t C, std::size_t R>
	class Matrix final
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC MEMBERS ------------------------------------------------------------

		// row class
		using row_t = std::array<T, R>;

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// default ctor
		Matrix() = default;

		// initializes from a set values
		Matrix(const std::array<T, C * R>& raw);

		// default dtor
		~Matrix() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - CAPACITY FUNCTIONS --------------------------------------------------------

		// get the number or rows
		static constexpr std::size_t rows();

		// get the number of columns
		static constexpr std::size_t columns();

		// get the number of total elements
		static constexpr std::size_t size();



		////////////////////////////////////////////////////////////////////////////////
		// - ELEMENT ACCESS ------------------------------------------------------------

		// access element at location
		T& at(const std::size_t c, const std::size_t r);

		// read element at location
		const T& at(const std::size_t c, const std::size_t r) const;

		// access row at location
		row_t& operator[](const std::size_t c);

		// access row at location
		const row_t& operator[](const std::size_t c) const;



		////////////////////////////////////////////////////////////////////////////////
		// - ARITHMETIC OPERATORS ------------------------------------------------------

		// multiply by a scalar value
		Matrix<T, C, R> operator*(const T scalar) const;

		// multiply by another matrix
		template<std::size_t S, std::size_t D,
			std::enable_if_t<C == D, int> = 0 // make sure the matricies can be multiplied
		>
		Matrix<T, S, D> operator*(const Matrix<T, S, D>& other) const;

	private:
		std::array<row_t, C> m_Mat;
	};



	template<class T, std::size_t C, std::size_t R>
	inline Matrix<T, C, R>::Matrix(const std::array<T, C * R>& raw)
	{
		for (std::size_t i = 0; i < C; i++)
			for (std::size_t j = 0; j < R; j++)
				m_Mat[i][j] = raw[i * C + j];
	}



	template<class T, std::size_t C, std::size_t R>
	inline constexpr std::size_t Matrix<T, C, R>::rows()
	{
		return R;
	}



	template<class T, std::size_t C, std::size_t R>
	inline constexpr std::size_t Matrix<T, C, R>::columns()
	{
		return C;
	}



	template<class T, std::size_t C, std::size_t R>
	inline constexpr std::size_t Matrix<T, C, R>::size()
	{
		return R * C;
	}



	template<class T, std::size_t C, std::size_t R>
	inline T& Matrix<T, C, R>::at(const std::size_t c, const std::size_t r)
	{
		return m_Mat[c][r];
	}



	template<class T, std::size_t C, std::size_t R>
	inline const T& Matrix<T, C, R>::at(const std::size_t c, const std::size_t r) const
	{
		return m_Mat[c][r];
	}



	template<class T, std::size_t C, std::size_t R>
	inline Matrix<T, C, R>::row_t& Matrix<T, C, R>::operator[](const std::size_t c)
	{
		return m_Mat[c];
	}



	template<class T, std::size_t C, std::size_t R>
	inline const Matrix<T, C, R>::row_t& Matrix<T, C, R>::operator[](const std::size_t c) const
	{
		return m_Mat[c];
	}



	template<class T, std::size_t C, std::size_t R>
	inline Matrix<T, C, R> Matrix<T, C, R>::operator*(const T scalar) const
	{
		Matrix<T, C, R> rmat;

		for (std::size_t i = 0; i < C; i++)
			for (std::size_t j = 0; j < R; j++)
				rmat = m_Mat[i][j] * scalar;

		return rmat;
	}



	template<class T, std::size_t C, std::size_t R>
	template<std::size_t S, std::size_t D,
		std::enable_if_t<C == D, int>
	>
	inline Matrix<T, S, D> Matrix<T, C, R>::operator*(const Matrix<T, S, D>& other) const
	{
		return Matrix<T, S, D>();
	}



	////////////////////////////////////////////////////////////////////////////////
	// - COMMON MATRIX DEFINITIONS -------------------------------------------------
	
	using Matrix44f = Matrix<float, 4, 4>;
	using Matrix44i = Matrix<int, 4, 4>;
	using Matrix33f = Matrix<float, 3, 3>;
	using Matrix33i = Matrix<int, 3, 3>;
}
