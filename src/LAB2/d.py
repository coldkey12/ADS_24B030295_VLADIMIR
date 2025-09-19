from collections import Counter

n = int(input())
arr = list(map(int, input().split()))

freq = Counter(arr)
max_freq = max(freq.values())

modes = [num for num, count in freq.items() if count == max_freq]

modes.sort(reverse=True)

print(' '.join(map(str, modes)))