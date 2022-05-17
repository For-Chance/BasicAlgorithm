input = 2021041820210418
z = []
i = 2;
while input != 1:
    while input % i == 0:
        z.append(i)
        input = int(input / i)
    i += 1
print(z)
