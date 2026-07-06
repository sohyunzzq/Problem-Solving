#include <vector>
using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> ans;
    
    for (int i=0; i<numlist.size(); i++)
        if (numlist[i] % n == 0)
            ans.push_back(numlist[i]);
    return ans;
}