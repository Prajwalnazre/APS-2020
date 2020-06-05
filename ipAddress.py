#8
import socket
import fcntl
import struct

def get_ip_address(ifname):
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    return socket.inet_ntoa(fcntl.ioctl(
        s.fileno(),
        0x8915,  # SIOCGIFADDR
        struct.pack('256s', ifname[:15])
    )[20:24])


intrfc = input("Enter interface name\n1.lo\n2.wlp3s0\n3.enp2s0\n")
intrfc = intrfc.encode("utf-8")
print(get_ip_address(intrfc))
