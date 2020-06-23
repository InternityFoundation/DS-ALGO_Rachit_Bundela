// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3368/

class Solution {
public:
    int singleNumber(vector<int>& a) {
        ios::sync_with_stdio(false),cin.tie(NULL);  cout.tie(NULL);      
        int ones = 0;
        int twos = 0;
        for(int i = 0 ; i<a.size() ;i++){
            ones = (ones ^ a[i]) & (~twos);
            twos = (twos ^ a[i]) & (~ones); 
        }
        return ones;
    }
};
