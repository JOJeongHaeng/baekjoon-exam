num = int(input())
num_list = []

for i in range(num):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    dis = ((x1-x2)**2+(y1-y2)**2)**0.5
    
    if dis == 0:
        if r1 == r2:
            num_list.append(-1)    
        else:
            num_list.append(0)
        
    elif dis < r1 or dis < r2:
        if r1 - r2 == dis or r2 - r1 == dis:
            num_list.append(1)
        elif r1- r2 > dis or r2 - r1 > dis:
            num_list.append(0)
        else:
            num_list.append(2)
    else:
        if r1 + r2 == dis:
            num_list.append(1)
        elif r1 + r2 < dis:
            num_list.append(0)
        else:
            num_list.append(2)

for i in range(num):
    print(num_list[i])