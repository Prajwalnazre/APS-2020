#15
import socket
try:
      addr="270.0.0.0"
      socket.inet_aton(addr)
      print ("ipv4 address")
except socket.error:
      print ("not ip4 address")
