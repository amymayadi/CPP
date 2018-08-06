import commands
import os
for i in range(0,7):
	'''
	f = os.popen('./tcplistener')
	data = f.readline()
	f.close()
	'''
	print i
	r_v = os.system('./tcplistener')
	print '\n'
