#include <vector>
using namespace std;

int solution(vector<int> numbers) {
    int maxi = -10'000 * 10'000;
    
    for (int i=0; i<numbers.size(); i++)
        for (int j=0; j<numbers.size(); j++) {
            if (i == j)
                continue;
            maxi = max(maxi, numbers[i] * numbers[j]);
        }
    return maxi;
}