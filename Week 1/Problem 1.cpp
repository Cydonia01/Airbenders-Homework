/**
 * quotient and remainder of a number.
 * 
 * This file is first problem of week 1.
 *
 * @author Mehmet Ali Özdemir
 * @since 10.10.2023
 *
 */
#include<iostream>

using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	
	cout<<"Standard boxes needed: "<<n / 9<<endl;
	cout<<"Remaining candies: "<<n % 9<<endl;
	cout<<"Non-standard boxes needed: "<<n / m<<endl;
	cout<<"Remaining candies: "<<n % m;
	
	return 0;
}
