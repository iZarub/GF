#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include <algorithm>  
#include <stdio.h>

using std::vector;
using std::cout;
using std::cin;
using std::string;



vector<int> operator*(vector<int> a, vector<int> b) {
	vector<int>c;
	c.resize(a.size());
	for (int i = 0; i < a.size(); i++) {
		c[i] = a[i] * b[i];
	}
	return c;
}



template <class X> X sqr(X param) {
	return param * param;
}



int main() {
	int a = 5;
	cout << sqr(a);
	cout << std::endl;
	vector<int>arr = { 1, 2, 3 };
	for (int i : sqr(arr)) {
		cout << i;
	}

}
