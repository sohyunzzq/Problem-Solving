#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> arr;
    for (int i=1; i<=n; i+=2)
        arr.push_back(i);
    return arr;
}