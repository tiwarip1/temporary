import matplotlib.pyplot as plt
import numpy as np

l=[1746,887,588,444,384,319,281,246,219,197,181,166,147,137,129,115,103,98,94,86,74,69,65]
m=[]
for i in range(0,len(l)):
    m.append(l[0]/l[i])
    
plt.plot(m)
plt.title("Speed up over processors")
plt.xlabel("Number of Processors")
plt.ylabel("Speed up")
plt.savefig('speedup.png',dpi=400)