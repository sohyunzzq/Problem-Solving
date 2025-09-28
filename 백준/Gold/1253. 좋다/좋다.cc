#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // i번째 수를 완성할 수 있는가
        int left = 0;
        int right = n - 1;
        
        while(left < right) {
            if (left == i)
                left++;
            if (right == i)
                right--;
            
            if (left >= right)
                break;

            int sum = arr[left] + arr[right]; 
            
            if (sum == arr[i]) {
                cnt++;
                break;
            }
            
            if (sum < arr[i])
                left++;
            else
                right--;
        }
    }
    
    cout << cnt;
}