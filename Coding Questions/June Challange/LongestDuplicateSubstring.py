#https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3365/

from collections import defaultdict
m = 1000000007
prime = 26
def cal_hash(s, mid):
    hash_val = 0
    mul = pow(prime, mid-1,m)
    for i in range(mid):
        hash_val = (hash_val + ((ord(s[i]) - ord('a') + 1) * mul))%m
        mul = mul // prime
    return hash_val   
def solve(s, mid):
    n = len(s)
    dct = {}
    dct = defaultdict(int)
    
    hash_val = cal_hash(s, mid)
    # print(hash_val)
    dct[hash_val] = 1
    
    for i in range(1, n):
        if(i+mid > n):
            break
        # print(hash_val)
        # print(i)
        hash_val = (((hash_val - (pow(prime, mid-1, m)* (ord(s[i-1]) - ord('a') + 1)))*prime)%m +   ord(s[i + mid - 1]) - ord('a') + 1)%m
        # print(dct)
        if(dct[hash_val] != 0):
            # print("===============", i)
            # print(dct)
            final_ans = s[i:i+mid]
            if(s[dct[hash_val] - 1 : dct[hash_val] - 1 + mid] == final_ans):
                print(final_ans, mid)
                return (final_ans)
            
                
        dct[hash_val] = i+1
    
    # print(final_ans)
    return ("")
    
    
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        n = len(s)
        l = 0
        h = n
        ans = ""
        while(l<=h):
            mid = (l+h)//2
            print(l, mid, h)
            final_ans = solve(s, mid)
            # print(final_ans)
            if(final_ans != ""):
                ans = final_ans
                l = mid + 1
            else:
                h = mid - 1
        return ans
