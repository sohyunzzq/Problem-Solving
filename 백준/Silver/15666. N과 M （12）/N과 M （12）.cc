#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define endl '\n'

int n, m;
vector<int> arr;
vector<int> selected;

void func(int curr) {
	if (selected.size() == m) {
		for (int i = 0; i < m; i++)
			cout << selected[i] << " ";
		cout << endl;
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (curr == 0 || selected[curr - 1] <= arr[i]) {
			selected.push_back(arr[i]);
			func(curr + 1);
			selected.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	set<int> temp;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		temp.insert(num);
	}
	arr.assign(temp.begin(), temp.end());
	
	func(0);
}