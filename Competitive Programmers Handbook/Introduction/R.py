import math

memo = {0: 0}
def pre():
    numDigits = 1
    last_pos = 0
    for numDigits in range(1, 21):
        last_pos += 9 * (10**(numDigits-1)) * numDigits
        memo[numDigits] = last_pos

def numDigits(query):
    for digit in range(1, 21):
        if memo[digit] >= query:
            return digit

def solve(query):
    digits = numDigits(query)
    num_start = (10 ** (digits-1))
    num_end = int(10 ** digits) - 1
    range_start = memo[digits-1] + 1
    range_end = memo[digits]

    _num_start = num_start
    _num_end = num_end
    _range_start = range_start
    _range_end = range_end
    mid = 0
    while True:
        mid = int((_num_start + _num_end) / 2)
        _range_mid = _range_start + ((mid - _num_start) * digits)
        if (query >= _range_mid):
            _num_start = mid
            _range_start = _range_mid
        else:
            _num_end = mid
        if (abs(query - _range_start) < 1000):
            break
    range_diff = (query - _range_start)
    diff = int(range_diff / digits)
    num = _num_start + diff
    pos = query - (_range_start + (diff * digits))
    num = str(num)
    return num[pos]


pre()
num_queries = int(input())

for i in range(num_queries):
    query = int(input())
    print(solve(query))
