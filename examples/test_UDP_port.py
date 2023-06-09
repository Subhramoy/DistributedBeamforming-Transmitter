import socket
import struct
import time
import sys
import pmt
import numpy
import math
import cmath
import json

multicast_group = ('224.3.29.71', 10000)
server_address = ('', 10000)

# Create the socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind to the server address
# sock.bind(server_address)


# Tell the operating system to add the socket to the multicast group
# on all interfaces.
group = socket.inet_aton('224.3.29.71')
mreq = struct.pack('4sL', group, socket.INADDR_ANY)
sock.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)



# Receive/respond loop
while True:
    # print >>sys.stderr, '\nwaiting to receive message'
    # data, address = sock.recvfrom(1024)

    # print >>sys.stderr, 'received %s bytes from %s' % (len(data), address)
    # print >>sys.stderr, data

    # print >>sys.stderr, 'sending acknowledgement to', address
    sock.sendto('dummy_text', multicast_group)
    time.sleep(1)
