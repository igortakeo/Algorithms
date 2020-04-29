//
// Created by igortakeo on 03/09/19.
//
#include <bits/stdc++.h>
#define N 15
#define MAX 4*N
using namespace std;
//max_size = 4*N
int tree[MAX];

//Implementation of Sum Segment Tree 

//arr[l...r]
//cn : current node in segment tree
//ra and rb : sum in this range
/*
 *                      [0..5]
 *                        36
 *          [0..2]                  [3..5]
 *            9                       27
 *    [0..1]    [2..2]       [3..4]        [5..5]
 *      4          5           16            11
 *[0..0]  [1..1]         [3..3]  [4..4]
 *   1       3              7       9
 *
 * tree[15] = 36 9 27 4 5 16 11 1 3 0 0 7 9 0 0
 *
 * The first "if"  will analyze this situation:
 *        ra:*--------*:rb
 *           l:*----*:r
 *
 * The second "if" will analyze this situation:
 *      l:*------*:r
 *                   ra:*-----*:rb
 * or
 *                  l:*------*:r
 *    ra:*------*:rb
 *
 * Query [1..3] = 15
 * (1)-query(0,5,0,1,3)
 *      -if(0 >= 1 and 5 <= 3) false
 *      -else if(5 < 1 or 0 > 3) false
 *      - middle = 5/2 = 2
 *      - (2):query(0,2,1,1,3) = 8
 *      - (3):query(3,5,2,1,3) = 7
 *      - return (2)+(3) = 15
 * (2)-query(0,2,1,1,3)
 *      -if(0 >= 1 and 2 <= 3) false
 *      -else if(2 < 1 or 0 > 3) false
 *      -middle = 2/2=1
 *      -(4):query(0,1,3,1,3) = 3
 *      -(5):query(2,2,4,1,3) = 5
 *      -return (4) + (5) = 8
 * (4)-query(0,1,3,1,3)
 *      -if(0 >= 1 and 1 <= 3)false
 *      -else if(1 < 1 or 0 > 3) false
 *      -middle = 1/2 = 0
 *      -(6):query(0,0,7,1,3) = 0
 *      -(7):query(1,1,8,1,3) = 3
 *      -return (6)+(7) = 3
 * (6)-query(0,0,7,1,3)
 *      -if(0 >= 1 and 0 <= 3) false
 *      -else if(0 < 1 or 0 > 3) true, return 0 (leaf node does not belong in the range)
 * (7)-query(1,1,8,1,3)
 *      -if(1 >= 1 and 1 <= 3) true, return tree[8]=3 (leaf node belongs in the range)
 * (5)-query(2,2,4,1,3)
 *      -if(2 >= 1 and 2 <= 3) true, return tree[4]=5 (leaf node belongs in the range)
 * (3)-query(3,5,2,1,3)
 *      -if(3 >= 1 and 5 <= 3) false
 *      -else if(5 < 1 or  3 > 3) false
 *      -middle = 4
 *      -(8) query(3,4,5,1,3) = 7
 *      -(9) query(5,5,6,1,3) = 0
 *      -return (8)+(9) = 7
 * (8)-query(3,4,5,1,3)
 *      -if(3 >= 1 and 4 <= 3) false
 *      -else if(4 < 1 or 3 > 3) false
 *      -middle = 3
 *      -(10) query(3,3,11,1,3) = 7
 *      -(11) query(4,4,12,1,3) = 0
 *      - return (10)+(11) = 7
 * (10)-query(3,3,11,1,3)
 *      -if(3 >= 1 and 3 <= 3) true, return tree[11] = 7 (leaf node belongs in the range)
 * (11)-query(4,4,12,1,3)
 *      -if(4>=1 and 4 <= 3) false
 *      -else if(4 < 1 or 4 > 3)true, return 0 (leaf node does not belong in the range)
 * (9)-query(5,5,6,1,3)
 *      -if(5>=1 and 5 <= 3) false
 *      -else if(5 < 1 or 5 > 3) true, return 0 (leaf node does not belong in the range)
 *
 */
int query(int l, int r, int cn, int ra, int rb){
    if(l >= ra and r <= rb) return tree[cn];
    else if(r < ra or l > rb) return 0;
    int middle = (l+r)/2;
    return query(l, middle, cn*2+1, ra, rb) + query(middle+1, r, cn*2+2, ra, rb);
}

//i : index of the value will be updated
//cn : current node in segment tree
//diff : new_value - old_value
//arr[l...r]
void updateValue(int l, int r, int i, int new_value, int cn){
    if(l == r and l == i) tree[cn] = new_value;
    else if(i < l || i > r) return;
    else{
        int middle = (l+r)/2;
        updateValueTree(l, middle, i, new_value, 2*cn+1);
        updateValueTree(middle+1, r, i, new_value, 2*cn+2);
        tree[cn] = tree[2*cn+1] + tree[2*cn+2];
    }
}

