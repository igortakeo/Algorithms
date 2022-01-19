#include <bits/stdc++.h>

using namespace std;

int main(){

    map<int, string>keypad;
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string>permutations;

    keypad[0] = "+";
    keypad[1] = "";
    keypad[2] = "ABC";
    keypad[3] = "DEF";
    keypad[4] = "GHI";
    keypad[5] = "JKL";
    keypad[6] = "MNO";
    keypad[7] = "PQRS";
    keypad[8] = "TUV";
    keypad[9] = "WXYZ";

    int numberOnePosition = -1;
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] == 1){
            numberOnePosition = i;
        }
    }

    if(numberOnePosition != -1){
        numbers.erase(numbers.begin()+numberOnePosition);
    }

    for(int i=0; i<keypad[numbers[0]].size(); i++){
        string character = "";
        character += keypad[numbers[0]][i];
        permutations.push_back(character);
    }

    for(int i=1; i<numbers.size(); i++){
        
        vector<string> currentPermutation;

        for(int j=0; j<permutations.size(); j++){

            string currentString = permutations[j];

            for(int k=0; k<keypad[numbers[i]].size(); k++){
                
                currentString += keypad[numbers[i]][k];

                currentPermutation.push_back(currentString);

                currentString.pop_back();
            }
        }

        permutations.clear();
        permutations = currentPermutation;
    }

    cout << permutations.size() << endl;

    for(auto i : permutations){
        cout << i << " "; 
    }
    cout << endl;

    return 0;
}