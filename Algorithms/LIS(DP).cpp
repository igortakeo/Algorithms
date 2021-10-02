#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(n^2)
// Space Complexity O(n)

vector<int>arr;

int lis(int n){

	vector<int>arr_lis(n, 1);

	for(int i=1; i<n; i++){
		for(int j=0; j < i; j++){
			if(arr[i] > arr[j]) {
				arr_lis[i] = max(arr_lis[i], arr_lis[j]+1);
			}
		}
	}

	for(auto a : arr_lis) cout << a << ' ';
	cout << endl;

	return *max_element(arr_lis.begin(), arr_lis.end());
}

int main(){

	int n, x;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> x;
		arr.push_back(x);
	}

	cout << lis(n) << endl;

	return 0;
}