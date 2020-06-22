#https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3366/

def solve(l, k, fct):

    
    # print(l)
    # print(k)
    # print(fct)
    n = len(l)
    
    q = k//fct
    r = k%fct
    # print(q, r)
    if(fct == 1):
        if(q==2):
            l[1], l[0] = l[0], l[1] 
            return l
        else:
            return l
    if(q == 0 and r == 1):
        return l;

        
    if(fct == 2):
        if(q==1 and r==0):
            l[1], l[2] = l[2], l[1]
        if(q==1 and r == 1):
            l[1], l[0] = l[0], l[1]
        
        if(q==2 and r == 0):
            l[1], l[0] = l[0], l[1]
            l[1], l[2] = l[2], l[1]
        
        if(q == 2 and r == 1):
            l[2], l[0] = l[0], l[2]
            l[1], l[2] = l[2], l[1]
        if(q == 3 and r == 0):           
            l[2], l[0] = l[0], l[2]
        
        return l
            
    f = 0
    if(r==0):
        q = q - 1
        r = fct - 1
        f = 1
        
    x = l[q]
    l.remove(x)
    l = [x] + l
    if(f == 1):
        r = fct
    ans = l[0:1] + solve(l[1:], r, fct//(n-1))
    return ans
    
def fact(n):
    ans = 1
    for i in range(1,n+1):
        ans = ans * i
    return ans    


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        if(n==1):
            return "1"
        l = list(range(1, n+1))
        fct = fact(n - 1)
        ans = solve(l, k, fct)
        for i in range(len(ans)):
            ans[i] = str(ans[i])
        return "".join(ans)
        
