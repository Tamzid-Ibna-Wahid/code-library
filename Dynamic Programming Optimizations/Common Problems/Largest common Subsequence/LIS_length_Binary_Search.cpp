
// Binary Search Approach of Finding LIS by
// reducing the problem to longest
// common Subsequence
#include <bits/stdc++.h>
using namespace std;
int lis(vector<int>& arr){

    // Binary search approach
    int n = arr.size();
    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > ans.back()) {
            ans.push_back(arr[i]);
        }
        else{
           int low = lower_bound(ans.begin(), ans.end(), arr[i])- ans.begin();
            ans[low] = arr[i];
        }
    }
   return ans.size();
}

int main(){
    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    printf("Length of LIS is %d\n", lis(arr));
    return 0;
}
