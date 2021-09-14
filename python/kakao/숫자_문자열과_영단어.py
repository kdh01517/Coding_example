def solution(s):
    answer = ''
    dic = {
        'zero' : '0', 'one' : '1', 'two' : '2', 'three' : '3',
        'four' : '4', 'five' : '5', 'six' : '6', 'seven' : '7',
        'eight' : '8', 'nine' : '9'
    }

    tmp = ''
    for c in s:
        if c in '0123456789':
            answer += c
        else:
            tmp += c
        
        if tmp in dic.keys():
            answer += dic[tmp]
            tmp = ''

    return int(answer)