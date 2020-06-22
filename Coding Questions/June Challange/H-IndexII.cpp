//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3364/

class Solution {
public:
    int hIndex(vector<int>& a) {
        int n  = a.size();
        
        for(int i = -1 ; i<n-1; i++){
            if(n-i-1 <= a[i+1]) return n-i-1;
        }

        return 0;
        
    }
};
