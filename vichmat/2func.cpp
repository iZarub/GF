#include<iostream>
#include<vector>
#include<cmath>

using std::vector;
using std::cout;
using std::cin;


// f(x,y) = x^2 - 2y or f(x, y) = x^2 - 2y + 3

// y(i) = y(i-1) + h(x(i-1)^2-2y(i-1)) h = 0.1


float f1(float x, float y) {
	return x * x - 2*y;
}


float f2(float x, float y) {
	return x * x - 2 * y + 3;
}



class Solver {
	float y;
	std::vector<float>res;
	



public:
	void Solve(float (*f)(float, float)) {

		res.push_back(1);
		y = 1 + 0.1 * f(0, 1);
		res.push_back(y);


		for (int i = 2; i < 11; i++) {
			y = res[i - 1] + 0.1 * f(0.1 * (i - 1), res[i - 1]);
			res.push_back(y);
		}
	}



	void GetResults() {
		for (float& i : res) {
			std::cout << i << std::endl;
		}
	}

};



int main()
{
	Solver res1;
	res1.Solve(f1);
	res1.GetResults();
	cout << std::endl;
	Solver res2;
	res2.Solve(f2);
	res2.GetResults();
	



}
