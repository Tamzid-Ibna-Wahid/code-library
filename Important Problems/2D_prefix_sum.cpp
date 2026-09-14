#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

class NumMatrix {
public:
    vector<vector<long long>> pre;

    NumMatrix(vector<vector<long long>>& matrix, long long r, long long c) {
        pre = vector<vector<long long>>(r + 1, vector<long long>(c + 1, 0));
        build(r, c, matrix);
    }

    void build(long long r, long long c, vector<vector<long long>>& matrix){
        for(long long i = 1; i <= r; i++){
            for(long long j = 1; j <= c; j++){
                pre[i][j] =
                    matrix[i-1][j-1]
                    + pre[i-1][j]
                    + pre[i][j-1]
                    - pre[i-1][j-1];
            }
        }
    }

    long long sumRegion(long long row1, long long col1, long long row2, long long col2){
        return pre[row2+1][col2+1]
             + pre[row1][col1]
             - pre[row1][col2+1]
             - pre[row2+1][col1];
    }
};

signed main(){

    fast_cin();
        
      int r, c;
      cin>>r>>c;
      vector<vector<long long>> matrix1(r, vector<long long>(c));
      
      for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> matrix1[i][j];

            matrix2[i][j] = matrix1[i][j] * matrix1[i][j];
        }
    }
    
    NumMatrix nummatrix1(matrix1, r, c);
    
    int q;
    cin>>q;
    
     while(q--){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        y1--;
        x2--;
        y2--;
        
        double sum = nummatrix1.sumRegion(x1, y1, x2, y2);
        cout << sum << endl;        
      }
        
        
    return 0;
}