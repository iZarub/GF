#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;

class vec;
class Matrix {
    vector<vector<float>> arr;
    int size;

public:

    Matrix(vector<float> vec) {

        if (sqrt(vec.size()) - ceil(sqrt(vec.size())) == 0)
        {
            size = (int)sqrt(vec.size());
            for (int i = 0; i < size; i++)
            {
                arr.push_back({});
                for (int j = 0; j < size; j++)
                {
                    arr[i].push_back(vec[(i * size) + j]);
                }
            }
        }

        else
        {
            cout << "Matrix is not square";
            exit;
        }

    }

    Matrix() = default;

    ~Matrix() = default;


    void GetMatrix()
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << std::endl;
        }

        for (int j = 0; j < arr[arr.size() - 1].size(); j++)
        {
            cout << arr[arr.size() - 1][j] << ' ';
        }
    }



    Matrix operator +(Matrix m1)
    {
        if (size == m1.size)
        {
            vector<float> sum_vec;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    sum_vec.push_back(arr[i][j] + m1.arr[i][j]);
                }
            }

            Matrix sum(sum_vec);
            return sum;
        }
        else
        {
            cout << "Size issue.";
            exit;
        }
    }

    Matrix operator -(Matrix m1)
    {
        if (size == m1.size)
        {
            vector<float> vec;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    vec.push_back(arr[i][j] - m1.arr[i][j]);
                }
            }

            Matrix sum(vec);
            return sum;
        }
        else
        {
            cout << "Size issue.";
            exit;
        }
    }


    Matrix operator*(Matrix m1) {

        if (size == m1.size)
        {
            vector<float> vec;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    float s = 0;
                    for (int t = 0; t < size; t++)
                    {
                        s += arr[i][t] * m1.arr[t][j];
                    }
                    vec.push_back(s);
                }
            }
            Matrix multi(vec);
            return multi;
        }
        else
        {
            cout << "Size issue.";
            exit;
        }
    }



    friend vec mv(vec v1, Matrix m1);


};


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


    friend vec mv(vec v1, Matrix m1);


};


vec mv(vec v1, Matrix m1) {
    if (v1.N != m1.size) {
        cout << "Wrong demention" << std::endl;
        return v1;
    
    }
    int s = 0;
    vec result;
    for (int j = 0; j < v1.N; j++) {
        for (int i = 0; i < v1.N; i++) {
            s += v1.v[i]*m1.arr[i][j];

        }
        result.v.push_back(s);
        s = 0;
    }

    return result;
}


int main() {

    vector<float> vec1 = {1, 2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
    Matrix m1(vec1);
    m1.GetMatrix();
    cout << "Your Matrix" << std::endl;
    vec v1(1);
    cout << std::endl;
    v1.GetVector();
    cout << "Your Vector" << std::endl;
    cout << std::endl;
    mv(v1, m1).GetVector();
    cout << "Your V*M Vector";
}
