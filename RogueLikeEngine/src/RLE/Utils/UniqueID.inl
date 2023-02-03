template<class T>
inline std::size_t rle::UniqueID<T>::global()
{
	return m_Global;
}



template<class T>
inline rle::UniqueID<T>::UniqueID() : 
	m_Local(m_Global++)
{

}



template<class T>
inline bool rle::UniqueID<T>::operator==(const UniqueID<T>& other) const
{
	return m_Local == other.m_Local;
}



template<class T>
inline bool rle::UniqueID<T>::operator!=(const UniqueID<T>& other) const
{
	return m_Local != other.m_Local;
}



template<class T>
inline std::size_t rle::UniqueID<T>::UID() const
{
	return m_Local;
}
