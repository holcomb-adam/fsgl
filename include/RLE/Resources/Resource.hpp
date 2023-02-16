#pragma once

// --- Standard ---
#include <string>

// --- RLE ---
#include "RLE/Utils/UniqueID.hpp"



namespace rle
{
	class Resource
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC DATA ---------------------------------------------------------------

		// Unique Identifier
		UniqueID<Resource> UID;


			
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Deleted Default Constructor
		Resource() = delete;

		// Constructor
		Resource(const bool local, const std::string& name, const std::string& path);

		// [Deleted] [Copy-Constuctor]
		Resource(const Resource&) = delete;


		// Virtual Default Constructor
		virtual ~Resource() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get flag if resource is local
		bool getIsLocal() const;

		// Get the name of the resource
		const std::string& name() const;

		// Get the path of the resource
		const std::string& path() const;



	private:
		bool m_Local = false;
		std::string m_Name;
		std::string m_Path;
	};
}
