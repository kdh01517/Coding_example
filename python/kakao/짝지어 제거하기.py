def solution(s):
    stack = []
    for i in s[:]:
        if not stack or stack[-1] != i:
            stack.append(i)
        elif stack[-1] == i:
            stack.pop()
    if len(stack) != 0:
        return 0
    return 1