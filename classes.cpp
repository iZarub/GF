#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;



class Vehicle {
	int wheels;
	int passengers;

public:

	void Set_Wheels(int w) {
		wheels = w;
	}

	void Get_Wheels() {

		cout << "Wheels" << ": " << wheels << std::endl;
	}


	void Set_Passengers(int p) {
		passengers = p;
	}

	void Get_Passengers() {
		cout << "Passengers" << ": " << passengers << std::endl;
	}


};


class Truck :public Vehicle {
	int cargo;

public:
	void Set_Cargo(int c) {
		cargo = c;
	}

	void Get_Cargo() {
		cout << "Cargo" << ": " << cargo << std::endl;
	}

	void show() {
		Get_Wheels();
		Get_Passengers();
		Get_Cargo();
	}

};


class Auto :public Vehicle {
	int type;

public:
	void Set_Type(int t) {
		type = t;
	}

	void Get_Type() {
		cout << "Type" << ": " << type << std::endl;
	
	}
	void show() {
		Get_Wheels();
		Get_Passengers();
		Get_Type();
	}


};








int main() {
	Truck t1;
	t1.Set_Cargo(200);
	t1.Set_Passengers(1);
	t1.Set_Wheels(8);
	cout << "Truck char:" << std::endl;
	t1.show();
	cout << std::endl;

	Auto a1;
	a1.Set_Passengers(4);
	a1.Set_Type(1);
	a1.Set_Wheels(4);
	cout << "Auto charL:" << std::endl;
	a1.show();
   
}
