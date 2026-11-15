
#include <iostream>
using namespace std;

int main() {
    int students[100], sandwiches[100];
    int n;

    cin >> n;

    int zero = 0, one = 0;

    for (int i = 0; i < n; i++) {
        cin >> students[i];

        if (students[i] == 0)
            zero++;
        else
            one++;
    }

    for (int i = 0; i < n; i++) {
        cin >> sandwiches[i];
    }

    for (int i = 0; i < n; i++) {
        if (sandwiches[i] == 0) {
            if (zero == 0) {
                cout << one;
                return 0;
            }
            zero--;
        }
        else {
            if (one == 0) {
                cout << zero;
                return 0;
            }
            one--;
        }
    }

    cout << 0;

    return 0;
}
