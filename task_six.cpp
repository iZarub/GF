#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;



void show(vector<int>v, int S){
    for (int i = 0; i < S; i++){
        cout << v[i];
    }
}




void show(int M, int N, int ** arr){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << std::endl;
    }
}






int main() {
    int M, N;
    cin >> M >> N;
    int ** arr = new int*[M];
    for (int i = 0; i < M; ++i) {
        arr[i] = new int[N];
    }

    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j){
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    show(M, N, arr);
    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;






    int S;
    vector<int>vec;
    cin >> S;
    for (int i = 0; i < S; i++){
        int a;
        cin >> a;
    }

    show(vec, S);

}
