#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;


class vec {
    vector<float>v;
    int N;

public:

    vec(int param)
    {
        cout << "Type size of the vector" << std::endl;
        cin >> N;
        cout << "Type elements of the vector" << std::endl;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            v.push_back(a);

        }
    }

    vec() = default;

    ~vec() = default;


    void GetVector() {
        for (float& i : v) {
            cout << i << " ";
        }
        cout << std::endl;
    }


    vec operator+(vec v1) {
        vec v2;
        if (v1.N != N) {
            cout << "Size issue";
            exit;
        }
        else {
            for (int i = 0; i < v1.N; i++) {
                v2.v.push_back(v1.v[i] + v[i]);
            }
        }
        return v2;
    }


    vec operator-(vec v1) {
        vec v2;
        if (v1.N != N) {
            cout << "Size issue";
            exit;
        }
        else {
            for (int i = 0; i < v1.N; i++) {
                v2.v.push_back(-v1.v[i] + v[i]);
            }
        }
        return v2;
    }

    float operator*(vec v1) {
        if (v1.N != N) {
            cout << "Size issue";
            exit;
        }
        float s = 0;
        for (int i = 0; i < v1.N; ++i) {
            s += v1.v[i] * v[i];

        }
        return s;
    }
    

};


int main() {
    vec v3;
    vec v1(1);
    v1.GetVector();
    cout << std::endl;
    vec v2(1);
    v2.GetVector();
    cout << std::endl;
    v3 = v1 + v2;
    v3.GetVector();
    cout << std::endl;
    v3 = v1 - v2;
    v3.GetVector();
    cout << std::endl;
    cout << (v1 * v2);

}
