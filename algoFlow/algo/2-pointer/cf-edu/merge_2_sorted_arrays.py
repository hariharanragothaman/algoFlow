def merge_sorted_array(A, B):
    """
    index of the transferred element in ans, will always be i+j
    """
    i = 0
    j = 0
    n, m = len(A), len(B)
    ans = [0] * (m+n)
    while i < n or j < m:
        if j == m or (i < n and A[i] < B[j]):
            ans[i+j] = A[i]
            i += 1
        else:
            ans[i+j] = B[j]
            j += 1

    print(*ans)
