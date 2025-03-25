#include <iostream>
using namespace std;

int main() {
    int alpha[26] = {};
    string str;
    cin >> str;

    for (int i = 0; str[i]; i++) {
        alpha[str[i] - 'A'] = 1;
    }

    for (int i = 0; i < 26; i++) {
        if (!alpha[i]) {
            cout << char(i + 'A');
            break;
        }
    }
}