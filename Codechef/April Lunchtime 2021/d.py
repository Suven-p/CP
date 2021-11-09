N = int(input(""))
array = input("").split()
array = [int(i) for i in array]
Q = int(input(""))
ans = sum(array)
c = (pow(10, 9) + 7)
for i in range(Q):
    # temp = input("")
    ans *= 2
    print(ans%c)