//cn : current node in segment tree
//arr[l...r];
int build(int arr[], int l, int r, int cn){
    if(l == r){tree[cn] = arr[l]; return tree[cn];}
    int middle = (l+r)/2;
    int left = build(arr, l, middle, 2*cn+1);
    int right = build(arr, middle+1, r, 2*cn+2);

    return tree[cn] = left + right;
}

int main(){

    int arr[] = {1,3,5,7,9,11};
    int n = 6;

    build(arr, 0, n-1, 0);
	/*
    for(int i=0; i<15; i++) cout << tree[i] << ' ';
    cout << endl;
    cout << query(0, n-1, 0, 1, 3) << endl;
    updateValue(0,n-1, 1, 10, 0);

    for(int i=0; i<15; i++) cout << tree[i] << ' ';
    cout << endl;


    cout << query(0, n-1, 0, 1, 3) << endl;
	*/	
    return 0;
}

//Min Segmentet Tree

int tree[4*MAX];

int query(int l, int r, int cn, int ra, int rb){
    if(r < ra or l > rb) return MAX;
    else if(l >= ra and r <= rb) return tree[cn];
    int middle = (l+r)/2;
    return min(query(l, middle, cn*2+1, ra, rb),query(middle+1, r, cn*2+2, ra, rb));
}

//i : index of the value will be updated
//cn : current node in segment tree
//arr[l...r]
void updateValueTree(int l, int r, int i, int new_value, int cn){
    if(l == r and l == i) tree[cn] = new_value;
    else if(i < l || i > r) return;
    else{
        int middle = (l+r)/2;
        updateValueTree(l, middle, i, new_value, 2*cn+1);
        updateValueTree(middle+1, r, i, new_value, 2*cn+2);
        tree[cn] = min(tree[2*cn+1], tree[2*cn+2]);
    }
}

//cn : current node in segment tree
//arr[l...r];
int build(int arr[], int l, int r, int cn){
    if(l == r){tree[cn] = arr[l]; return tree[cn];}
    int middle = (l+r)/2;
    int left = build(arr, l, middle, 2*cn+1);
    int right = build(arr, middle+1, r, 2*cn+2);

    return tree[cn] = min(left,right);
}

//Segement tree with Lazy Propagation(update of ranges)

int tree[4*MAX];
int lazy[4*MAX];

int query(int l, int r, int cn, int ra, int rb){
   if(lazy[cn]){ 
        tree[cn] += (l-r+ 1)*lazy[cn];    			// Update it
        if(l != r){
            lazy[cn*2+1] += lazy[cn];                 // Mark child as lazy
            lazy[cn*2+2] += lazy[cn];                // Mark child as lazy
        }
        lazy[cn] = 0;                                  // Reset it
    }
    if(l >= ra and r <= rb) return tree[cn];
    else if(r < ra or l > rb) return 0; //if is seg min change 0 to MAX
    int middle = (l+r)/2;
    return query(l, middle, cn*2+1, ra, rb) + query(middle+1, r, cn*2+2, ra, rb);
}

//i : index of the value will be updated
//cn : current node in segment tree
//diff : new_value - old_value
//arr[l...r] update the range[a...b]

/*
 * Sum Segment tree update tree[cn] += (l-r+1)*lazy[cn]
 * Min Segment tree e Max Segment tree :
 * 	Add value in the range tree[cn] += lazy[cn]
 * 	Update range with one value tree[cn] = lazy[cn]
 * 
 */ 
void updateValue(int l, int r, int a, int b, int new_value, int cn){
    if(lazy[cn]){ 
        tree[cn] += (l-r+ 1)*lazy[cn];    			// Update it
        if(l != r){
            lazy[cn*2+1] += lazy[cn];                 // Mark child as lazy
            lazy[cn*2+2] += lazy[cn];                // Mark child as lazy
        }
        lazy[cn] = 0;                                  // Reset it
    }
    if(l > b or r < a) return;
    else if(a <= l and r <= b){
		tree[cn] += (l-r+1)*new_value;
        if(l != r){
            lazy[cn*2+1] += new_value;                 // Mark child as lazy
            lazy[cn*2+2] += new_value;                // Mark child as lazy
        }
    }
    else{
        int middle = (l+r)/2;
        updateValue(l, middle, a, b, new_value, 2*cn+1);
        updateValue(middle+1, r, a, b, new_value, 2*cn+2);
        tree[cn] = tree[2*cn+1] + tree[2*cn+2];
    }
}

//cn : current node in segment tree
//arr[l...r];
int build(int arr[], int l, int r, int cn){
    if(l == r){tree[cn] = arr[l]; return tree[cn];}
    int middle = (l+r)/2;
    int left = build(arr, l, middle, 2*cn+1);
    int right = build(arr, middle+1, r, 2*cn+2);

    return tree[cn] = left + right;
}



