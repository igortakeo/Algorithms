#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f 
#define pb push_back
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

/*
    Trie Algorithm (prefix tree)
    add and search in O(N) / N: maximum string lenght
    Memory Complexity O(26*N*M) / M: number of keys in trie
*/


struct Node{
    struct Node *children [26]; 
    bool isleaf;
};

Node* TrieNode(){
    struct Node *root = new Node;
    root->isleaf = false;
    for(int i=0; i<26; i++) root->children[i] = NULL;
    return root;
}

void add(struct Node *root, string key){
    struct Node *next = root;
    int n = key.size();
    for(int i=0; i<n; i++){
        int l = key[i]-'a';
        if(next->children[l] == NULL){
            next->children[l] = TrieNode();
            next = next->children[l];
        }
        else next = next->children[l];
    }
    next->isleaf = true;
}

bool search(struct Node *root, string key){
    struct Node *next = root;
    int n = key.size();
    for(int i=0; i<n; i++){
        int l =  key[i] - 'a';
        if(next->children[l] == NULL) return false;
        next = next->children[l];
    }
    if(next->isleaf) return true;
    else return false;
}

int main(){
    fastcin

    struct Node *Trie = TrieNode();
    /*
    add(Trie, "the");
    add(Trie, "a");
    add(Trie, "there");
    add(Trie, "answer");
    add(Trie, "any");
    add(Trie, "by");
    add(Trie, "bye");
    add(Trie, "their");

    cout << "the: ";
    search(Trie, "the") ? cout << "Yes\n" : cout << "No\n";
    cout << "these: ";
    search(Trie, "these") ? cout << "Yes\n" : cout << "No\n";
    cout << "there: ";
    search(Trie, "there") ? cout << "Yes\n" : cout << "No\n";
    cout << "answ: ";
    search(Trie, "answ") ? cout << "Yes\n" : cout << "No\n";
    cout << "any: ";
    search(Trie, "any") ? cout << "Yes\n" : cout << "No\n";
    cout << "and: ";
    search(Trie, "and") ? cout << "Yes\n" : cout << "No\n";
    add(Trie, "and");
    cout << "and: "; 
    search(Trie, "and") ? cout << "Yes\n" : cout << "No\n";
    */
    return 0;
}
