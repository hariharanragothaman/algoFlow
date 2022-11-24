import itertools
import operator

# To consecutively multiply elements
arr = [1, 2, 3, 4, 5, 6]
op = list(itertools.accumulate(arr, operator.mul))
print(op)
