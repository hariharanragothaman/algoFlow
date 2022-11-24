import itertools

# zipping unequal lists
a = [1, 2, 3]
b = [4, 5]
c = list(itertools.zip_longest(a, b, fillvalue=0))
print(c)
