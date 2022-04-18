#pragma once

namespace rle
{
	class NonCopyable
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------
		
		// default ctor
		NonCopyable() = default;

		// deleted copy constructor
		NonCopyable(const NonCopyable&) = delete;

		// virtual default dtor
		virtual ~NonCopyable() = default;

		// deleted copy assignment operator
		NonCopyable& operator=(const NonCopyable&) = delete;
	};
}