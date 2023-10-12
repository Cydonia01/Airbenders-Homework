/**
 * cost of a triangle tile.
 * 
 * This file is second problem of week 1.
 *
 * @author Mehmet Ali Özdemir
 * @since 10.10.2023
 *
 */
 
#include<iostream>
#include<cmath>
 
using namespace std;
 
int main() {
 	double a, b, c, u, area, cost;
	cin>>a>>b>>c;
 	
	u = (a + b + c) / 2;
 	area = sqrt(u * (u - a) * (u - b) * (u - c));
	cost = area * 0.80;
 	
	cout<<"Cost: "<<cost<<"$";
 	
	return 0;
}
