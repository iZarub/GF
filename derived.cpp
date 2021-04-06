#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;



class base {
protected:
	int i, j;

public:

	void Set(int a, int b) {
		i = a;
		j = b;
	}

};

class derived1:public base {
	int k;
};



class derived2:public derived1 {
	int m;

public:
	void SetM() {
		m = base::i * base::j;
	}


	void ShowM() {
		cout << m;
	}

};






int main() {

	derived2 ob;
	ob.Set(1, 2);
	SetM();
	ob.ShowM();
}
