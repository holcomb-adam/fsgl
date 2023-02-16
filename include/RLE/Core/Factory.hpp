#pragma once



namespace rle
{
	// Here is the RLE factory class ("struct").
	// - This class is the main construction facility for RLE. For external dependencies,
	//     RLE utilizes abstraction to hide them from the global namespace for the users
	//	   sake. Since a majority of the API is abstracted, there is no easy construction
	//     of objects and we need to provide a means for construction. The factory class
	//     provides seperate and explicit access to these funtions.
	//     - Example: i.e. "rle::factory<my_class>::create()" over "rle::my_class::create()"
	// - Factory is specializable and in the public API, feel free to utilize.
	// - One of the major reasons for using a struct over a namespace is using a template
	//     to be as explicit as possible.
	


	// The factory class (struct)
	// - Specializable for creation of custom abstracts
	// - Really an explicit means of organizing API construction tools
	template<class T>
	struct factory final { };
}





// This is placed in factory specializations to remove the constructors of the factory 
// object. This is optional but advised.
#define RLE_FACTORY_NO_CTOR() /*******/ \
	factory() = delete;					\
	factory(const factory&) = delete;	\
	factory(factory&&) = delete;		
