#Updated client with Password confirmation while changing current password
import getpass
import socket
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

def update(username):
    print("What do you want to Update?")
    print("1. Name")
    print("2. Password")
    print("3. Both")
    opt=int(input("Enter your choice: "))
    if(opt==1):
        name=input("Enter the new name to be updated: ")
        snd=[]
        snd.append("3")
        snd.append(username)
        snd.append(name)
        snd=str(snd)
        Client.send(str.encode(snd))
        print("Name is Updated Successfully")
    elif(opt==2):
        flag=0
        while(flag!=1):
            old=input("Enter your current Password:")
            old=Rail_Fence_Cipher_encr(old,3)
            new=[]
            new.append("1")
            new.append(username)
            new.append(old)
            new=str(new)
            Client.send(str.encode(new))
            ans=Client.recv(1024)
            ans=ans.decode('utf-8')
            print(ans)
            if(int(ans)==1):
                flag=1
                password=input("Enter your New Password: ")
                confirm=input("Confirm your Password: ")
                if(password!=confirm):
                    flag=0
                    print("Both Passwords should be same...! Please Re-enter your Password")
                else:
                    flag=1
            else:
                print("Invalid Password, Please try again")

        password=Rail_Fence_Cipher_encr(password, 3)
        snd=[]
        snd.append("4")
        snd.append(username)
        snd.append(password)
        snd=str(snd)
        Client.send(str.encode(snd))
        print("Password Updated Successfully")
    elif(opt==3):
        snd=[]
        snd.append("5")
        snd.append(username)
        name=input("Enter the new name to be updated: ")
        while(flag!=1):
            old=input("Enter your current Password:")
            old=Rail_Fence_Cipher_encr(old,3)
            new=[]
            new.append("1")
            new.append(username)
            new.append(old)
            new=str(new)
            Client.send(str.encode(new))
            ans=Client.recv(1024)
            ans=ans.decode('utf-8')
            print(ans)
            if(int(ans)==1):
                flag=1
                password=input("Enter your New Password: ")
                confirm=input("Confirm your Password: ")
                if(password!=confirm):
                    flag=0
                    print("Both Passwords should be same...! Please Re-enter your Password")
                else:
                    flag=1
            else:
                print("Invalid Password, Please try again")
        password=Rail_Fence_Cipher_encr(password, 3)
        snd.append(name)
        snd.append(password)
        snd=str(snd)
        Client.send(str.encode(snd))
        print("Name and Password Updated Successfully")


def view(username):
    snd=[]
    snd.append("6")
    snd.append(username)
    snd=str(snd)
    Client.send(str.encode(snd))
    data=Client.recv(1024)
    data=data.decode('utf-8')
    data=eval(data)
    for r in data:
        uname=r[0]
        fname=r[1]
        pwd=r[2]
    print("ID  |  Username  |  Name")
    print(uname,"  |  ",fname,"  |  ",pwd)

def delete(username):
    snd=[]
    snd.append("7")
    snd.append(username)
    snd=str(snd)
    Client.send(str.encode(snd))
    data=Client.recv(1024)
    data=data.decode('utf-8')
    if(data=="1"):
        print("Deleted your Information successfully... See you...!")

def login():
    count=0
    while(count==0):
        snd=[]
        snd.append("1")
        print("Enter username")
        username=input()
        print("enter password")
        password=getpass.getpass()
        password=Rail_Fence_Cipher_encr(password,3)
        #print(password)
        snd.append(username)
        snd.append(password)
        newsend=str(snd)
        Client.send(str.encode(newsend))
        ans=Client.recv(1024)
        ans=ans.decode('utf-8')
        if(int(ans)==1):
            print("Logged In Successfully")
            count=1
        else:
            print("Invalid Email/Password, Please try again")
    flag=0
    while(flag!=1):
        print("*****Welcome to Dashboard*****")
        print("1. Upadte")
        print("2. View")
        print("3. Delete")
        print("4. Logout")
        chc=int(input("Please Enter your choice: "))
        if(chc==1):
            update(username)
        elif(chc==2):
            view(username)

        elif(chc==3):
            delete(username)
            flag=1
        else:
             flag=1


def register():
    snd=[]
    snd.append("2")
    username=input("Enter Email id(This will be your username): ")
    name=input("Enter your name: ")
    flag=0
    while(flag!=1):
        print("Enter your Password: ")
        password = getpass.getpass()
        confirm=input("Confirm your Password: ")
        if(password!=confirm):
            print("Both Passwords should be same...! Please Re-enter your Password")
        else:
            flag=1
    password=Rail_Fence_Cipher_encr(password,3)
    snd.append(username)
    snd.append(name)
    snd.append(password)
    snd=str(snd)
    Client.send(str.encode(snd))
    ans=Client.recv(1024)
    ans=ans.decode('utf-8')
    if(int(ans)==0):
        print("Account Created Successfully.. Please login to continue")
    else:
        print("Email Id already exists, Please Login...")



Client=socket.socket()
host="127.0.0.1"
port=1234

print("Waiting for server to connect")
try:
    Client.connect((host,port))
except socket.error as e:
    print(str(e))

flag=0
ans=Client.recv(1024)
print(ans.decode('utf-8'))
while (flag==0):
    print("*******Welcome*******")
    print("1. Login")
    print("2. Registration")
    print("3. Exit")
    choice=int(input("Enter your option: "))
    if(choice==1):
        login()
    elif(choice==2):
        register()
    else:
        l = ["8"]
        l = str(l)
        Client.send(str.encode(l))
        print("Thank You")
        break
        flag=1

Client.close()
