// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    
    bool solve(vector<vector<int>>& a, int numCourses, vector <int>& vis, int x){     
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);        
        vis[x] = 1; // procesing
        for(int i = 0 ; i < a[x].size(); i++){
            if(vis[a[x][i]] == 0)
                continue;            
            if(vis[a[x][i]] == 1)
                return false;            
            bool ans = solve(a, numCourses, vis, a[x][i]);
            if(ans == false )
                return false;
        }
        vis[x] = 2;
        
        return true;
    }
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        
        vector<vector<int>> a(numCourses);
        int n = prerequisites.size();
        // set <int> st;
        vector <int> vis(numCourses, 0);
        for(int i = 0 ; i<n ;i++){
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            
            a[x].push_back(y);
        }
        
        for(int i = 0 ; i<numCourses; i++){
            if(vis[i] != 2){
                bool ans = solve(a, numCourses, vis, i);
                if(ans == false)
                    return false;
            }
        }
        return true;
    }
};
