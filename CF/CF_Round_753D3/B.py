totalTests = int(input())
for i in range(totalTests):
    line = input().split()
    x = int(line[0])
    n = int(line[1])
    if n == 0:
        print(x)
        continue
    temp = int(n / 4)
    difference = int((n * (n + 1)) / 2)
    difference -= 2 * ((4*temp) + 1) * (temp + 1)
    ans = x
    correction = 0
    if n % 4 == 0:
        correction = (4 * temp) + 1
    if x % 2 == 0:
        ans += difference
        ans += correction
    else:
        ans -= difference
        ans += correction
    print(ans)


# int totalTests=1;
#     cin >> totalTests;

#     for (int numTest = 1; numTest <= totalTests; numTest++) {
#         ll x, n;
#         cin >> x >> n;
#         ll temp = n / 4;
#         unsigned long long difference = ((n*(n + 1)) / 2);
#         difference -= 2 * (4*temp + 1) * (temp + 1);
#         ll ans = x;
#         ll correction = 0;
#         if (n % 4 == 0) {
#             correction = (4 * temp) + 1;
#         }
#         if (x % 2 == 0) {
#             ans += difference;
#             ans += correction;
#         }
#         else {
#             ans -= difference;
#             ans -= correction;
#         }
#         cout << ans << "\n";
