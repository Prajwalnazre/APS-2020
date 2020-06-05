
# coding: utf-8

# In[11]:


def appendZero(text):
    zero="00000000"
    temp= 8-len(text)
    return zero[0:temp]+text


# In[12]:


def flipBits(msg):
    checksum=""
    for i in range(len(msg)):
        if msg[i]=="0":
            checksum+="1"
        else:
            checksum+="0"
    return checksum


# In[13]:


from socket import *
import math
serverName = gethostname()
serverPort = 12000
client = socket(AF_INET,SOCK_DGRAM)
msg = input("Enter your message in binary form : ")
#calculate checksum
length = math.ceil(len(msg)/8)
j=0
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
    
else:
    temp = bin(dataSum)[2:]
    temp1 = int(temp[-8:],2)
    temp2 = int(temp[0:-8],2)
    dataSum = temp1+temp2
    dataSum = appendZero(bin(dataSum)[2:])

checksum = flipBits(dataSum)

#send data and checksum
print("Message sent is : ",msg)
print("Checksum is : ",checksum)
client.sendto(msg.encode(),(serverName,serverPort))
client.sendto(checksum.encode(),(serverName,serverPort))
mmsg,serverAddress=client.recvfrom(2048)
print(mmsg.decode())
client.close()

