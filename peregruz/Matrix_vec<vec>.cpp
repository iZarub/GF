#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;


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

};

int main() {
    Matrix mat;
    vector<float> vec1 = { 1, 2, 3, 4};
    vector<float> vec2 = { 5, 6, 7, 8 };
    Matrix m1(vec1);
    m1.GetMatrix();
    cout << std::endl << std::endl;
    Matrix m2(vec2);
    m2.GetMatrix();
    cout << std::endl << std::endl;
    mat = m1 + m2;
    mat.GetMatrix();
    cout << std::endl << std::endl;
    mat = m1 - m2;
    mat.GetMatrix();
    cout << std::endl << std::endl;
    mat = m1*m2;
    mat.GetMatrix();
    cout << std::endl << std::endl;
}
