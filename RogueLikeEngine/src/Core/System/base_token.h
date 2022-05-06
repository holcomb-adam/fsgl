#pragma once

namespace rle
{
	namespace detail
	{
		// This empty struct should be inherited by every
		// rle class / struct at base level
		struct base_token {};

		// i.e.
		// ~~~ Inheritance Heirarchy ~~~~~~~~~~~~~~~~~~~~
		// 
		//   o-----------------o   o-------------------o
		//   | some_util_class |   | some_detail_class | 
		//   o-----------------o   o-------------------o
		//         |                         |
		//         v                         |
		// o-----------------o               |
		// | some_class_base | <-------------/
		// o-----------------o
		//         |
		//         v
		// o------------------------o     o------------o
		// | some_rle_derived_class | <---| base_token |
		// o------------------------o     o------------o
	}
}