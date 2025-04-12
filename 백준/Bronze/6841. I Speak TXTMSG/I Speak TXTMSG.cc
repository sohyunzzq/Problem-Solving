#include <iostream>
using namespace std;

int main() {
	string str;
	while (1) {
		cin >> str;

		if (str == "TTYL") {
			cout << "talk to you later" << endl;
			break;
		}

		if (str == "CU")
			cout << "see you" << endl;
		else if (str == ":-)")
			cout << "I’m happy" << endl;
		else if (str == ":-(")
			cout << "I’m unhappy" << endl;
		else if (str == ";-)")
			cout << "wink" << endl;
		else if (str == ":-P")
			cout << "stick out my tongue" << endl;
		else if (str == "(~.~)")
			cout << "sleepy" << endl;
		else if (str == "TA")
			cout << "totally awesome" << endl;
		else if (str == "CCC")
			cout << "Canadian Computing Competition" << endl;
		else if (str == "CUZ")
			cout << "because" << endl;
		else if (str == "TY")
			cout << "thank-you" << endl;
		else if (str == "YW")
			cout << "you’re welcome" << endl;
		else
			cout << str << endl;
	}
}