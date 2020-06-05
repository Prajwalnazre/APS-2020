
def highestPowerof2(n): 

	res = 0; 
	for i in range(n, 0, -1): 
		if ((i & (i - 1)) == 0): 
		
			res = i; 
			break; 
		
	return res; 

n = 100000; 
print(highestPowerof2(n));  

