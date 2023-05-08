template<class T>
inline std::size_t fsgl::UniqueID<T>::global()
{
	return m_Global;
}



template<class T>
inline fsgl::UniqueID<T>::UniqueID() : 
	m_Local(m_Global++)
{

}



template<class T>
inline bool fsgl::UniqueID<T>::operator==(const UniqueID<T>& other) const
{
	return m_Local == other.m_Local;
}



template<class T>
inline bool fsgl::UniqueID<T>::operator!=(const UniqueID<T>& other) const
{
	return m_Local != other.m_Local;
}



template<class T>
inline std::size_t fsgl::UniqueID<T>::raw() const
{
	return m_Local;
}
