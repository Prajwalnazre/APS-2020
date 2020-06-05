import socket

s = socket.socket()


port = 13333


s.connect(('127.0.0.1', port))


data= raw_input("Enter message in binary:")

p=data.count('1')
if p&1==1:
      data+='1'
      print("parity is odd") 
else:
      data+='0'
      print("parity is even") 

print("After adding parity bit:",data) 

s.sendall(data)
