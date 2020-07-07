#Updated Server.py
'''
create table test (username varchar(20),name varchar(2),password varchar(20));  //table information
'''
import socket
import os
from _thread import *
import mysql.connector as ms
mydb=ms.connect(host="localhost", user="root", passwd="root",database="server_db")
cursor=mydb.cursor()

Server=socket.socket()
host="127.0.0.1"
port=1234
NumberOfThreads=0

try:
    Server.bind((host,port))
except socket.error as e:
    print(str(e))
print("Hello all... Server is running...")
print("Waiting for clients...")
Server.listen(5)

def multiclient(conn):
    conn.send(str.encode("Server is connected...!"))
    while True:
        data=conn.recv(4096)
        data=data.decode('utf-8')
        data=eval(data)
        #print(data)
        if(data[0]=="1"):
            qs="SELECT password FROM test WHERE username=\"%s\"" %(data[1])
            cursor.execute(qs)
            reply=cursor.fetchall()
            response="0"
            if(len(reply)==1):
                for j in reply:
                    if(j[0]==data[2]):
                        response="1"
                        break
            if not data:
                break
            conn.sendall(str.encode(response))
        elif(data[0]=="2"):
            found=0
            response="0"
            q="SELECT username from test"
            cursor.execute(q)
            records=cursor.fetchall()
            for r in records:
                #print(r[0],data[1])
                if(r[0]==data[1]):
                    response="1"
                    found=1
                    break
            if(found==0):
                qs="INSERT INTO test(username,name,password) VALUES(\"%s\",\"%s\",\"%s\")"%(data[1],data[2],data[3])
                try:
                   cursor.execute(qs)
                   mydb.commit()
                except:
                    mydb.rollback()
            conn.sendall(str.encode(response))

        elif(data[0]=="3"):
            qs="UPDATE test SET name=\"%s\" where username=\"%s\""%(data[2],data[1])
            try:
               cursor.execute(qs)
               mydb.commit()
            except:
                mydb.rollback()
        elif(data[0]=="4"):
            qs="UPDATE test SET password=\"%s\" where username=\"%s\""%(data[2],data[1])
            try:
               cursor.execute(qs)
               mydb.commit()
            except:
                mydb.rollback()
        elif(data[0]=="5"):
            qs="UPDATE test SET name=\"%s\",passw0rd=\"%s\"where username=\"%s\""%(data[2],data[3],data[1])
            try:
               cursor.execute(qs)
               mydb.commit()
            except:
                mydb.rollback()
        elif(data[0]=="6"):
            qs="SELECT * from test where username=\"%s\""%(data[1])
            cursor.execute(qs)
            result=cursor.fetchall()
            print(result)
            result=str(result)
            conn.send(str.encode(result))
        elif(data[0]=="7"):
            qs="DELETE FROM test WHERE username=\"%s\""%(data[1])
            try:
               cursor.execute(qs)
               mydb.commit()
               conn.send(str.encode("1"))
            except:
                mydb.rollback()

        elif(data[0]=="8"):
            break

    conn.close()

while True:
    client,address=Server.accept()
    print("Server is connected to :"+address[0]+":"+str(address[1]))
    start_new_thread(multiclient, (client,))
    NumberOfThreads+=1
    print("Thread number of new client is: "+str(NumberOfThreads))
Server.close()
