/**
 * This program creates two matrices and executes some operations on them.
 * 
 * This is second problem of week 3.
 *
 * @author Mehmet Ali Özdemir
 * @since 21.10.2023
 *
 */
#include <iostream>
#include <vector>
#include <limits>

void display(std::vector<std::vector<int>> &matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			std::cout<<matrix[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

void fill(std::vector<std::vector<int>> &matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			std::cout<<"Enter value for ("<<i + 1<<", "<<j + 1<<"): ";
			int value;
			while (!(std::cin>>value)) {
		        std::cin.clear();
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		        std::cout << "Invalid input. Please enter a integer: ";
		    }
		    matrix[i][j] = value;
		}
	}
}

std::vector<std::vector<int>> addMatrix(std::vector<std::vector<int>> &first, std::vector<std::vector<int>> &second) {
	std::vector<std::vector<int>> result(first.size(), std::vector<int>(first[0].size(), 0));
	
	for (int i = 0; i < first.size(); i++) {
		for (int j = 0; j < first[i].size(); j++) {
			result[i][j] = first[i][j] + second[i][j];
		}
	}
	return result;
}

std::vector<std::vector<int>> subtractMatrix(std::vector<std::vector<int>> &first, std::vector<std::vector<int>> &second) {
	std::vector<std::vector<int>> result(first.size(), std::vector<int>(first[0].size(), 0));
	
	for (int i = 0; i < first.size(); i++) {
		for (int j = 0; j < first[i].size(); j++) {
			result[i][j] = first[i][j] - second[i][j];
		}
	}
	return result;
}

int main() {
	int row;
	int col;
	
	std::cout<<"Enter row and column of matrices: ";
	
	while (!(std::cin >> row >> col) || row <= 0 && col <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter positive integers for row and column: ";
    }

	std::vector<std::vector<int>> first(row, std::vector<int>(col, 0));
	std::vector<std::vector<int>> second(row, std::vector<int>(col, 0));
	
	std::cout<<"First matrix: \n";
	fill(first);
	
	std::cout<<"\nSecond matrix: \n";
	fill(second);

	std::vector<std::vector<int>> sum = addMatrix(first, second);
	std::vector<std::vector<int>> diff = subtractMatrix(first, second);
	
	std::cout<<"\nFirst matrix: \n";
	display(first);
	
	std::cout<<"\nSecond matrix: \n";
	display(second);
	
	std::cout<<"\nSum matrix: \n";
	display(sum);
	
	std::cout<<"\nSubtraction matrix: \n";
	display(diff);
}
