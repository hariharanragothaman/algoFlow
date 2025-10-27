from collections import defaultdict, deque

def input_as_array():
    return list(map(int, input().split()))

def main():
    n, m = input_as_array()
    g = defaultdict(list)

    if m != n-1:
        print("No")
        return

    for _ in range(m):
        u, v = input_as_array()
        g[u].append(v)
        g[v].append(u)


    # Checking if there are no cycles.
    visited = [0] * (n+1)
    visited[1] = 1
    q = deque()
    q.append((1, -1))
    while q:
        node, parent = q.popleft()
        for child in g[node]:
            if not visited[child]:
                visited[child] = True
                q.append((child, node))
            elif child != parent:
                print("No")
                return

    # Checking if the graph is connected.
    for i in range(1, n+1):
        if not visited[i]:
            print("No")
            return

    print("Yes")
