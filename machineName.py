#1
import socket
host_name = socket.gethostname()
host_ip = socket.gethostbyname(host_name)
print("Host name:",host_name)
print("Host ip Address:",host_ip)

