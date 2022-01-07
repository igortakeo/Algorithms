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

    int l = 0, r = v.size();

    while(l <= r){

        // This way because of overflow
        // The sum of left and right is greater than 2^31 - 1  
        int mid = l + (r - l)/2;

        cout << "l: " << l << " " << "r: " << r << endl;
        cout << mid << ": " << v[mid] << endl << endl;

        if(v[mid] == target){
            ans = mid;
            break;
        }
        else if(v[mid] > target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }


    if(ans == -1){
        cout << "Target not found" << endl;
    }
    else{
        cout <<  "Founded at position " << ans << endl;
    }

    return 0;
}