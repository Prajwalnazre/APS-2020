#2
import socket
host_name = input("Enter Host Name\n")
host_ip = socket.gethostbyname(host_name)
print("IP address for",host_name,"is",host_ip)
