villages = int(input())
vL = []
for i in range(villages):
    vL.append(int(input()))
sVL = sorted(vL)
smallest = ((sVL[1] - sVL[0])/2) + ((sVL[2]-sVL[1])/2)
for x in range(len(sVL)):
    if x == 0 or x == len(sVL)-1 or x == 1:
        continue
    else:
        if (((sVL[x]-sVL[x-1])/2) + ((sVL[x+1]-sVL[x])/2)) < smallest:
            smallest = (((sVL[x]-sVL[x-1])/2) + (sVL[x+1]-sVL[x])/2)
print(str(smallest))