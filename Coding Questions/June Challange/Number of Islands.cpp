// https://leetcode.com/problems/number-of-islands/submissions/

class Solution {
public:
    
    void solve(vector<vector<char>>& a, vector<vector<bool>>& vis, int i, int j){
        if(i>= a.size() || j >= a[0].size() || i < 0 || j < 0)
            return;
        if(a[i][j] == '0' || vis[i][j] == true)
            return;
        vis[i][j] = true;
        solve(a, vis, i+1, j);
        solve(a, vis, i, j+1);
        solve(a, vis, i-1, j);
        solve(a, vis, i, j-1);
    }
    
    
    int numIslands(vector<vector<char>>& a) {
        int n = a.size();
        if(n==0)
            return 0;
        int m = a[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int k = 0;
        
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j< m; j++){
                if(a[i][j] == '1' && vis[i][j] == false){
                    k++;
                    solve(a, vis, i, j);
                }
            }
        }
        
        return k;
        
        
    }
};
