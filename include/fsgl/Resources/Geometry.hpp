#pragma once

// --- GLM ---
#include <glm/vec2.hpp>

// --- Standard ---
#include <vector>

// --- FSGL ---
#include "Resource.hpp"



namespace fsgl
{
	/// @bug This class represents a 2D shape however thats not inheritly obvious
	
	
	
	/// @brief A class that represents a shape resource holding polygon information 
	/// for a given shape.
	class Geometry : public Resource
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - MEMBER TYPES --------------------------------------------------------------

		// Iterator type
		using iterator = std::vector<glm::vec2>::iterator;



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------
		
		// Default Constructor
		Geometry();

		// Constructor
		// Loads the shape from memory
		Geometry(const std::vector<glm::vec2>& vertices);

		// Constructor
		// Loads the shape from the disk
		Geometry(const std::string& path);

		// Virtual Defualt Destructor
		virtual ~Geometry() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - MANIPULATORS --------------------------------------------------------------
		
		// Load Shape from memory
		void load(const glm::vec2* data, const std::size_t n);

		// Load shape from disk
		bool load(const std::string& path);



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the number of verticies in the shape
		std::size_t count() const;

		// Get the polygon data
		const glm::vec2* data() const;

		// Get the indicies of the shape
		std::vector<std::uint32_t> indices() const;



	private:
		// --- Vertex Data ---
		std::vector<glm::vec2> m_Vertices;
	};
}
