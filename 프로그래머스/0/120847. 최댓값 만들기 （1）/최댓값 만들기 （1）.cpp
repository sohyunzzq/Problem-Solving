#include <vector>
using namespace std;

int solution(vector<int> numbers) {
    int maxi = 0;
    
    for (int i=0; i<numbers.size(); i++)
        for (int j=i+1; j<numbers.size(); j++)
            maxi = max(maxi, numbers[i] * numbers[j]);
    return maxi;
}