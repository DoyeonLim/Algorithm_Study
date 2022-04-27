n = int(input())
num_list = [int(input()) for i in range(n)]

for i in range(1, n):
    for j in range(i, 0, -1):
        if num_list[j] < num_list[j-1]:
            num_list[j], num_list[j-1] = num_list[j-1], num_list[j]
        else:
            break

for i in num_list:
    print(i)