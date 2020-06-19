import numpy as np
def alph_to_num(st):
  key=[]
  for i in range(len(st)):
      key.append(ord(st[i])-65)
  return key
def hillcipher_encrypt(string, key):
  n=len(string)
  st=alph_to_num(string)
  k=alph_to_num(key)
  key=[[0] * 3 for i in range(3)]
  msg=[[0] for i in range(3)]
  result=[[0] for i in range(3)] 
  x=0
  for i in range(n):
    for j in range(n):
      key[i][j]=k[x]
      x+=1
  for i in range(3):
    msg[i][0]=st[i]
  for i in range(n):
    for j in range(1):
      for m in range(n):
        result[i][j]+=key[i][m]*msg[m][j]
      result[i][j]=result[i][j]%26
  encrypted=[]
  for i in range(n):
    encrypted.append(chr(result[i][0]+65))
  return "".join(encrypted)

def hillcipher_decrypt(string, key):
  n=len(string)
  st=alph_to_num(string)
  k=alph_to_num(key)
  key=[[0] * 3 for i in range(3)]
  msg=[[0] for i in range(3)]
  result=[[0] for i in range(3)] 
  x=0
  for i in range(n):
    for j in range(n):
      key[i][j]=k[x]
      x+=1
    #key=np.key
  from sympy import Matrix
  inverse=Matrix(key).inv_mod(26)
  np.inverse=np.array(inverse)
  for i in range(3):
    msg[i][0]=st[i]
  for i in range(n):
    for j in range(1):
      for m in range(n):
        result[i][j]=result[i][j]%26
        result[i][j]+=np.inverse[i][m]*msg[m][j]
      result[i][j]=result[i][j]%26
  decrypted=[]
  for i in range(n):
    decrypted.append(chr(result[i][0]+65))
  return "".join(decrypted)


def Rail_Fence_Cipher_encr(msg, key):
  n = len(msg)
  mat = [[0]*n for i in range(key)]
  i = 0
  j = 0
  dir = "down"
  for j in range(n):
    mat[i][j] = msg[j]
    if(i==key-1):
      dir = "up"
    if(i==0):
      dir = "down"  
    if(dir == "down"):
      i += 1
    else:
      i-=1  
  # print(mat)
  ans = ""
  for i in range(key):
    for j in range(n):
      if(mat[i][j] == 0):
        continue
      ans = ans + mat[i][j]
  # print(ans)     
  return ans  

def Rail_Fence_Cipher_decr(cipher, key):

  n = len(cipher)
  mat = [[0]*n for i in range(key)]
  i = 0
  j = 0
  dir = "down"
  for j in range(n):
    mat[i][j] = "*"
    if(i==key-1):
      dir = "up"
    if(i==0):
      dir = "down"  
    if(dir == "down"):
      i += 1
    else:
      i-=1  
  # print(mat)
  
  ans = ""
  k = 0
  for i in range(key):
    for j in range(n):
      if(mat[i][j] != '*'):
        continue
      mat[i][j] = cipher[k]
      k+=1
  # print(mat) 

  i = 0
  j = 0
  dir = "down"
  for j in range(n):
    ans = ans + mat[i][j]
    if(i==key-1):
      dir = "up"
    if(i==0):
      dir = "down"  
    if(dir == "down"):
      i += 1
    else:
      i-=1    
  return ans  

def both_encr(msg, key1, key2):
  cipher = hillcipher_encrypt(msg, key1)
  return Rail_Fence_Cipher_encr(cipher, key2)

def both_decr(msg, key1, key2):
  cipher = Rail_Fence_Cipher_decr(msg, key2)  
  return hillcipher_decrypt(cipher, key1)

print("Welcome to Encryption/Decryption tool")    
while(True):

  print("Encryption")
  print("1. Hill cipher Encryption ")
  print("2. Rail Fence Cipher Encryption ")
  print("3. both")
  print("Decryption")
  print("4. Hill cipher Decryption ")
  print("5. Rail Fence Cipher Decryption ")
  print("6. both")
  
  print("Enter 0 to exit")
  print("Enter your Option")

  type = int(input())

  if(type==0):
      print("Thank you")
      break
  msg=input("Please Enter the message: ")

  if(type == 1):
    key = input("Please Enter the hill cipher key: ")
    print("The Encrypted message is :",hillcipher_encrypt(msg, key))
  if(type == 2):
    key=int(input("Please Enter the Rail Fence Cipher key: "))
    print("The Encrypted message is :",Rail_Fence_Cipher_encr(msg, key))
  if(type == 3):
    key1 = input("Please Enter the hill cipher key: ")
    key2 = int(input("Please Enter the Rail Fence Cipher key: "))
    print(both_encr(msg, key1, key2))

  if(type == 4):
    key = input("Please Enter the hill cipher decrypt key: ")
    print("The Decrypted message is :",hillcipher_decrypt(msg, key))
  if(type == 5):
    key=int(input("Please Enter the Rail Fence Cipher decrypt key: "))
    print("The Decrypted message is :",Rail_Fence_Cipher_decr(msg, key))
  if(type == 6):
    key1 = input("Please Enter the hill cipher decrypt key: ")
    key2 = int(input("Please Enter the Rail Fence Cipher decrypt key: "))
    print(both_decr(msg, key1, key2))

  print()  

