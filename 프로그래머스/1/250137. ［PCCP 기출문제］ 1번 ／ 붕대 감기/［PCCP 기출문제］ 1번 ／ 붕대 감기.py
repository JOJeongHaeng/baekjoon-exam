def solution(bandage, health, attacks):
    t, x, y = bandage[0], bandage[1], bandage[2]  
    l_a = attacks[-1][0]
    seq = -1
    now_h = health
    n_a = 0
    for i in range(l_a+1):
      if attacks[n_a][0] == i:
        seq = 0
        now_h -= attacks[n_a][1]
        n_a += 1
        if now_h <= 0:
          return -1
      else:
        seq += 1
        now_h += x
        if now_h > health:
          now_h = health
        if seq == t and now_h + y > health:
          now_h = health
          seq = 0
        elif seq == t and now_h + y <= health:
          now_h += y
          seq = 0
    return now_h