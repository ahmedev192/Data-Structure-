#include "_Vector.h"
#include <iostream>
#include <cassert>

using namespace std;


template <typename T>
void _Vector<T>::expandCapacity() {
	// Double the actual array size
	capacity *= 2;
	cout << "Expand capacity to " << capacity << "\n";
	T* arr2 = new T[capacity]{};
	for (int i = 0; i < size; ++i)
		arr2[i] = arr[i]; // copy data

	swap(arr, arr2);
	delete[] arr2;
}

template <typename T>
_Vector<T>::_Vector() {

	size = 0;
	capacity = size + 10;
	// The actual size array will
	// be bigger than needed
	arr = new T[capacity]{};
}

template <typename T>
_Vector<T>::~_Vector() {
	delete[] arr;
	arr = nullptr;
}

template <typename T>
int _Vector<T>::getSize() {
	return size;
}

template <typename T>
T _Vector<T>::get(int idx) {
	assert(0 <= idx && idx < size);
	return arr[idx];
}

template <typename T>
void _Vector<T>::set(int idx, T val) {
	assert(0 <= idx && idx < size);
	arr[idx] = val;
}

template <typename T>
void _Vector<T>::printAll() {
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

template <typename T>
int _Vector<T>::find(T value) {
	for (int i = 0; i < size; ++i)
		if (arr[i] == value)
			return i;
	return -1; // -1 for NOT found
}

template <typename T>
T _Vector<T>::getFront() {
	return arr[0];
}

template <typename T>
T _Vector<T>::getBack() {
	return arr[size - 1];
}

template <typename T>
void _Vector<T>::pushBack(T value) {
	// we can't add any more
	if (size == capacity)
		expandCapacity();
	arr[size++] = value;
}

template <typename T>
void _Vector<T>::insert(int idx, T value) {
	assert(idx >= 0 && idx <= size);
	if (idx == size) {
		pushBack(value);
	}
	else {
		if (size == capacity)
			expandCapacity();
		size++;
		for (int i = size; i > idx; i--) {
			arr[i] = arr[i - 1];
		}
		arr[idx] = value;
	}
}

template <typename T>
void _Vector<T>::rotateVector() {
	if (size <= 1) {
		// Nothing to rotate if the vector has 0 or 1 elements
		return;
	}

	int mid = size / 2;
	cout << mid;
	for (int i = 0; i < mid; i++) {
		swap(arr[i], arr[size - i - 1]);
	}
}

template <typename T>
void _Vector<T>::rightRotate(int steps) {

	assert(steps <= size);
	// Nothing to rotate if the vector has 0 or 1 elements
	if (size <= 1)
		return;

	// Use a temporary array to store the rotated elements
	T* temp_values = new T[steps];

	// Copy the last 'steps' elements to temp_values
	for (int i = 0; i < steps; ++i) {
		temp_values[i] = arr[size - steps + i];
	}

	// Shift the remaining elements to the right
	for (int i = size - 1; i >= steps; --i) {
		arr[i] = arr[i - steps];
	}

	// Copy back the rotated elements from temp_values to the beginning of arr
	for (int i = 0; i < steps; ++i) {
		arr[i] = temp_values[i];
	}

	delete[] temp_values; // Free the memory allocated with new
}

template <typename T>
void _Vector<T>::pop() {
	assert(size > 0);
	size--;
}

template <typename T>
void _Vector<T>::deleteElement(int idx) {
	assert(idx >= 0 && idx < size);
	for (int i = idx; i < size-1 ; i++) {
		arr[i] = arr[i + 1];
	}
	size --;
}
