#include <bits/stdc++.h>
using namespace std;

vector<int>found_patt;

vector<int> prefix_function(string s){

	int n = s.size();
	vector<int>pi(n);
	pi[0]=0;
	for(int i=1; i<n; i++){
		int j = pi[i-1];
		while(j > 0 and s[i] != s[j]){j = pi[j-1];}
		if(s[i] == s[j]) j++;
		pi[i] = j;	
	}

	return pi;
}

void kmp(string t, string s) { 
    int M = s.size();
    int N = t.size(); 
  
    vector<int> pi = prefix_function(s);

    int i = 0; // index for s[] 
    int j = 0; // index for t[] 
    while (i < N) { 
        if (s[j] == t[i]){ j++; i++;} 
        if (j == M) { 
          	found_patt.push_back(i-j); 
            j = pi[j-1]; 
        } 
        else if (i < N && s[j] != t[i]) { 
            if (j != 0) j = pi[j-1]; 
            else i = i+1; 
        } 
    } 
} 

int main(){

	string s, t;
	cin >> t >> s;

	kmp(t,s);
	cout << "Found " << found_patt.size() << " occurrences" << endl;
	cout << "Found pattern in the positions ";
	for(auto a : found_patt) cout << a << ' ';
	cout << endl;
	
	vector<int>pf = prefix_function(t); 
	for(auto a : pf) cout << a << ' ';
	cout << endl;


	return 0;
}
