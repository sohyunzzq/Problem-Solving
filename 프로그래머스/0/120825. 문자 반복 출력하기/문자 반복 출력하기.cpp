#include <string>
using namespace std;

string solution(string my_string, int n) {
    string ans;
    
    for (int i=0; i<my_string.size(); i++)
        for (int j=0; j<n; j++)
            ans.push_back(my_string[i]);
    return ans;
}