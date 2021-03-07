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
    vector<vector<float>>mat;
    int N;

public:

    matrix(){
        cout << "Type size of the matrix" << std::endl;
        cin >> N;
        cout << "Type elements of the matrix" << std:: endl;
        for (int i = 0; i < N; i++){
            for (int j = 0; j< N; j++){
                int a;
                cin >> a;
                mat[i][j] = a;
            }
        }
    }


    ~matrix() = default;


    void GetMatrix(){
        for (int i = 0; i < N; i++){
            for (int j = 0; j<N; i++){
                cout << mat[i][j] << " ";
            }
        cout << std::endl;
        }

    }

};





int main() {


char sign;
vec v1;
cout << "Type sign(+-*)" << std::endl;
cin >> sign;
vec v2;

matrix m1;
m1.GetMatrix();




if (v1.comp(v2) == true){

    if (sign == '+'){
        v1.sum(v2);
        v1.GetVector();
    }

    if (sign == '-'){
        v1.dif(v2);
        v1.GetVector();
    }

    if (sign == '*'){
        v1.scalar(v2);
    }
}

else{
    cout << "Size issue";
}

}
