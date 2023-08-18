def counting_sort(A):
    """
    Current limitation works only for 0 to max(A)
    Needs update for negative numbers
    """
    mx = max(A)
    n = len(A)
    cnt = [0] * (mx+1)
    output = [0] * n

    # Building the count array
    for c in A:
        cnt[c] += 1
    # print("The cnt is:", cnt)

    num_items_before = 0
    for i, counts in enumerate(cnt):
        cnt[i] = num_items_before
        num_items_before += counts
    # print("The cnt is:", cnt)

    for c in A:
        output[cnt[c]] = c
        cnt[c] += 1
        # print(f"The output is:", output)
    return output


if __name__ == '__main__':
    A = [7, 7, 6, 1, 1, 2, 3, 4, 7]
    result = counting_sort(A)
    print(result)
