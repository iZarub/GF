#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;


class vec{
    vector<float>v;
    int N;

public :

    vec()
    {
    cout << "Type size of the vector" << std::endl;
    cin >> N;
    cout << "Type elements of the vector" << std:: endl;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        v.push_back(a);

    }
    }


    ~vec() = default;


    void GetVector(){
        for (float& i :v){
            cout << i << " ";
        }
    cout << std::endl;
    }

    bool comp(vec v1){
        if (this->N != v1.N){
            return false;
        }
        else {
            return true;
        }
    }

    void sum(vec v2)
    {
        for (int i = 0; i < v2.N; ++i){
            this->v[i] += v2.v[i];
        }
    }

    void dif(vec v2){

        for (int i = 0; i < v2.N; ++i){
            this->v[i] -= v2.v[i];
        }
    }

    void scalar(vec v2){
        float s = 0;
        for (int i = 0; i< v2.N; ++i){
            s += this->v[i]*v2.v[i];

        }
        cout << s;
    }

};






class matrix{
    float** arr;
    int M;

public:

    matrix(){
        cout << "Type size of the matrix" << std::endl;
        cin >> M;
        cout << "Type elements of the matrix" << std:: endl;

        arr = (float**)malloc(M * sizeof(float**));
        for (int i = 0; i < M; ++i) {
            arr[i] = (float*)malloc(M * sizeof(float*));
        }


        for (int i = 0; i < M; ++i){
            for (int j = 0; j < M; ++j){
                float a;
                cin >> a;
                arr[i][j] = a;

            }

        }
    }


    ~matrix() = default;


    void GetMatrix(){
        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                cout << arr[i][j] << " ";
            }
            cout << std::endl;
        }
    }

    bool comp(matrix m1){
        if (this->M != m1.M){
            return false;
        }
        else {
            return true;
        }
    }

    void sum(matrix v2)
    {
        for (int i = 0; i < v2.M; ++i){
            for(int j = 0; j < v2.M; ++j) {
                this->arr[i][j] += v2.arr[i][j];
            }
        }
    }

    void diff(matrix v2){
        for (int i = 0; i< v2.M; i++){
            for (int j = 0; j < v2.M; j++){
                this->arr[i][j] -= v2.arr[i][j];
            }
        }
    }


    void multi(matrix v2) {
        for (int i = 0; i< v2.M;i++){
            for (int j = 0; j< v2.M; j++){
                float s = 0;
                for (int k = 0; k< v2.M; k++){
                    s += this->arr[i][k]*v2.arr[k][j];
                }
                this->arr[i][j] = s;
            }
        }
    }
};





int main() {

    char type;
    cout << "M or V?" << std::endl;
    cin >> type;

    if (type == 'V') {

        char sign;
        vec v1;
        cout << "Type sign(+-*)" << std::endl;
        cin >> sign;
        vec v2;


        if (v1.comp(v2) == true) {

            if (sign == '+') {
                v1.sum(v2);
                v1.GetVector();
            }

            if (sign == '-') {
                v1.dif(v2);
                v1.GetVector();
            }

            if (sign == '*') {
                v1.scalar(v2);
            }
        }
        else {
            cout << "Size issue";
        }
    }

    else{

        matrix m1;
        char sign;
        cout << "Type sign(+-*)" << std::endl;
        cin >> sign;
        matrix m2;
        if (m1.comp(m2) == true){

            if (sign == '+') {
                m1.sum(m2);
                m1.GetMatrix();
            }

            if (sign == '-') {
                m1.diff(m2);
                m1.GetMatrix();
            }

            if (sign == '*') {
                m1.multi(m2);
                m1.GetMatrix();
            }

        }
        else{
            cout << "Size issue";

        }

    }

}
