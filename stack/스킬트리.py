def solution(skill, skill_trees):
    answer = 0
    
    for s in skill_trees:
        check = list(skill)
        for p in s:
            if p in skill:
                if p != check.pop(0):
                    break
        else:
            answer += 1
        
    return answer