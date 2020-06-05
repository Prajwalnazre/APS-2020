
# coding: utf-8

# In[1]:


def appendZero(text):
    zero="00000000"
    temp= 8-len(text)
    return zero[0:temp]+text


# In[2]:


def flipBits(msg):
    checksum=""
    for i in range(len(msg)):
        if msg[i]=="0":
            checksum+="1"
        else:
            checksum+="0"
    return checksum


# In[ ]:


from socket import *
import math
serverPort=12000
server=socket(AF_INET,SOCK_DGRAM)
server.bind(('',serverPort))
print('Receiver is ready to receive: ')
while True:
    msg,clientAddress=server.recvfrom(2048)
    checksum,clientAddress=server.recvfrom(2048)
    msg=(msg.decode())
    checksum=(checksum.decode())
    #change message to check if failure case
    #msg = "1110011101"
    #calculate sum of the data received
    length = math.ceil(len(msg)/8)
    
    data = []
    if(len(msg)%8==0):
        for i in range(0,len(msg),8):
            data.append(int(msg[i:i+8],2))
    else:
        limit = len(msg)-len(msg)%8
        for i in range(0,limit,8):
             data.append(int(msg[i:i+8],2))
        lastNum = appendZero(msg[limit:])
        data.append(int(lastNum,2))
    dataSum = sum(data)
    if(len(bin(dataSum))-2<=8):
        dataSum = dataSum
        dataSum = appendZero(bin(dataSum)[2:])
        dataSum = int(dataSum,2)
    else:
        temp = bin(dataSum)[2:]
        temp1 = int(temp[-8:],2)
        temp2 = int(temp[0:-8],2)
        dataSum = temp1+temp2
        
    #calculate sum of data and checksum
    finalSum = dataSum+int(checksum,2)
    finalSum = flipBits(bin(finalSum)[2:])
    print("Message received is ",msg)
    print("After adding data and checksum : ",finalSum)
    if finalSum == "00000000":
        message = "Message is recieved successfully"
        print(message)
        
    else:
        message = "Message not received successfully"
        print(message)
    message=str(message)
    server.sendto(message.encode(),clientAddress)

