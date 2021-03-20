#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;


class matrix {
    float** arr;
    int M;

public:

    matrix(int param1, int param2) {
        cout << "Type size of the matrix" << std::endl;
        cin >> M;
        cout << "Type elements of the matrix" << std::endl;

        arr = (float**)malloc(M * sizeof(float));
        for (int i = 0; i < M; ++i) {
            arr[i] = (float*)malloc(M * sizeof(float));
        }


        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                float a;
                cin >> a;
                arr[i][j] = a;
            }
        }
    }



    matrix(int M) {
        arr = (float**)malloc(M * sizeof(float));
        for (int i = 0; i < M; ++i) {
            arr[i] = (float*)malloc(M * sizeof(float));
        }

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {

                arr[i][j] = 0;
            }
        }
    }



    matrix() = default;



    ~matrix() {
        for (int i = 0; i < M; i++) {
            free(arr[i]);
        }
        free(arr);
    }




    void GetMatrix() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                cout << arr[i][j] << " ";
            }
            cout << std::endl;
        }
    }



    matrix operator=(matrix m2)
    {
        arr = m2.arr;
        M = m2.M;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                arr[i][j] = m2.arr[i][j];
            }
        }

        return *this;
    }


    matrix operator+(matrix m2)
    {
        if (M == m2.M)
        {
            matrix result(m2.M);
            for (int x = 0; x < M; x++) {
                for (int y = 0; y < M; y++) {
                    result.arr[x][y] = arr[x][y] + m2.arr[x][y];
                }
            }
            return result;
        }

        cout << "Size issue";
        exit;
    }
};




int main() {
    matrix m1(1, 1);
    matrix m2(1, 1);
    matrix mr;
    mr = m1 + m2;
    cout << "Result:" << std::endl;
    mr.GetMatrix();

}
