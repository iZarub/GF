#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int N, s, t, avg;
    s = 0;
    avg = 0;
    std::vector <int> T;
    std::vector <int> I;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        T.push_back(t);
        s += t;
    }

    avg = s / N;

    for (int i = 0; i < N; ++i) {
        if (T[i] > avg) {
            I.push_back(i);
        }
    }
    for (int i : I) {
        cout << i + 1 << " ";
    }


    return 0;
}
