#pragma once

// Standard Library includes
#include <vector>



namespace rle
{
	// RLE Forward Declaration
	class Layer;



	class LayerStack final
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - MEMBER TYPES --------------------------------------------------------------

		// Iterator type
		using iterator = std::vector<Layer*>::iterator;

		// Reverse iterator type
		using reverse_iterator = std::vector<Layer*>::reverse_iterator;



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------
		
		// Default constructor
		LayerStack() = default;

		// Default destructor
		~LayerStack() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - MANIPULATORS --------------------------------------------------------------

		// Add a layer to the stack
		// - Calls 'onEnter' for the layer
		void push(Layer* layer);

		// Add a lyer as an overlay
		// - Rendered after all the other layers
		// - Calls 'onEnter' for the layer
		void pushOverlay(Layer* layer);



		////////////////////////////////////////////////////////////////////////////////
		// - ITERATORS -----------------------------------------------------------------

		// Begining iterator
		iterator begin();

		// Ending iterator
		iterator end();

		// Reverse begining iterator
		reverse_iterator rbegin();

		// Reverse ending iterator
		reverse_iterator rend();



	private:
		std::vector<Layer*> m_Layers;
		std::size_t m_LayerInsert = 0;
	};
}
