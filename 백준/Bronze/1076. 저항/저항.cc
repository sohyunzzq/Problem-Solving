#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<string, int> resistance;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	resistance.insert({ "black", 0 });
	resistance.insert({ "brown", 1 });
	resistance.insert({ "red", 2 });
	resistance.insert({ "orange", 3 });
	resistance.insert({ "yellow", 4 });
	resistance.insert({ "green", 5 });
	resistance.insert({ "blue", 6 });
	resistance.insert({ "violet", 7 });
	resistance.insert({ "grey", 8 });
	resistance.insert({ "white", 9 });
	
	long long ans = 0;
	for (int i = 1; i >= 0; i--) {
		string st;
		cin >> st;

		ans += resistance[st] * pow(10, i);
	}
	
	string st;
	cin >> st;

	ans *= pow(10, resistance[st]);

	cout << ans;
}