alist = []
for i in range(9):
  a = int(input())
  alist.append(a)
print(max(alist))
print(alist.index(max(alist))+1)