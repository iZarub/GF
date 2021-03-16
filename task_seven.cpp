#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;


struct Vec{
    int x;
    int y;
    int z;


    Vec(int a, int b, int c){
        this->x = a;
        this->y = b;
        this->z = c;


    }


    void GetVector(){
        cout << x << std::endl <<  y << std::endl << z;


    }

};

Vec operator+ (Vec v1, Vec v2){
    Vec v3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    return v3;
}

Vec operator-(Vec v1, Vec v2){
    Vec v4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    return v4;

}

int operator*(Vec v1, Vec v2){
    int a = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    return a;
}




int main() {
Vec v1(2, 3, 4);
Vec v2(1, 2, 3);
(v1 + v2).GetVector();
cout << std::endl << std::endl;
(v1 - v2).GetVector();
cout << std::endl << std::endl;
cout << (v1*v2);

}
