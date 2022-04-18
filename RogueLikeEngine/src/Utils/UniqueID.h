#pragma once

#include <cstddef>
#include <functional>

#include "NonCopyable.h"



namespace rle
{
	// provides unique IDing for any type T
	template<class T>
	class UniqueID final : NonCopyable
	{
		// static global size_t
		// holds the current id count for type T
		inline static std::size_t m_Global = 0;

	public:
		// get the global id
		static std::size_t global();

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// default ctor
		UniqueID();

		// default dtor
		~UniqueID() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - OBSERVATION FUNCTIONS -----------------------------------------------------
		
		// get the underlying ID
		std::size_t UID() const;

	private:
		std::size_t m_Local;
	};



	template<class T>
	inline std::size_t UniqueID<T>::global()
	{
		return m_Global;
	}



	template<class T>
	inline UniqueID<T>::UniqueID() : 
		m_Local(m_Global++)
	{

	}



	template<class T>
	inline std::size_t UniqueID<T>::UID() const
	{
		return m_Local;
	}
}



// Specialization of std::hash to allow for hashing of UniqueID
template<class T>
struct std::hash<rle::UniqueID<T>>
{

};
