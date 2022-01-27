n = int(input())
twoD = []
ans = []
for i in range(n):
    twoD.append([int(x) for x in input().split()])
x = twoD.index(min(twoD))
y = twoD[x].index(min(min(twoD)))
if x == n - 1:
  if y == 0:
    for y in range(n):
      ans.append([twoD[x][y] for x in range(n-1,-1,-1)])
  else:
    for x in range(n-1,-1,-1):
      ans.append([twoD[x][y] for y in range(n-1,-1,-1)])
else:
  if y == 0:
    ans = twoD
  else:
    for y in range(n-1,-1,-1):
      ans.append([twoD[x][y] for x in range(n)])
for i in ans:
  print(' '.join([str(x) for x in i]))