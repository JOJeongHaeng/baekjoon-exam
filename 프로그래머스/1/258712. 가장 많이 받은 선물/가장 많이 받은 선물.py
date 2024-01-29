def solution(friends, gifts):
    answer = 0
    gift = [[0 for j in range(len(friends))] for i in range(len(friends))]
    give = [0 for j in range(len(friends))]
    recieve = [0 for j in range(len(friends))]
    gap = [0 for j in range(len(friends))]
    next_year = [0 for j in range(len(friends))]
    for i in gifts:
      A,B = i.split()
      gift[friends.index(A)][friends.index(B)]+=1
    for i in range(len(friends)):
      give[i] = sum(gift[i])
      for j in range(len(friends)):
        recieve[i] += gift[j][i]
      gap[i] = give[i] - recieve[i]
    for i in range(len(friends)):
      for j in range(len(friends)):
        if i != j and i < j:
          if gift[i][j] > gift[j][i]:
            next_year[i]+=1
          elif gift[i][j] < gift[j][i]:
            next_year[j]+=1
          else:
            if gap[i]>gap[j]:
              next_year[i]+=1
            elif gap[i]<gap[j]:
              next_year[j]+=1
    return max(next_year)