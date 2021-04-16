#pragma once
#include <string.h>
template<typename T>
class DynamicArray
{
private:
	int startSize;
	int currSize;
	int tailIndex = 0;
	T* arr;
public:
	DynamicArray();
	void resizeArray();
	void add(const T&); // move semantics function
	void add(T*); // 
	void remove(const int&);
	T* operator[](const int&) const;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
	: startSize(1), currSize(1)
{
	arr = new T[startSize];
}

template<typename T>
inline void DynamicArray<T>::resizeArray()
{
	int newSize = currSize * 2;
	T* newArray = new T[newSize];

	memcpy(newArray, arr, currSize * sizeof(T));

	delete[]arr;
	arr = newArray;
	currSize = newSize;
}

template<typename T>
inline void DynamicArray<T>::add(const T& object)
{
	if (tailIndex >= currSize) resizeArray();
	std::cout << object << " : " << &object << std::endl;
	arr[tailIndex++] = std::move(object); // move the data that was passed
	std::cout << object << " : " << &object << std::endl;

	std::cout << &arr[tailIndex - 1]  << " : " << arr[tailIndex - 1] << std::endl;
}

template<typename T>
inline void DynamicArray<T>::add(T* object)
{
	if (tailIndex >= currSize) resizeArray();
	arr[tailIndex++] = *(object); // move the data that was passed

	std::cout << object << std::endl;
	std::cout << &arr[tailIndex - 1] << std::endl;
}

template<typename T>
inline void DynamicArray<T>::remove(const int& index)
{
}

template<typename T>
inline T* DynamicArray<T>::operator[](const int& index) const
{
	return &arr[index];
}