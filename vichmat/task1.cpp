#include<iostream>
#include<vector>

// f(x,y) = x^2 - 2y
// y(i) = y(i-1) + h(x(i-1)^2-2y(i-1))

class Solver {
	float y;
	std::vector<float>res;

	public:
	void Solve() {
		res.push_back(1);
		y = 1 + 0.1 * (0 - 2);
		res.push_back(y);
		for (int i = 2; i < 11; i++) {
			y = res[i - 1] + 0.1 * ((((i - 1) * 0.1) * (i - 1) * 0.1) - 2 * res[i - 1]);
			res.push_back(y);
		}
	}

	void GetResults() {
		for (float& i : res) {
			std::cout << i << std::endl;
		}
	
	
	}




};
