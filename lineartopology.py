from mininet.topo import Topo
from mininet.net import Mininet
from mininet.node import CPULimitedHost
from mininet.link import TCLink
from mininet.util import irange,dumpNodeConnections
from mininet.log import setLogLevel

class LinearTopo(Topo):
    "Linear topology of n switches, with one host per switch."
    def __init__(self, n=2, **opts):
        super(LinearTopo, self).__init__(**opts)
        self.n = n
		
        Host1 = self.addHost( 'h1' )
        Host2 = self.addHost( 'h2' )
        Host3=self.addHost('h3')
        Switch1 = self.addSwitch( 's1' )
        Switch2 = self.addSwitch( 's2' )
        Switch3=self.addSwitch('s3')
        #self.link=dict(bw=10, delay='5ms', loss=1, max_queue_size=1000, use_htb=True)
        # Add links
        print("adding links")
        self.addLink( Host1,Switch1)
        self.addLink( Host2,Switch2)
        self.addLink( Host3,Switch3)       
        self.addLink( Switch1,Switch2)
        self.addLink( Switch2,Switch3)
def simpleTest():
	"Create and test a simple network"
	topo = LinearTopo(n=4)
	net = Mininet(topo)
	net.start()
	#print "Dumping host connections"
	dumpNodeConnections(net.hosts)
	#print "Testing network connectivity"
	net.pingAll()
	net.stop()
if __name__ == '__main__':
	setLogLevel('info')
	simpleTest()
