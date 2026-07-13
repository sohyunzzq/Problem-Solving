#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> arr;
    sort(num_list.begin(), num_list.end());
    for (int i=5; i<num_list.size(); i++)
        arr.push_back(num_list[i]);
    return arr;
}