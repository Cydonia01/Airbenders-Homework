/**
 * This program implements Vector class and executes some operations on vectors.
 * 
 * This is first problem of week 5.
 *
 * @author Mehmet Ali Özdemir
 * @since 24.10.2023
 *
 */

#include <iostream>
#include <math.h>
#include <limits>

template <typename T>
class Vector {
private:
	T x;
	T y;
public:
	
	Vector() {}
	
	Vector(T x, T y) {
		this->x = x;
		this->y = y;
	}
	
	Vector operator+(Vector v) {
		Vector<T> sum;
		sum.x = this->x + v.x;
		sum.y = this->y + v.y;
		return sum;
	}
	
	Vector operator-(Vector v) {
		Vector<T> diff;
		diff.x = this->x - v.x;
		diff.y = this->y - v.y;
		return diff;
	}
	
	Vector operator*(T m) {
		Vector<T> sum;
		sum.x = this->x * m;
		sum.y = this->y * m;
		return sum;
	}
	
	Vector operator/(T m) {
		Vector<T> sum;
		sum.x = this->x / m;
		sum.y = this->y / m;
		return sum;
	}
	
	double length() {
		return sqrt(pow(this->x, 2) + pow(this->y, 2));
	}
	
	friend std::ostream & operator<<(std::ostream &os, Vector &v) {
		os<<v.x<<"i"<<" + "<<v.y<<"j";
		return os;
	}	
};

int main(int argc, char* argv[]) {
	double x1, y1;
	double x2, y2;
	int num;
	char op;
	
	std::cout<<"Enter components of first vector: ";
	while (!(std::cin>>x1>>y1)) {
	    std::cout<<"Invalid input. Please enter numeric values for x1 and y1."<<std::endl;
	    std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	std::cout<<"Enter components of second vector: ";
	while (!(std::cin>>x2>>y2)) {
	    std::cout<<"Invalid input. Please enter numeric values for x2 and y2."<<std::endl;
	    std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout<<std::endl;
	
	Vector<double> v1(x1, y1);
	Vector<double> v2(x2, y2);
	Vector<double> v3;
	
	while (true) {
		std::cout<<"Which operation do you want to do?"<<std::endl;
		std::cout<<"1. Enter '+' to add up two vectors."<<std::endl;
		std::cout<<"2. Enter '-' to take difference of two vectors."<<std::endl;
		std::cout<<"3. Enter '*' to perform scalar multiplication on first vector."<<std::endl;
		std::cout<<"4. Enter '/' to perform scalar division on first vector."<<std::endl;
		std::cout<<"5. Enter 'l' to print the length of first vector."<<std::endl;
		std::cout<<"6. Enter 'e' to exit the program."<<std::endl;
		std::cin>>op;
		
		if (op == 'e') break;
		
		else if (op == 'l')
			std::cout<<"Length of the first vector: "<<v1.length()<<std::endl<<std::endl;
		else {	
			if (op == '+')
				v3 = v1 + v2;
				
			if (op == '-')
				v3 = v1 - v2;
				
			if (op == '*') {
				std::cout<<"Enter a number: ";
				std::cin>>num;
				v3 = v1 * num;
			}
			
			if (op == '/') {
				std::cout<<"Enter a number: ";
				std::cin>>num;
				v3 = v1 / num;
			}
			std::cout<<"Final vector: "<<v3<<std::endl<<std::endl;
		}
	}
	return 0;
}
