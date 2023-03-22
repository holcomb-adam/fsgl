#include "Node.hpp"

#include "impl/RLE_Node.hpp"



template<class T, class ...Targs>
inline T& rle::Node::addComponent(Targs&&... targs)
{
    auto* ptr = new T(std::forward<Targs>(targs)...);
    auto& uptr = (*m_Components.emplace(
        impl::getComponentTypeID<T>(),
        std::move(std::unique_ptr<Component>(ptr))).first).second;
    uptr->m_Owner = this;
    uptr->onInit();
    return *ptr;
}

template<class T>
inline T& rle::Node::getComponent()
{
    return *static_cast<T*>(m_Components.at(impl::getComponentTypeID<T>()).get());
}

template<class T>
inline const T & rle::Node::getComponent() const
{
    return *static_cast<const T*>(m_Components.at(impl::getComponentTypeID<T>()).get());
}

template<class T>
inline bool rle::Node::hasComponent() const
{
    return m_Components.find(impl::getComponentTypeID<T>()) != m_Components.end();
}
