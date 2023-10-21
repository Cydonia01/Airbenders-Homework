/**
 * This program finds the second greatest number in an array.
 * 
 * This is the first problem of week 3.
 *
 * @author Mehmet Ali Özdemir
 * @since 21.10.2023
 *
 */
 
#include<iostream>
#include <limits>

template <typename T>
class Array {
private:
	T* arr;
	int arraySize;
public:
	Array(int size) {
		arr = new T[size];
		arraySize = size;
	}
	
	~Array() {
		delete[] arr;
	}
	
	T& operator[](int index) {
		return arr[index];
	}
	
	int size() {
		return arraySize;
	}
};

template <typename T>
int secondGreatest(Array<T> &arr) {
	T minNum = std::numeric_limits<T>::min();
	int best = minNum;
	int second = minNum;
	
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > best)
			best = arr[i];
	}
	
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < best && arr[i] > second)
			second = arr[i];
	}
	return (second == minNum) ? 1:second; 
}

int main() {
	int size;
	
	std::cout<<"Enter the size of the array: ";
	std::cin>>size;
	
	Array<int> myArr(size);
	
	std::cout<<"Enter elements: ";
	
	for (int i = 0; i < myArr.size(); i++) {
		std::cin>>myArr[i];
	}
	
	std::cout<<"The second greatest element is: "<<secondGreatest(myArr);
}
