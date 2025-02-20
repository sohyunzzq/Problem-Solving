#include <iostream>
#include <cmath>
using namespace std;

int prime(int num) {
    if (num == 1)
        return 0;
    for (int i=2; i<=sqrt(num); i++)
        if (num % i == 0)
            return 0;
    return 1;
}

int main() {
    int m, n;
    cin>>m>>n;

    for (int i=m; i<=n; i++)
        if (prime(i))
            cout << i << '\n';
}