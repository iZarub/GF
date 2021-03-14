#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;

// p\q p - Z, q - N
// НОК = mn/НОД(mn)

void swap(int a, int b){
    int c = a;
    a = b;
    b = a;
}


void sort(int a, int b){
    if (b > a){
        swap(a, b);
    }
}


int nod(int a, int b){
    int c;
    sort(a, b);
    while (b != 0){
        c = a;
        a = b;
        b = c%b;
    }
    return a;
}





class Q_num{
    int p;
    int q;

public:

    Q_num(int Value_p, int Value_q){
        cout << "Enter an integer numerator" << std::endl;
        cin >> Value_p;
        cout << "Enter the natural denominator" << std::endl;
        cin >> Value_q;
        p = Value_p;
        q = Value_q;
        int NOD = nod(p,q);
        if ( NOD != 1 ){
            p = p / NOD;
            q = q / NOD;
            if (q < 0){
                q = -q;
                p = -p;
            }
        }


    }

    ~Q_num() = default;


    void GetFraction(){
        cout << p << '/' << q << std::endl;
    }


    void GetSum(Q_num num2){
        int NOD = nod(this->q, num2.q);
        int NOK = this->q*num2.q / NOD;
        this->p = this->p*(NOK/this->q) + num2.p*(NOK/num2.q);
        this->q = NOK;
        NOD = nod(this->p,this->q);
        if (NOD != 1){
            this->p /= NOD;
            this->q /= NOD;
            if (q < 0){
                q = -q;
                p = -p;
            }

        }

    }


    void GetDiff(Q_num num2){
        int NOD = nod(this->q, num2.q);
        int NOK = this->q*num2.q / NOD;
        this->p = this->p*(NOK/this->q) - num2.p*(NOK/num2.q);
        this->q = NOK;
        NOD = nod(this->p,this->q);
        if (NOD != 1){
            this->p /= NOD;
            this->q /= NOD;
            if (q < 0){
                q = -q;
                p = -p;
            }
        }

    }


    void GetMulti(Q_num num2){
        this->q = this->q*num2.q;
        this->p = this->p*num2.p;
        int NOD = nod(this->p,this->q);
        if (NOD != 1) {
            this->p /= NOD;
            this->q /= NOD;
            if (q < 0){
                q = -q;
                p = -p;
            }
        }

    }


    void GetDivision(Q_num num2){
        this->q = this->q*num2.p;
        this->p = this->p*num2.q;
        int NOD = nod(this->p,this->q);
        if (NOD != 1) {
            this->p /= NOD;
            this->q /= NOD;
            if (q < 0){
                q = -q;
                p = -p;
            }
        }
    }



    void GetComp(Q_num num2){
        this->GetDiff(num2);
        if (this->p > 0){
            cout << "First > Second";
        }
        else if (this->p < 0){
            cout << "First < Second";
        }
        else {
            cout << "First = Second";
        }
    }





};



int main() {
    Q_num num1(1,1);
    num1.GetFraction();
    Q_num num2(1,1);
    num2.GetFraction();
    num1.GetComp(num2);

}
