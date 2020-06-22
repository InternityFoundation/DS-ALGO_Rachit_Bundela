// https://leetcode.com/problems/friend-circles/submissions/

class Solution {
public:
    void solve(int x, vector<vector<int>>& a, vector <bool>& vis ){
        int n = a.size();
        vis[x] = true;
        for(int j = 0 ; j<n ;j++){
            if(a[x][j] == 1 && vis[j] == false){
                solve(j, a, vis);
            }
        }
        
    }

    int findCircleNum(vector<vector<int>>& a) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        
        
        int n = a.size();
        vector <bool> vis(n, false);
        int k = 0;
        for(int i = 0 ; i<n ;i++){
            if(vis[i] == false){
            k++;
            solve(i, a, vis);   
            }
        }
        return k;
        
    }
};
