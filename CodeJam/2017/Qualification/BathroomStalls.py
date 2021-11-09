import math
import heapq

def solve(N, K):
    heap = []
    set_ = set()
    map = {}
    map[N] = 1
    processed = 0
    first = 0
    second = 0
    heapq.heapify(heap)
    heapq.heappush(heap, -1 * N)
    set_.add(N)
    while True:
        largest = -1 * heapq.heappop(heap)
        count = map[largest]
        first = (largest-1)//2
        second = (largest-1) - first
        processed += count
        if processed >= K:
            break
        if first not in set_:
            heapq.heappush(heap, -1 * first)
            set_.add(first)
        if second not in set_:
            heapq.heappush(heap, -1 * second)
            set_.add(second)
        map[first] = map.get(first, 0) + count
        map[second] = map.get(second, 0) + count
        map[largest] = 0
    return (first, second)

numTests = int(input())
for numTest in range(numTests):
    inp = input()
    numbers = inp.split()
    N = int(numbers[0])
    K = int(numbers[1])
    num0, num1 = solve(N, K)
    print(f'Case #{numTest+1}: {max(num0, num1)} {min(num0, num1)}')