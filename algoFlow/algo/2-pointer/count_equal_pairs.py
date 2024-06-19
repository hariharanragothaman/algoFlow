from collections import Counter


def count_equal_pairs(A, B):
    n, m = len(A), len(B)
    ctr = Counter(A)
    ans = 0
    for j in range(m):
        ans += ctr.get(B[j], 0)
    print(ans)
