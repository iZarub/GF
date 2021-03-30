#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using std::vector;
using std::cout;
using std::cin;



std::ostream& operator << (std::ostream &stream, vector<int> arr) {
	for (int& i : arr) {
		stream << i << " ";
	}
	return stream;
}

std::istream& operator >> (std::istream& stream, vector<int>&arr) {
	int a;
	for (int i = 0; i < 5; i++) {
		stream >> a;
		arr.push_back(a);
	


	}
	return stream;

}

int main() {
	vector<int> arr;
	
	cin >> arr;
	

	cout << arr;
}
