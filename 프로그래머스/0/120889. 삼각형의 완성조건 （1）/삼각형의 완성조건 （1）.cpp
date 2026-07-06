#include <vector>
using namespace std;

int solution(vector<int> sides) {
    int sum = 0;
    int maxi = 0;
    
    for (int i=0; i<3; i++) {
        sum += sides[i];
        maxi = max(maxi, sides[i]);
    }
    sum -= maxi;
    
    return (maxi < sum ? 1 : 2);
}