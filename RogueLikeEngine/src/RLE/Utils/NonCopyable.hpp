#pragma once



namespace rle
{
	class NonCopyable
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------
		
		// Default constructor
		NonCopyable() = default;

		// Deleted copy constructor
		NonCopyable(const NonCopyable&) = delete;

		// Virtual default destructor
		virtual ~NonCopyable() = default;

		// Deleted copy assignment operator
		NonCopyable& operator=(const NonCopyable&) = delete;
	};
}