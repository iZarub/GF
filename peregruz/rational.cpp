#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::cout;
using std::cin;

// p\q p - Z, q - N
// НОК = mn/НОД(mn)

void swap(int a, int b) {
    int c = a;
    a = b;
    b = a;
}


void sort(int a, int b) {
    if (b > a) {
        swap(a, b);
    }
}


int nod(int a, int b) {
    int c;
    sort(a, b);
    while (b != 0) {
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}





class Q_num {
    int p;
    int q;

public:



    Q_num(int Value_p, int Value_q) {
        cout << "Enter an integer numerator" << std::endl;
        cin >> Value_p;
        cout << "Enter the natural denominator" << std::endl;
        cin >> Value_q;
        p = Value_p;
        q = Value_q;
        int NOD = nod(p, q);
        if (NOD != 1) {
            p = p / NOD;
            q = q / NOD;
            if (q < 0) {
                q = -q;
                p = -p;
            }
        }


    }

    Q_num() = default;

    ~Q_num() = default;


    void GetFraction() {
        cout << p << '/' << q << std::endl;
    }



    Q_num operator +(Q_num num1) {
        Q_num num3;
        int NOD = nod(num1.q, q);
        int NOK = num1.q * q / NOD;
        num3.p = num1.p * (NOK / num1.q) + p * (NOK / q);
        num3.q = NOK;
        NOD = nod(num3.p, num3.q);
        if (NOD != 1) {
            num3.p /= NOD;
            num3.q /= NOD;
            if (num3.q < 0) {
                num3.q = -num3.q;
                num3.p = -num3.p;
            }
        }
        return num3;
    }

    Q_num operator -(Q_num num1) {
        Q_num num3;
        int NOD = nod(num1.q, q);
        int NOK = num1.q * q / NOD;

        num3.p = - num1.p * (NOK / num1.q) + p * (NOK / q);

        num3.q = NOK;

        NOD = nod(num3.p, num3.q);
        if (NOD != 1) {
            num3.p /= NOD;
            num3.q /= NOD;
            if (num3.q < 0) {
                num3.q = - num3.q;
                num3.p = - num3.p;
            }
        }
        return num3;
    }

    Q_num operator*(Q_num num1) {
        Q_num num3;
        num3.q = num1.q * q;
        num3.p = num1.p * p;
        int NOD = nod(num3.p, num3.q);
        if (NOD != 1) {
            num3.p /= NOD;
            num3.q /= NOD;
            if (num3.q < 0) {
                num3.q = -num3.q;
                num3.p = -num3.p;
            }
        }
        return num3;
    }
    
    Q_num operator/(Q_num num1) {
        Q_num num3;
        num3.q = q * num1.p;
        num3.p = p * num1.q;
        int NOD = nod(num3.p, num3.q);
        if (NOD != 1) {
            num3.p /= NOD;
            num3.q /= NOD;
            if (num3.q < 0) {
                num3.q = -num3.q;
                num3.p = -num3.p;
            }
        }
        return num3;
    }
    
    
    
    int operator==(Q_num num1) {
        return (p == num1.p) && (q == num1.q);
    }
  
};



int main() {
    Q_num num1(1, 1);
    cout << "First frac:" << ' ';
    num1.GetFraction();
    Q_num num2(1, 1);
    cout << "Second frac:" << ' ';
    num2.GetFraction();
    Q_num num;
    num = num1 + num2;
    num.GetFraction();
    cout << std::endl;
    num = num1 - num2;
    num.GetFraction();
    cout << std::endl;
    num = num1 * num2;
    num.GetFraction();
    cout << std::endl;
    num = num1/num2;
    num.GetFraction();
    cout << std::endl;
    cout << (num1 == num2);
}
