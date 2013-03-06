#!/usr/bin/env python
class Server(object):
    def __init__(self, ip, hostname):
        self.ip = ip
	self.hostname = hostname
    def ping(self, ip_addr):
        print "Pinging %s from %s (%s)" % (ip_addr, self.ip, self.hostname)
if __name__ == '__main__':
    sever = Server('192.168.106.1', 'bumbly')
    sever.ping('192.168.106.2')
    print sever.ip
