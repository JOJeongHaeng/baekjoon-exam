N, X = map(int, input().split())
a_list = input().split()
out = ""
for i in range(N):
  if int(a_list[i]) < X:
    out= out+a_list[i]+" "
print(out)