numTests = int(input())
memo = dict()
bananas = []

def solve(numBanana, position):
    if position >= len(bananas):
        return 10**9
    if numBanana == 0:
        return 0
    stored = memo.get({numBanana, position}, None)
    if stored is not None:
        return memo
    ans1 = solve(numBanana - bananas[position], position + 2) + 1
    ans2 = solve(numBanana, position + 1)
    memo[{numBanana, position}] = min(ans1, ans2)
    return memo[{numBanana, position}]


for i in range(numTests):
    temp = input()
    N, K = [int(j) for j in temp.split()]
    temp = input()
    bananas = [int(j) for j in temp.split()]
    memo = dict()
    print(f"Case #{i}: {solve(K, 0)}")


