/**
 * This program creates a matrix and fills it according to command line prompts.
 * 
 * This is first problem of week 4.
 *
 * @author Mehmet Ali Özdemir
 * @since 5.11.2023
 *
 */
#include <iostream>

int main(int argc, char* argv[]) {
	int cf = (int) argv[1][0] - 48;
	int row = (int) argv[2][0] - 48;

	int matrix[row][row];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			matrix[i][j] = (int) argv[3][i * row + j] - 48;
			if (i == 0) {
				std::cout<<matrix[i][j] * cf<<" ";
			}
			else {
				std::cout<<matrix[i][j]<<" ";
			}
		}
		std::cout<<std::endl;
	}
	return 0;
}
