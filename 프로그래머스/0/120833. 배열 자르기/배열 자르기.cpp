#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> ans;
    
    for (int idx = num1; idx <= num2; idx++)
        ans.push_back(numbers[idx]);
    return ans;
}