N, M = map(int, input().split())
n_l = []
for i in range(N):
  n_l.append(i+1)
for _ in range(M):
  a, b = map(int, input().split())
  temp = n_l[a-1:b]
  temp.reverse()
  n_l[a-1:b] = temp
print(*n_l)