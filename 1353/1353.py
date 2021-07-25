s = int(input())
d = [[0 for i in range(101)] for j in range(10)]
for i in range(1, 10):
    d[1][i] = 1
d[0][1] = 1
for i in range(1, 9):
    for j in range(1, 82):
        for k in range(10):
            d[i + 1][j + k] += d[i][j]
ans = 0
for i in range(10):
    ans += d[i][s]
print(ans)