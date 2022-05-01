#pragma once

#include <array>



namespace rle
{
	template<class T, std::size_t M, std::size_t N>
	class Matrix final
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// default ctor
		Matrix();

		// initializes from a set values
		Matrix(const std::array<T, M * N>& raw);

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

		// get the underlying array
		const std::array<T, M * N>& underlying() const;




		////////////////////////////////////////////////////////////////////////////////
		// - ARITHMETIC OPERATTIONS ----------------------------------------------------

		// calculate a dot product from a vector
		std::array<T, M> dotProduct(const std::array<T, M>& vec) const;


		////////////////////////////////////////////////////////////////////////////////
		// - ARITHMETIC OPERATORS ------------------------------------------------------

		// multiply by a scalar value
		Matrix<T, M, N> operator*(const T scalar) const;

		// multiply by another matrix
		template<std::size_t P>
		Matrix<T, M, P> operator*(const Matrix<T, N, P>& other) const;

	private:
		std::array<T, M * N> m_Mat;
	};



	template<class T, std::size_t C, std::size_t R>
	inline Matrix<T, C, R>::Matrix()
	{
		m_Mat.fill(0);
	}



	template<class T, std::size_t M, std::size_t N>
	inline Matrix<T, M, N>::Matrix(const std::array<T, M * N>& raw) : 
		m_Mat(raw)
	{

	}



	template<class T, std::size_t M, std::size_t N>
	inline constexpr std::size_t Matrix<T, M, N>::rows()
	{
		return N;
	}



	template<class T, std::size_t M, std::size_t N>
	inline constexpr std::size_t Matrix<T, M, N>::columns()
	{
		return M;
	}



	template<class T, std::size_t M, std::size_t N>
	inline constexpr std::size_t Matrix<T, M, N>::size()
	{
		return M * N;
	}



	template<class T, std::size_t M, std::size_t N>
	inline T& Matrix<T, M, N>::at(const std::size_t c, const std::size_t r)
	{
		return m_Mat[r * M + c];
	}



	template<class T, std::size_t M, std::size_t N>
	inline const T& Matrix<T, M, N>::at(const std::size_t c, const std::size_t r) const
	{
		return m_Mat[r * M + c];
	}



	template<class T, std::size_t M, std::size_t N>
	inline const std::array<T, M* N>& Matrix<T, M, N>::underlying() const
	{
		return m_Mat;
	}



	template<class T, std::size_t M, std::size_t N>
	inline std::array<T, M> Matrix<T, M, N>::dotProduct(const std::array<T, M>& vec) const
	{
		std::array<T, M> vec;
		vec.fill(0);
	}



	template<class T, std::size_t M, std::size_t N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator*(const T scalar) const
	{
		Matrix<T, M, N> rmat;

		for (std::size_t i = 0; i < N; i++)
			for (std::size_t j = 0; j < M; j++)
				rmat = m_Mat[i * M + j] * scalar;

		return rmat;
	}


	
	template<class T, std::size_t M, std::size_t N>
	template<std::size_t P>
	inline Matrix<T, M, P> Matrix<T, M, N>::operator*(const Matrix<T, N, P>& other) const
	{
		Matrix<T, M, P> mmat;

		for (std::size_t i = 0; i < N; i++)
			for (std::size_t j = 0; j < P; j++)
				for (std::size_t k = 0; k < N; k++)
					mmat.at(j, i) += at(i, k) * other.at(k, j);
				
		return mmat;
	}



	////////////////////////////////////////////////////////////////////////////////
	// - COMMON MATRIX DEFINITIONS -------------------------------------------------
	
	using Matrix44f = Matrix<float, 4, 4>;
	using Matrix44i = Matrix<int, 4, 4>;

	using Matrix33f = Matrix<float, 3, 3>;
	using Matrix33i = Matrix<int, 3, 3>;
}
