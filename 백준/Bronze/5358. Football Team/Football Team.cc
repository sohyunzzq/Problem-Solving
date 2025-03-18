#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'i')
                cout << 'e';
            else if (str[j] == 'e')
                cout << 'i';
            else if (str[j] == 'I')
                cout << 'E';
            else if (str[j] == 'E')
                cout << 'I';
            else
                cout << str[j];
        }
        cout << endl;
    }
}