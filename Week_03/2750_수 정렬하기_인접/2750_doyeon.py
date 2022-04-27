n = int(input())
num_list = [int(input()) for i in range(n)]

def bubble_sorting(num_list):
    for i in range(n-1, -1, -1):
        for j in range(0, i):
            if num_list[j] > num_list[j+1]:
                num_list[j], num_list[j+1] = num_list[j+1], num_list[j]
    return num_list

for i in bubble_sorting(num_list):
    print(i)