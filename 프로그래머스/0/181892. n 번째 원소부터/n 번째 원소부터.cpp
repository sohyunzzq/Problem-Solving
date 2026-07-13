#include <vector>
using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> arr;
    for (int i=0; i<num_list.size()-n+1; i++)
        arr.push_back(num_list[n+i-1]);
    return arr;
}