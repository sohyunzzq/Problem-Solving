#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> ans;
    for (int i=0; i<strlist.size(); i++)
        ans.push_back(strlist[i].size());
    return ans;
}