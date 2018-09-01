hRead = open("F:\\test\\LP2\\14.txt", "r")
hWrite = open("F:\\test\\LP2\\ans14.txt","w")
n=int(hRead.readline())
v=[0 for i in range(n)]
for i in range(n):
    v[i]=[float(i) for i in hRead.readline().split()]  
x12=0.0
x11=0.0
x22=0.0
x21=0.0
y1=0.0
y2=0.0
for i in range(n):
    x12+=v[i][0]
    x11+=v[i][0]**2
    x21+=v[i][0]
    x22=float(n)
    y1+=v[i][0]*v[i][1]
    y2+=v[i][1]
L=x11*x22-x12*x21
L1=y1*x22-y2*x12
L2=x11*y2-x21*y1
a=L1/L
b=L2/L
print(a)
print(b)
hRead.close()
hWrite.close()
