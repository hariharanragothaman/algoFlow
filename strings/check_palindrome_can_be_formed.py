from collections import Counter


def check_if_palindrome_can_be_formed(s):
    return sum(v % 2 for k, v in Counter(s).items()) <= 1
