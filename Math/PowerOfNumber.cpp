#include <bits/stdc++.h>

using namespace std; 

// Time Complexity O(logn)
// Space Complexity O(1)

int power(int x, int y){

    if(x == 0) return 0;
    if(y == 0) return 1;
    if(y == 1) return x;

    int result = power(x, y/2);

    if(y%2 == 0)
        return result*result;
    else
        return x*result*result;

}

int main(){

    int x, y;

    cin >> x >> y;

    cout << power(x, y) << endl;

    return 0;
}