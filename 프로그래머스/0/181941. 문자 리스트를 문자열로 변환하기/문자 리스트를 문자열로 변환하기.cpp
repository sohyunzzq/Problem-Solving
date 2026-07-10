#include <string>
#include <vector>
using namespace std;

string solution(vector<string> arr) {
    string ans;
    
    for (int i=0; i<arr.size(); i++)
        ans += arr[i];
    return ans;
}