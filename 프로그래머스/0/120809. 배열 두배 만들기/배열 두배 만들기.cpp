#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> arr;
    
    for (int i=0; i<numbers.size(); i++)
        arr.push_back(numbers[i] * 2);
    return arr;
}