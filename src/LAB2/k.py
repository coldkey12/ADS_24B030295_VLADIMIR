from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    arr = input().split()
    freq = {}
    q = deque()
    res = []
    for ch in arr:
        freq[ch] = freq.get(ch, 0) + 1
        q.append(ch)
        while q and freq[q[0]] > 1:
            q.popleft()
        if q:
            res.append(q[0])
        else:
            res.append("-1")
    print(" ".join(res))