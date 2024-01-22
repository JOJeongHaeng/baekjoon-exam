N = int(input())
a_list= input().split()
v = int(input())
tatal = 0
for i in range(N):
  if v == int(a_list[i]):
    tatal+=1
print(tatal)