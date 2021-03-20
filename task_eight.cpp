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




friend Q_num operator+(Q_num num1, Q_num num2) {
    Q_num num3;
    int NOD = nod(num1.q, num2.q);
    int NOK = num1.q * num2.q / NOD;
    num3.p = num1.p * (NOK /num1.q) + num2.p * (NOK / num2.q);
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


friend Q_num operator-(Q_num num1, Q_num num2) {
    Q_num num3;
    int NOD = nod(num1.q, num2.q);
    int NOK = num1.q * num2.q / NOD;
    num3.p = num1.p * (NOK / num1.q) - num2.p * (NOK / num2.q);
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


friend Q_num operator*(Q_num num1, Q_num num2) {
    Q_num num3;
    num3.q = num1.q * num2.q;
    num3.p = num1.p * num2.p;
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


friend Q_num operator/(Q_num num1, Q_num num2) {
    Q_num num3;
    num3.q = num1.q * num2.p;
    num3.p = num1.p * num2.q;
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


friend std::string operator==(Q_num num1, Q_num num2) {
    Q_num num3 = (num1-num2);
    if (num3.p > 0) {
        return "First > Second";
    }
    else if (num3.p < 0) {
        return "First < Second";
    }
    else {
        return "First = Second";
    }
}


};




int main() {
    Q_num num1(1, 1);
    cout << "First frac:" << ' ';
    num1.GetFraction();
    Q_num num2(1, 1);
    cout << "Second frac:" << ' ';
    num2.GetFraction();
    cout << std::endl << "Sum:" << ' ';
    (num1 + num2).GetFraction();
    cout << std::endl << "Diff:"<< ' ';
    (num1 - num2).GetFraction();
    cout << std::endl << "Multi:"<< ' ';
    (num1 * num2).GetFraction();
    cout << std::endl << "Div:"<< ' ';
    (num1 / num2).GetFraction();
    cout << std::endl << "Comp:" << ' ';
    std::string comp = num1 == num2;
    cout << comp << std::endl;;


}
