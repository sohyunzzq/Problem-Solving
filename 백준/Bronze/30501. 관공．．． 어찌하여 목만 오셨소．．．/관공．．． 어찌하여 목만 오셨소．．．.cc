#include <iostream>
using namespace std;

bool FindS(string str) {
    for (int j = 0; j < str.size(); j++) {
        if (str[j] == 'S') {
            cout << str;
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (FindS(str))
            break;
    }
}