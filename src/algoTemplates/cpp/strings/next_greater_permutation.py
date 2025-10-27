def next_permutation(w):
    # Write your code here
    s = [c for c in w]
    n = len(s)

    k = -1
    for i in range(n-1, -1, -1):
        if s[i] > s[i-1]:
            s[i:] = sorted(s[i:])
            j = i - 1

            for k in range(i, n):
                if s[j] < s[k]:
                    s[j], s[k] = s[k], s[j]
                    s = ''.join(s)
                    return s

    return 'no answer'
