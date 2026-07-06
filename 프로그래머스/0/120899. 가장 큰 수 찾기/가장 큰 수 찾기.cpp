#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    int idx = 0;
    int maxi = 0;
    
    for (int i=0; i<arr.size(); i++) {
        if (arr[i] > maxi) {
            maxi = arr[i];
            idx = i;
        }
    }
    vector<int> ans(2);
    ans[0] = maxi, ans[1] = idx;
    
    return ans;
}