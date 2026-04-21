#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


struct trieNode{
    long long value;
    trieNode *arr[2];
};

trieNode *newNode(){
    trieNode *temp = new trieNode;
    temp->value = 0;
    temp->arr[0] = NULL;
    temp->arr[1] = NULL;
    return temp;
}

void insert(trieNode *root, long long pre_xor, long long max_bits){
    trieNode *temp = root;
 
    bool val;
    for (long long i=max_bits; i>=0; i--){
        val = pre_xor & (1ll<<i);
 
        if (temp->arr[val] == NULL) temp->arr[val] = newNode();
        temp = temp->arr[val];
    }
 
    temp->value = pre_xor;
}

long long query(trieNode *root, long long pre_xor, long long max_bits){
    trieNode *temp = root;
    
    bool val;
    for (long long i= max_bits; i>=0; i--){
        val = pre_xor & (1ll<<i);
 
        if (temp->arr[!val] != NULL) temp = temp->arr[!val];
        else if (temp->arr[val] != NULL) temp = temp->arr[val];
    }
    
    return pre_xor^(temp->value);
}

long long maxSubarrayXOR(vector<long long>& arr){
    int  n = arr.size();
    int max_val = *max_element(arr.begin(), arr.end());
    
    // int  max_bits = 64 - __builtin_clzll(max_val | 1);
    int max_bits = 32;
    
    
    trieNode *root = newNode();
    insert(root, 0, max_bits);
    long long result = 0, pre_xor =0;
 
    for (long long i=0; i<n; i++){
        pre_xor = pre_xor^arr[i];
        insert(root, pre_xor, max_bits);
        result = max(result, query(root, pre_xor, max_bits));
    }
    
    return result;
}

// https://codeforces.com/blog/entry/123404
// https://www.geeksforgeeks.org/dsa/find-the-maximum-subarray-xor-in-a-given-array/
// https://cses.fi/problemset/task/1655


signed main(){

    fast_cin();
    
     // Maximum xor subarray
        
        int n;
        cin>>n;
       
       vector<long long> v(n);
       for(int i = 0; i<n; i++){
         cin>>v[i];
       }
       
       cout<<maxSubarrayXOR(v)<<endl;    
    
        
        
        
    return 0;
}