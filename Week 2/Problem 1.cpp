/**
 * This program finds the order of positive integers of a prime number.
 * 
 * This is the first problem of week 2.
 *
 * @author Mehmet Ali Özdemir
 * @since 21.10.2023
 *
 */
 
#include<iostream>
#include<vector>
#include<cmath>

bool coprimeCheck(int primeNum, int div) {
	for (int i = 2; i <= div/2; i++) {
		if (primeNum % i == 0 && div % i == 0)
			return false;
	}
	return true;
}

int main() {
	int primeNum;
	std::vector<int> orderList;
	std::cin>>primeNum;
	for (int i = 2; i < primeNum; i++) {
		if (coprimeCheck(primeNum, i)) {
			int count = 1;
			bool found = false;
			while (!found) {
				if (static_cast<int>(pow(i, count)) % primeNum == 1) {
					found = true;
					orderList.push_back(count);
				}
				count++;
			}
		}
	}
	for (int i = 0; i < orderList.size(); i++) {
		std::cout<<orderList[i]<<" ";
	}
	return 0;
}
