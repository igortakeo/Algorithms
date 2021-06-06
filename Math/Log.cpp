#include <bits/stdc++.h>

using namespace std;


double LogN(double n, double base){
    return log(n)/log(base); 
}

int main(){

    double n,  x;
    cin >> n >> x;

    cout << LogN(n, x) << endl;

    return 0;
}