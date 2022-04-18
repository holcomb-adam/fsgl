#pragma once

#include <memory>
#include <unordered_map>

#include "Utils/UniqueID.h"



namespace rle
{
	template<class T>
	class FiniteStateMachine
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC MEMBERS ------------------------------------------------------------

		// default ctor
		FiniteStateMachine() = default;

		// virtual default dtor
		virtual ~FiniteStateMachine() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - ELEMENT ACCESS ------------------------------------------------------------

		// check if the state stack is empty
		bool empty() const;



		////////////////////////////////////////////////////////////////////////////////
		// - ELEMENT ACCESS ------------------------------------------------------------

		// get a reference to the top state
		T& topState();

		// get a const reference to the top state
		const T& topState() const;



		////////////////////////////////////////////////////////////////////////////////
		// - ELEMENT MANIPULATION ------------------------------------------------------

		// add a state to the stack
		template<class U, class... Targs>
		U& pushState(Targs&&... targs);

	private:
		std::vector<std::unique_ptr<T>> m_StateStack;
	};



	template<class T>
	inline bool FiniteStateMachine<T>::empty() const
	{
		return m_StateStack.empty();
	}



	template<class T>
	inline T& FiniteStateMachine<T>::topState()
	{
		return *m_StateStack.back().get();
	}



	template<class T>
	inline const T& FiniteStateMachine<T>::topState() const
	{
		return *m_StateStack.back().get();
	}



	template<class T>
	template<class U, class ...Targs>
	inline U& FiniteStateMachine<T>::pushState(Targs&& ...targs)
	{
		U* state = new U(std::forward<Targs>(targs)...);
		state->onEnter();
		m_StateStack.emplace_back(state);

		return *state;
	}
}
