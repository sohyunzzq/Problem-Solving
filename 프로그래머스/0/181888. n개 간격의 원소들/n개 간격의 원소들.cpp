#include <vector>
using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> arr;
    for (int i=0; i<num_list.size(); i+=n)
        arr.push_back(num_list[i]);
    return arr;
}