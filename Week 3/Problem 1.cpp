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
		if (arr[i] > best){
			second = best;
			best = arr[i];
		}
		else if (arr[i] > second && arr[i] != best)
			second = arr[i];
	}
	return (second == minNum) ? 1:second;
}

int main(int argc, char **argv) {
	int size;
	
	std::cout<<"Enter the size of the array: ";
	std::cin>>size;
	
	Array<int> myArr(size);
	
	std::cout<<"Enter elements: ";
	
	for (int i = 0; i < myArr.size(); i++) {
		std::cin>>myArr[i];
	}
	
	int result = secondGreatest(myArr);
	std::cout<<"Second greatest element is: "<<result;
}

