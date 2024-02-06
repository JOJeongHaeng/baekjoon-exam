def solution(players, callings):
    pdic = {}
    for j in range(len(players)):
     pdic[players[j]] = j
    for i in callings:
        pdic[i] -= 1
        pdic[players[pdic[i]]] += 1
        players[pdic[i]], players[pdic[i]+1] = players[pdic[i]+1], players[pdic[i]]
    pdic = dict(sorted(pdic.items(), key=lambda x: x[1]))
    return list(pdic.keys())