#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;


class arr {
	int** p;
	int N;


	public:
		arr() {
			cin >> N;
			p = new int* [N];
			for (int i = 0; i < N; ++i) {
				p[i] = new int[N];
			}

			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					int a;
					cin >> a;
					p[i][j] = a;
				}
			}
		}


		~arr() {
			for (int i = 0; i < N; i++) {
					delete p[i];
			}
			delete[] p;
		}



		void GetMatrix(){
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << p[i][j] << " ";
				}
				cout << std::endl;
			}
		}
		


};

int main() {
	arr p1;
	p1.GetMatrix();
}
