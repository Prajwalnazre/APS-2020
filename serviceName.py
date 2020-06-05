#3
import socket

def find_service(port_no,protocol_name):
    service_name = socket.getservbyport(port_no,protocol_name);
    print("service name:",service_name)


n = int(input("Enter port no\n"))
s = input("Enter protocol name\n")
find_service(n,s)
