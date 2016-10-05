#pragma once
#include <math.h>


template<typename T>
class THeap
{
private:
	int capacity = 0;
	int arrsize = 0;
	T* arr = nullptr;
	void enlargeArray();
	void siftUp(int index);
	void siftDown();
	void swap(int index1, int index2);
	int parent(int child);
	int rightChild(int parent);
	int leftChild(int parent);

public:
	THeap();
	~THeap();
	THeap(int sz);
	int size();
	T front();
	void push_back(const T & value);
	bool pop_back(T & outValue);
	bool empty();
};

template<typename T>
THeap<T>::THeap()
{
	capacity = 1;
	arr = new T[capacity];
}

template<typename T>
THeap<T>::~THeap()
{
	delete[] arr;
}

template<typename T>
THeap<T>::THeap(int sz)
{
	capacity = sz;
	arr = new T[capacity];
}

template<typename T>
int THeap<T>::size()
{
	if (arr == nullptr) {
		return 0;
	}

	return arrsize;
}

template<typename T>
T THeap<T>::front()
{
	T front;
	if (arr == nullptr) {
		return arr[0];
	}

	if (size() >= 1) {
		return arr[0];
	}
	else return arr[0];
}

template<typename T>
void THeap<T>::push_back(const T &value)
{
	if(arrsize == capacity){
		enlargeArray();
		//cout << "Array is full" << endl;
	}

	arr[arrsize] = value;
	arrsize++;
	siftUp(arrsize-1);

}

template<typename T>
bool THeap<T>::pop_back(T &outValue)
{
	if (arrsize == 0)
	{
		return false;
	}

	//set outvalue to the top value
	outValue = front();

	//switch top with bottom populated value
	swap(0, arrsize-1);

	//arr[arrsize - 1] = -1; //dont think i need to set the value

	//decrement size
	arrsize--;

	//sift the switched value down
	siftDown();

	//return true if you popped an actual value
	return true;
}

template<typename T>
bool THeap<T>::empty()
{
	if (arrsize == 0) {
		return true;
	}
	else return false;
}

template<typename T>
void THeap<T>::enlargeArray()
{

	capacity = capacity * 2; //double array capacity

	T* tempArr = new T[capacity];

	memcpy_s(tempArr, capacity * 2 * sizeof(T), arr, capacity*sizeof(T));
	delete[] arr;

	arr = new T[capacity];
	memcpy_s(arr, capacity*sizeof(T), tempArr, capacity*sizeof(T));
	delete[] tempArr;

	//tempArr = (T*)realloc(arr, sizeof(T) * capacity);

	//arr = tempArr;
}

template<typename T>
void THeap<T>::siftUp(int index)
{
	bool inSpot = false;
	while (!inSpot) {
		if (index == 0) 
		{
			inSpot = true;
		}
		else if (arr[index] > arr[parent(index)]) //if the number sifting up is larger than the next number we good
		{
			inSpot = true;
		}
		else { //if it's smaller we got more work
			swap(index, parent(index));
			index = parent(index);
		}
	}
}

template<typename T>
void THeap<T>::siftDown()
{
	bool inSpot = false;
	int index = 0;
	int lChild;
	int rChild;
	while (!inSpot) {
		lChild = leftChild(index);
		rChild = rightChild(index);
		if (lChild >= arrsize || rChild >= arrsize) //if the children are outside the scope of the array, you are at the bottom and have sifted all the way down.
		{
			inSpot = true;
			break;
		}
		if (lChild < arrsize && rChild < arrsize && arr[index] < arr[lChild] && arr[index] < arr[rChild]) //if the current number is less than both it's children it's done
		{
			inSpot = true;
		}
		else //otherwise swap it with other things
		{
			if (arr[index] > arr[lChild])
			{
				swap(index, lChild);
				index = lChild;
			}
			else
			{
				swap(index, rChild);
				index = rChild;
			}
		}
	}
}

template<typename T>
void THeap<T>::swap(int index1, int index2)
{
	T num1 = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = num1;
}

template<typename T>
int THeap<T>::parent(int child)
{
	if (child == 0)
	{
		return -1;
	}
	
	return (int)floor((child-1)/2);
}

template<typename T>
int THeap<T>::leftChild(int parent)
{
	return  ((2 * parent) + 1);
}

template<typename T>
int THeap<T>::rightChild(int parent)
{
	return ((2 * parent) + 2);
}