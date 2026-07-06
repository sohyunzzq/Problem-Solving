#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> arr;
    
    for (int i=0; i<num_list.size(); i++) {
        int num = num_list[num_list.size() - 1 - i];
        arr.push_back(num);
    }
    return arr;
}