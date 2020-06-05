def calcRedundantBits(m): 
  
    # Use the formula 2 ^ r >= m + r + 1 
    # to calculate the no of redundant bits. 
    # Iterate over 0 .. m and return the value 
    # that satisfies the equation
    r=2
    while True:
        
        if(2**r >= m + r + 1): 
            break
        r+=1
    return r

def detectError(arr, nr): 
    n = len(arr) 
    res = 0
  
    # Calculate parity bits again 
    for i in range(nr): 
        val = 0
        for j in range(1, n + 1): 
            if(j & (2**i) == (2**i)): 
                val = val ^ int(arr[-1 * j]) 
  
        # Create a binary no by appending 
        # parity bits together. 
  
        res = res + val*(10**i) 
  
    # Convert binary to decimal 
    return int(str(res), 2) 

from socket import *
receiverPort=12000
receiver=socket(AF_INET,SOCK_DGRAM)
receiver.bind(('',receiverPort))
print('Receiver is ready to receive: ')

msg,senderAddress=receiver.recvfrom(2048)
msg = msg.decode()
msg = "10011100101"
print("Message received is ",msg)


#Calculate the no of Redundant Bits Required 
m = len(msg) 
r = calcRedundantBits(m)
correction = detectError(msg, r) 


if str(correction)=="0":
    print("No error")
    mmsg = "No error"
else:
    print("The position of error is " + str(correction))
    mmsg =  "The position of error is " + str(correction)
receiver.sendto(mmsg.encode(),senderAddress)

