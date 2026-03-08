#include <iostream>
#include <algorithm>
using namespace std;

string S, T;

bool S2T() {
	while (T.size() > S.size() && S != T) {
		if (T[T.size() - 1] == 'A')
			T.pop_back();
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}

	return (S == T);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> S >> T;

	cout << S2T();
}