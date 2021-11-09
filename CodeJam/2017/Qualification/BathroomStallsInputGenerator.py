import random
import math

start = pow(10, 3)
end = pow(10, 6)
numTest = 1000

with open('BathroomStallsInput.txt', 'w') as f:
    f.write(f'{numTest}\n')
    for i in range(numTest):
        N = pow(10, 18)
        K = random.randint(start, end)
        f.write(f"{N} {K}\n")
