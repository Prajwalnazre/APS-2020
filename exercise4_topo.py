from mininet.topo import Topo

class MyTopo( Topo ):
    def build( self ):
        "Create custom topo."
        # Add hosts and switches
        print("adding host and switches")
        Host1 = self.addHost( 'h1' )
        Host2 = self.addHost( 'h2' )
        Host3=self.addHost('h3')
        Host4=self.addHost('h4')
        Host5=self.addHost('h5')
        Host6=self.addHost('h6')
        Switch1 = self.addSwitch( 's1' )
        Switch2 = self.addSwitch( 's2' )
        Switch3=self.addSwitch('s3')
        Switch4=self.addSwitch('s4')
        #linkopts2 = {'bw':10, 'delay':'5ms', 'loss':1, 'max_queue_size':1000, 'use_htb':True}
        # Add links
        print("adding links")
        self.addLink( Host1,Switch1)
        self.addLink( Host2,Switch1)     
        self.addLink( Host3,Switch2)
        self.addLink( Host4,Switch3)
        self.addLink( Host5,Switch4)
        self.addLink( Host6,Switch4)
        self.addLink( Switch1,Switch2)
        self.addLink( Switch2,Switch3)
        self.addLink( Switch3,Switch4)


topos = { 'mytopo': ( lambda: MyTopo() ) }
