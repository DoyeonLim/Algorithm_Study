n = int(input())
num_list = [int(input()) for i in range(n)]

for i in range(n):
    min = i
    for j in range(i+1, n):
        if num_list[min] > num_list[j]:
            min = j
    num_list[i], num_list[min] = num_list[min], num_list[i]

for i in num_list:
    print(i)