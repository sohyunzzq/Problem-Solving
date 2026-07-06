#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> arr(2);
    
    arr[0] = arr[1] = 0;
    for (int i=0; i<num_list.size(); i++)
        num_list[i] % 2 == 0 ? arr[0]++ : arr[1]++;
    return arr;
}