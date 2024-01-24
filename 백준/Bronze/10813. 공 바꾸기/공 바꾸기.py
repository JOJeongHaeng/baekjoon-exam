N, M = map(int,input().split())
n_list=[]
store = 0
for i in range(N):
  n_list.append(i+1)
for n in range(M):
  a, b = map(int, input().split())
  store = n_list[a-1]
  n_list[a-1] = n_list[b-1]
  n_list[b-1] = store
for i in range(N):
  print(n_list[i], end=" ")