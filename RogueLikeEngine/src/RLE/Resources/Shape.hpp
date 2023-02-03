#pragma once

// --- GLM ---
#include <glm/vec2.hpp>

// --- Standard ---
#include <vector>

// --- RLE ---
#include "Resource.hpp"



namespace rle
{
	// FIXME: This class represents a 2D shape however thats not inheritly obvious.
	//		  Meant as a temporary placeholder class for testing.
	
	// A class that represents a shape resource holding polygon information 
	// for a given shape.
	class Shape : public Resource
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
		Shape();

		// Constructor
		// Loads the shape from memory
		Shape(const std::vector<glm::vec2>& poly);

		// Constructor
		// Loads the shape from the disk
		Shape(const std::string& path);

		// Virtual Defualt Destructor
		virtual ~Shape() = default;



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
		// --- Polygon Data ---
		std::vector<glm::vec2> m_Polygon;
	};
}
