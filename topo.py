from mininet.topo import Topo
from mininet.node import Controller, RemoteController

class MyTopo( Topo ):
    "Topology"

    def __init__( self ):
	
        host1=self.addHost('h1',ip = '10.23.25.5')
        host2=self.addHost('h2')
        host3=self.addHost('h3')
        host4=self.addHost('h4')
        host5=self.addHost('h5')
        host6=self.addHost('h6')

	#Add switches

        switch1=self.addSwitch('s1')
        switch2=self.addSwitch('s2')

	c1 = self.addController('c1')

	#Add links

        self.addLink(switch1,switch2)
        self.addLink(switch1,host1)
        self.addLink(switch1,host2)
        self.addLink(switch1,host3)
        self.addLink(switch2,host4)
        self.addLink(switch2,host5)
        self.addLink(switch2,host6)
	
	switch1.start([c1])
	switch2.start([c1])

	

topos = { 'mytopo': ( lambda: MyTopo() ) }

#print(topos)






	
