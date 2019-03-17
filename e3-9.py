from functools import reduce

print(reduce(lambda x, y: x if (x > y) else y, list(map(int, input('Please input numbers: ').split(' ')))))
