c = [1,1,1]
d = [3,2,0]
b = [0,3,2]
r = [7,11,7]
n = 3
de = [0]*n
gam = [0]*n
x = [0]*n
for i in range(3):
    if (i == 0):
        de[0] = d[0]/(-c[0])
        gam[0] = r[0]/c[0]
    else:
        de[i] = -d[i]/(c[i] + b[i]*de[i-1])
        gam[i] = (r[i] - b[i]*gam[i-1])/(c[i]+b[i]*de[i-1])
for i in range(n,0,-1):
    k = i - 1
    if(k == n-1):
        x[n-1] = gam[n-1]
    else:
        x[k] = de[k]*x[k+1]+gam[k]
print (x)