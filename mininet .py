from mininet.topo import Topo

class MyTopo( Topo ):
    "Topology"

    def __init__( self ):
        "Create custom topo"

        # Initialize topology
        Topo.__init__( self):
	
	#Add hosts
	
	host1=self.addHost('h1')
	host2=self.addHost('h2')
	host3=self.addHost('h3')
	host4=self.addHost('h4')
	host5=self.addHost('h5')
	host6=self.addHost('h6')
	host7=self.addHost('h7')
	host8=self.addHost('h8')

	#Add switches

	switch1=self.addSwitch('s1')
	switch2=self.addSwitch('s2')
	switch3=self.addSwitch('s3')
	switch4=self.addSwitch('s4')
	switch5=self.addSwitch('s5')
	switch6=self.addSwitch('s6')
	switch7=self.addSwitch('s7')
	switch8=self.addSwitch('s8')
	switch9=self.addSwitch('s9')
	switch10=self.addSwitch('s10')

	#Add links

	self.addLink(switch1,switch3)
	self.addLink(switch1,switch5)
	self.addLink(switch2,switch4)
	self.addLink(switch2,switch6)
	self.addLink(switch3,switch7)
	self.addLink(switch3,switch8)
	self.addLink(switch4,switch7)
	self.addLink(switch4,switch8)
	self.addLink(switch5,switch9)
	self.addLink(switch5,switch10)
	self.addLink(switch6,switch9)
	self.addLink(switch6,switch10)
	self.addLink(switch7,host1)
	self.addLink(switch7,host2)
	self.addLink(switch8,host3)
	self.addLink(switch8,host4)
	self.addLink(switch9,host5)
	self.addLink(switch9,host6)
	self.addLink(switch10,host7)
	self.addLink(switch10,host8)

topos = { 'mytopo': ( lambda: MyTopo() ) }






	
