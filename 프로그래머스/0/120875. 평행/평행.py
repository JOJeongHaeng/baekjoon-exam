def solution(dots):
    check = [(0,1), (0,2), (0,3), (1,2), (1,3), (2,3)]
    count = 0
    for ch in check:
        i, j = ch
        num = [0, 1, 2, 3]
        num.remove(i)
        num.remove(j)
        k, l = num
        inc_1 = (dots[j][1]-dots[i][1])/(dots[j][0]-dots[i][0])
        inc_2 = (dots[l][1]-dots[k][1])/(dots[l][0]-dots[k][0])
        if inc_1 == inc_2:
            return 1
    return 0