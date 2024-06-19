"""
You are given two arrays, sorted in non-decreasing order.
For each element of the second array,
find the number of elements in the first array strictly less than it.
"""


def number_of_smaller(A, B):
    n, m = len(A), len(B)
    ans = [0] * m
    i = 0
    for j in range(m):
        while i < n and A[i] < B[j]:
            i += 1
        ans[j] = i
    print(*ans)
