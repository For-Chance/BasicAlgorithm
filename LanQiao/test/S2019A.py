sum = 0
ls = "0129"
for i in range(2019):
    for s in str(i + 1):
        if s in ls:
            sum += (i + 1) * (i + 1)
            break;
print(sum)