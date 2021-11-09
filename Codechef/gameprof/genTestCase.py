import random

n = random.randint(1, 1000)
upperLimit = pow(10, 9)
k = random.randint(1, upperLimit)

output = f"{n} {k}\n"
for _ in range(n):
    a, b = random.randint(0, 1000), random.randint(0, 1000)
    lower = min(a, b)
    higher = max(a, b)
    value = random.randint(1, 1000)
    output += f"{lower} {higher} {value}\n"

with open('testInput.txt', 'w') as f:
    f.write(output)
