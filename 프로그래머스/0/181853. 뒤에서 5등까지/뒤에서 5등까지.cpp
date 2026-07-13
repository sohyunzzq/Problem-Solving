#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> num_list) {
    sort(num_list.begin(), num_list.end());
    
    vector<int> arr;
    for (int i=0; i<5; i++)
        arr.push_back(num_list[i]);
    return arr;
}