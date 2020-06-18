//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3363/


class Solution {
public:
    
    void floodfill(vector<vector<char>>& a, int i, int j){
        int n = a.size();
        int m = a[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(a[i][j] != 'O') return;
        
        a[i][j] = 'Z';
        floodfill(a, i, j+1);
        floodfill(a, i, j-1);
        floodfill(a, i+1, j);
        floodfill(a, i-1, j);
        
    }
    
    
    void solve(vector<vector<char>>& a) {
        
        int n = a.size();
        if(n == 0) return;
        int m  = a[0].size();
        
        for(int j  = 0 ; j < m ;j++)
            floodfill(a, 0, j);
        
        
        for(int j  = 0 ; j < m ;j++)
            floodfill(a, n-1, j);        

               
        for(int i  = 0 ; i < n ;i++)
            floodfill(a, i, 0);
        
        
        for(int i  = 0 ; i < n ;i++)
            floodfill(a, i, m-1);
        
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ; j<m; j++){
                if(a[i][j] == 'Z')
                    a[i][j] = 'O';
                else if(a[i][j] == 'O')
                    a[i][j] = 'X';
            }
        }
        
    }
};
