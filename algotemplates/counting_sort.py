def counting_sort(A):
    mx = max(A)
    n = len(A)
    cnt = [0] * (mx+1)
    output = [0] * (mx+1)

    # Building the count array
    for c in A:
        cnt[c] += 1
    print("The cnt is:", cnt)

    num_items_before = 0
    for i, counts in enumerate(cnt):
        cnt[i] = num_items_before
        num_items_before += counts
    print("The cnt is:", cnt)

    for c in A:
        output[cnt[c]] = c
        cnt[c] += 1
    return output


if __name__ == '__main__':
    A = [1, 4, 1, 2, 7, 5, 2]
    print(A)
    result = counting_sort(A)
    print(result)
