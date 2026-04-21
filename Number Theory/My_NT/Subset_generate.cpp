#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
vector<vector<int>> subsetgenarate(vector<int>& v){
    int size_of_vector =v.size();
    int subset_count =(1<<size_of_vector);        // 2^n subset

    vector<vector<int>>all_subset;

    for(int i=0; i < subset_count; i++){

        vector<int>subset;

        for(int j=0;j<size_of_vector;j++){
	         if( (i>>j) & 1) subset.push_back(v[j]);
        }
        all_subset.push_back(subset);
    }
    return all_subset;  
}


int main(){
    vector<int> v ={1,2,3,4,5};

    vector<vector<int>>ans = subsetgenarate(v);

    for(auto &i : ans){
        for(auto &j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}