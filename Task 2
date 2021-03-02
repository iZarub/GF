#include <iostream>
#include<vector>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


class students {
	vector<int>marks;
	int avg;
	std::string name;

public:
	void SetMarks() {
		int n;
		for (int i = 0; i < 5; i++) {
			cin >> n;
			marks.push_back(n);
		}
	}

	void SetName() {
		std::string Name;
		cin >> Name;
		name = Name;

	}


	void GetMarks() {
		for (int& i : marks) {
			cout << i;
		}
	}

	void GetName() {
		cout << name;

	}
	void GetAverage(){
		int s;
		s = 0;
		for (int& i : marks) {
			s = s + i;
		}
		cout << s / 5;
	}
};
	

		

int main(){
	students s1;
	students s2;
	students s3;
	s1.SetMarks();
	s1.SetName();
	s1.GetMarks();
	s1.GetName();
	s1.GetAverage();

	s2.SetMarks();
	s2.SetName();
	s2.GetMarks();
	s2.GetName();
	s2.GetAverage();

	s3.SetMarks();
	s3.SetName();
	s3.GetMarks();
	s3.GetName();
	s3.GetAverage();

    return 0;
}
	
