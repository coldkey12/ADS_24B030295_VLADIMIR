n = int(input())
arr = list(map(int, input().split()))
x = int(input())

min_diff = abs(arr[0] - x)
index = 0

for i in range(1, n):
    diff = abs(arr[i] - x)
    if diff < min_diff:
        min_diff = diff
        index = i

print(index)