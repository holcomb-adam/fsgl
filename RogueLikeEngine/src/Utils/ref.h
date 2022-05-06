#pragma once



namespace rle
{
	template<class T>
	class ref final
	{
	public:
		// default ctor
		ref() = default;

		// ctor,
		// set the reference value
		ref(T& t);

		operator T& () const;

		T& get();


		void bind(T& binder);

	private:
		T* ptr = nullptr;
	};



	template<class T>
	inline ref<T>::ref(T& t) : 
		ptr(&t)
	{

	}



	template<class T>
	inline ref<T>::operator T& () const
	{
		return *ptr;
	}



	template<class T>
	inline T& ref<T>::get()
	{
		return *ptr;
	}



	template<class T>
	inline void ref<T>::bind(T& binder)
	{
		ptr = binder;
	}
}