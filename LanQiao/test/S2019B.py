a = 1
b = 1
c = 1
res = 0
i = 3
while i != 20190324:
    res = ( a + b + c ) % 10000
    a = b
    b = c
    c = res
    i += 1
print(res)