#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, p1, r, p2;
    cin>>a>>p1>>r>>p2;
    
    double slice=double(a)/p1;
    double whole=(M_PI*r*r)/p2;
    
    if(slice < whole)
        cout<<"Whole pizza";
    else
        cout<<"Slice of pizza";
}