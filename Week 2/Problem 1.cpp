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

bool coprimeCheck(int p, int n) {
	for (int i = 2; i <= n/2; i++) {
		if (p % i == 0 && n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int p;
	std::vector<int> list;
	std::cin>>p;
	for (int i = 2; i < p; i++) {
		if (coprimeCheck(p, i)) {
			int count = 1;
			bool found = false;
			while (!found) {
				if ((int)pow(i, count) % p == 1) {
					found = true;
					list.push_back(count);
				}
				count++;
			}
		}
	}
	for (int i = 0; i < list.size(); i++) {
		std::cout<<list[i]<<" ";
	}
	return 0;
}
