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

template<class T> class Bubble {
	vector<T> vec;
public:
    Bubble(){
        for (int i = 0; i < 5; i++) {
            T N;
            cin >> N;
            vec.push_back(N);
        }
    }


    void sort(){
        T temp;
        for (int i = 0; i < vec.size() - 1; i++) {
            for (int j = 0; j < vec.size() - i - 1; j++) {
                if (vec[j] > vec[j + 1]) {
                    temp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = temp;
                }
            }
        }
    }
    
    void get_vec() {
        for (T i : vec) {
            cout << i << " ";
        }
    }


};




int main() {
    Bubble<int> vec1;
    vec1.get_vec();
    vec1.sort();
    cout << std::endl;
    vec1.get_vec();
    cout << std::endl;

    Bubble<double> vec2;
    vec2.get_vec();
    vec2.sort();
    cout << std::endl;
    vec2.get_vec();
}
