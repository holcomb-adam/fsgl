#include "Node.hpp"

#include "impl/node_helpers.hpp"



template<class T, class ...Targs>
inline T& fsgl::Node::addComponent(Targs&&... targs)
{
    auto* ptr = new T(std::forward<Targs>(targs)...);
    auto& uptr = (*m_Components.emplace(
        impl::getComponentTypeID<T>(),
        std::move(std::unique_ptr<Aspect>(ptr))).first).second;
    uptr->m_Owner = this;
    uptr->onInit();
    return *ptr;
}

template<class T>
inline T& fsgl::Node::getComponent()
{
    return *static_cast<T*>(m_Components.at(impl::getComponentTypeID<T>()).get());
}

template<class T>
inline const T & fsgl::Node::getComponent() const
{
    return *static_cast<const T*>(m_Components.at(impl::getComponentTypeID<T>()).get());
}

template<class T>
inline bool fsgl::Node::hasComponent() const
{
    return m_Components.find(impl::getComponentTypeID<T>()) != m_Components.end();
}
