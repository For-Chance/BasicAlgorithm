import math
cnt  = 0
num = -1
l = [4, 5, 6]
ls = "235678"
while cnt != 2020:
    num += 1
    flag = 0
    num_10 = num % 10
    if num_10 in l:
        continue
    nn = num * num
    for s in str(nn):
        if s in ls:
            flag = 1
            break;
    if flag == 1:
        continue
    else:
        cnt += 1
        print(nn)
        
    