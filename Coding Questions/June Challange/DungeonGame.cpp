// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3367/

class Solution {
public:
    void print(vector<vector<int>> ans){
        int n = ans.size();
        int m = ans[0].size();        
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<m ;j++)
                cout<<ans[i][j]<<"  ";
            cout<<endl;
        }
    }
    int solve(vector<vector<int>>& ans, vector<vector<int>>& a, int i, int j){
        
        int n = a.size();
        int m = a[0].size();
        // cout<<i<<" "<<j<<endl;
        // print(ans);
        // cout<<"====="<<endl;

                
        if(i>=n || j>=m)
            return INT_MAX; 
        
        if(ans[i][j] != INT_MIN)
            return ans[i][j];
       
        
        if(i == n && j == m-1)
            return 0;
        if(i == n-1 && j == m)
            return 0;

        
        int x, y;
        // if(i<=n-1 && j+1 <= m-1 && ans[i][j+1] == INT_MIN)
             x = solve(ans, a, i, j+1);
        // if(i+1<=n-1 && j <= m-1 && ans[i+1][j] == INT_MIN)
             y = solve(ans, a, i+1, j);
        
        int val = min(x, y) - a[i][j];
        if(val<0)
            val = 0;
        ans[i][j] = val;
        return val;
         
    }
    
    
    
    int calculateMinimumHP(vector<vector<int>>& a) {
            
    
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = a.size();
        int m = a[0].size();
        if(n==0)
            return 0;
        vector<vector<int>> ans(n, vector<int>(m, INT_MIN));
        int val = 0 - a[n-1][m-1];
        if(val<0)
            val = 0;
        ans[n-1][m-1] = val;
        
        return solve(ans, a, 0, 0) + 1;
        
    }
};
