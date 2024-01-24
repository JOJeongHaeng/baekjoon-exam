n_list = []
for i in range(30):
  n_list.append(i+1)
for _ in range(28):
  a = int(input())
  n_list.remove(a)
for i in n_list:
  print(i)