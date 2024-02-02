def solution(edges):
    m_ax = max(map(max, edges))
    i_n = []
    o_ut = []
    vertices = 0
    donut = 0
    straight = 0
    eight = 0
    total = 0
    for _ in range(m_ax+1):
        i_n.append(0)
        o_ut.append(0)
    for i in edges:
        o_ut[i[0]] += 1
        i_n[i[1]] += 1
    for j in range(1, len(i_n)):
        if o_ut[j] == 0:
            straight += 1        
        elif i_n[j] == 0 and o_ut[j] >= 2:
            vertices = j
            total = o_ut[j]
        elif i_n[j] > 0 and o_ut[j] == 2:
            eight += 1
    donut = total - straight - eight
    return [vertices, donut, straight, eight]