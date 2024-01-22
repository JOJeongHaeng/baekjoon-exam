N = int(input())
a_list = list(map(int, input().split()))
min = max = a_list[0]
for i in a_list:
  if i < min:
    min = i
  if i > max:
    max = i
print(min, max)