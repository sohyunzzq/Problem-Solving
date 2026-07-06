#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> arr(2);
    
    arr[0] = money / 5500;
    arr[1] = money % 5500;
    
    return arr;
}