#include <bits/stdc++.h>

using namespace std;


int main(){

    int n, target, ans = -1;
    cin >> n;
    cin >> target;

    vector<int>v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    for(int i=0; i<n; i++){
        cout << i << ": " << v[i] << endl;
    }
    cout << endl;
    cout << endl;

    auto it = upper_bound(v.begin(), v.end(), target);

    cout << "Upper bound C++ function: " << (it - v.begin()) << endl;

    int l=0, r=n;

    while(l < r){

        int mid = l + (r-l)/2;

        cout << mid  << " (" << l << "," << r << ")"<< " " << v[mid] << endl;

        if(target >= v[mid]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }

    cout << "Upper bound implementation: " << l << endl;
}