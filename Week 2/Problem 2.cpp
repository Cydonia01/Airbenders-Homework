/**
 * This program checks if a sentence is palindrome or not.
 * 
 * This is second problem of week 2.
 *
 * @author Mehmet Ali Özdemir
 * @since 21.10.2023
 *
 */
 
#include<iostream>
#include<cctype>
#include<string>

bool isPalindrome(std::string line) {
	int l = 0;
	int r = line.length() - 1;
	
	while (l <= r) {
		if (!isalnum(line[l])) {
			l++;
			continue;
		}
		if (!isalnum(line[r])) {
			r--;
			continue;
		}
		if (tolower(line[l]) == tolower(line[r])) {
			l++;
			r--;
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	std::string line;
	char check = 'y';
	std::string palCheck;
	
	while (check == 'y' || check == 'Y') {
		std::cout<<"Enter a line: ";
		std::getline(std::cin, line);
		
		palCheck = isPalindrome(line) ? "Yes it's a palindrome":"No it's not a palindrome";
		std::cout<<palCheck<<std::endl;
		
		std::cout<<"Do you want to check another string? (y/n)"<<std::endl;
		std::cin>>check;
		std::cin.ignore(INT_MAX, '\n');
	}
	
	return 0;
}
