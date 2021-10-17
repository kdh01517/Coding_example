def solution(s):
    answer = []
    s = s[2:-2]
    s = s.split("},{")
    s.sort(key = len)
    for i in s:
        li = i.split(",")
        for a in li:
            if int(a) not in answer:
                answer.append(int(a))
    return answer