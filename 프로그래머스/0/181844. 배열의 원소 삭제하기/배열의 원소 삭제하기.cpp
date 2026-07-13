#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> ans;
    for (int i=0; i<arr.size(); i++) {
        bool flag = true;
        for (int j=0; j<delete_list.size(); j++)
            if (arr[i] == delete_list[j]) {
                flag = false;
                break;
            }
        if (flag)
            ans.push_back(arr[i]);
    }
    return ans;
}