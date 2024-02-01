def solution(data, ext, val_ext, sort_by):
    answer = []
    X = 0
    for i in range(len(data)):
        if ext == "code":
            X = data[i][0] 
        elif ext == "date":
            X = data[i][1]
        elif ext == "maximum":
            X = data[i][2]
        elif ext == "remain":
            X = data[i][3]
        if X <= val_ext:
            answer.append(data[i])
    if sort_by == "code":
        answer.sort(key=lambda x:x[0])
    elif sort_by == "date":
        answer.sort(key=lambda x:x[1])
    elif sort_by == "maximum":
        answer.sort(key=lambda x:x[2])
    elif sort_by == "remain":
        answer.sort(key=lambda x:x[3])
    return answer