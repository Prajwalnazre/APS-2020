import socket


def fun_xor(a, b):


    arr = []


    for i in range(1, len(b)):
        if a[i] == b[i]:
             arr.append('0')
        else:
             arr.append('1')

    return ''.join(arr)



def div(divident, divisor):


    pick = len(divisor)


    tmp = divident[0 : pick]

    while pick < len(divident):

        if tmp[0] == '1':


            tmp = fun_xor(divisor, tmp) + divident[pick]

        else:
            tmp = fun_xor('0'*pick, tmp) + divident[pick]


        pick += 1


    if tmp[0] == '1':
        tmp = fun_xor(divisor, tmp)
    else:
        tmp = fun_xor('0'*pick, tmp)

    checkword = tmp
    return checkword


def decode(data, key):

    l_key = len(key)


    appended_data = data + '0'*(l_key-1)
    remainder = div(appended_data, key)

return remainder


s = socket.socket()
#print ("Socket is created")


port = 12345

s.bind(('', port))
print " Socket is created with port number:",port

s.listen(5)
print "Ready to accept message...."


while True:

    c, addr = s.accept()



    data = c.recv(1024)
    data+='1'

    print(data)

    if not data:
        break

    key = "1001"

    ans = decode(data, key)

    print "Remainder after binary division is :"+ans


    temp = "0" * (len(key) - 1)
    if ans == temp:
        c.sendall("Data:"+data + " does not contain error")
    else:
        c.sendall("Error is detected in the data.")

    c.close()
