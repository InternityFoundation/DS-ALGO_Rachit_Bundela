import numpy as np
def solve(mat, key):
  n = len(mat)
  k = 0
  for i in range(n, 3):
    k+=1
    mat.append(ord('@'))

  res = np.dot(key,mat)
  result = []
  # print(res)
  for i in range(len(res)):
    # print(res[i]%26 + 65)
    result.append(chr(res[i]%26 + 65))
  ans = "".join(result)
  ans = ans[:3-k] + ""*k
  return (ans)

print("Enter Plain Text")
s = input()
k = input()
key = [[0] * 3 for i in range(3)]
w = 0
for i in range(3):
  for j in range(3):
    key[i][j] = ord(k[w]) - ord('A')
    w += 1
  
# print(key)
ans = ""
for i in range((len(s)-1)//3 + 1):
  mat = []
  for j in range(3):
    mat.append(ord(s[i*3+j]) - ord('A'))
    if(i*3 + j >= len(s) - 1):
      break
  ans = ans + solve(mat, key)
print(ans)




