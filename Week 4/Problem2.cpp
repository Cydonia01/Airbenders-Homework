/**
 * This program reads a file and writes something to another file
 * 
 * This is second problem of week 4.
 *
 * @author Mehmet Ali Özdemir
 * @since 5.11.2023
 *
 */
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

std::vector<std::string> getWords(std::string line) {
	std::vector<std::string> res;
	int pos = 0;
	while (pos < line.size()) {
		pos = line.find(";");
		res.push_back(line.substr(0, pos));
		line.erase(0, pos + 1);
	}
	return res;
}

int main(int argc, char* argv[]) {
	std::ifstream inputFile("myFile.csv");
	std::vector<std::string> vect;
	
	if (!inputFile.is_open()) {
		std::cerr<<"Failed to open the file."<<std::endl;
		return 1;
	}
	
	std::string line;
	std::getline(inputFile, line);
	while(std::getline(inputFile, line)) {
		for (std::string x: getWords(line)) {
			vect.push_back(x);
		}
	}
	inputFile.close();
	
	std::ofstream MyFile("new.txt");	
	for (int i = 1; i < vect.size(); i++) {
		if (i % 4 == 0) {
			MyFile<<std::endl;
		} else {
			MyFile<<vect.at(i) + " ";
		}
	}
	MyFile.close();
	
	return 0;
}
