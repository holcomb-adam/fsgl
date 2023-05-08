#pragma once

// --- Standard ---
#include <functional>

// --- FSGL ---
#include "NonCopyable.hpp"



namespace fsgl
{
	// Provides unique IDing for any type T
	template<class T>
	class UniqueID final : NonCopyable
	{
		// Holds the current ID count for type T
		inline static std::size_t m_Global = 0;



	public:
		// get the global id
		static std::size_t global();



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		UniqueID();

		// Default destructor
		~UniqueID() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - COMPARISON ----------------------------------------------------------------

		// Overloaded comparison operator
		bool operator==(const UniqueID<T>& other) const;

		// Overloaded decomparison operator
		bool operator!=(const UniqueID<T>& other) const;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the underlying ID
		std::size_t raw() const;



	private:
		std::size_t m_Local;
	};



	// --- Inline Definition ---
#	include "UniqueID.inl"

}



// Specialization of std::hash to allow for hashing of UniqueID
template<class T>
struct std::hash<fsgl::UniqueID<T>>
{
	std::size_t operator()(const fsgl::UniqueID<T>& uid) const
	{
		return hash(uid.UID());
	}
};
