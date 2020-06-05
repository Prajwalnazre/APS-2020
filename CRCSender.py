import socket

def fun_xor(a, b):
    arr = []


    for i in range(1, len(b)):
        if a[i] == b[i]:
            arr.append('0')
        else:
            arr.append('1')

    return ''.join(arr)



def division(divident, divisor):


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


def encode(data, key):

    l_key = len(key)


    appended_data = data + '0'*(l_key-1)
    remainder = division(appended_data, key)


    codeword = data + remainder
    return codeword
    
s = socket.socket()


port = 12345


s.connect(('127.0.0.1', port))


data= raw_input("Enter message in binary:")
#s.sendall(input_string)
#data =(''.join(format(ord(x), 'b') for x in input_string))
#print (type(data ))
key = "1001"

ans = encode(data,key)
print("Encoded data :",ans)
s.sendall(ans)

print (s.recv(1024) )


s.close()
