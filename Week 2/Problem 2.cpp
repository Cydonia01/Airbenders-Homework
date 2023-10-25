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
#include<limits>

bool isPalindrome(std::string line) {
	int l = 0;
	int r = line.length() - 1;
	
	while (l < r) {
		if (!isalnum(line[l])) {
			l++;
		}
		else if (!isalnum(line[r])) {
			r--;
		}
		else if (tolower(line[l]) == tolower(line[r])) {
			l++;
			r--;
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
	
	while (check == 'y') {
		std::cout<<"Enter a line: ";
		std::getline(std::cin, line);
		
		palCheck = isPalindrome(line) ? "Yes it's a palindrome":"No it's not a palindrome";
		std::cout<<palCheck<<std::endl;
		
		std::cout<<"Do you want to check another string? (y/n)"<<std::endl;
		
		while (!(std::cin>>check) || check != 'y' && check != 'n') {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"Please enter a valid input!"<<std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	return 0;
}
