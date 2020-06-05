import socket

s = socket.socket()
#print ("Socket is created")


port = 13333

s.bind(('', port))
print " Socket is created with port number:",port

s.listen(5)
print "Ready to accept message...."


while True:

    c, addr = s.accept()



    data = c.recv(1024)
    #print data
    if data[0]==0:
       d='1'+data[1:]
    else:
       d='0'+data[1:]

    if not data:
        break

    print "Data recieved is:",d
    p=d.count('1')
    if p&1==0:
       print "Parity is even hence No error in the data...."
    else:
       print "Parity is odd hence error is detected..."
