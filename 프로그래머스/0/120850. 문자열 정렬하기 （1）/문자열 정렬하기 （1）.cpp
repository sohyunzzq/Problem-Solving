#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string my_string) {
    vector<int> arr;
    
    for (int i=0; i<my_string.size(); i++)
        if ('0' <= my_string[i] && my_string[i] <= '9')
            arr.push_back(int(my_string[i] - '0'));
    sort(arr.begin(), arr.end());
    
    return arr;
}