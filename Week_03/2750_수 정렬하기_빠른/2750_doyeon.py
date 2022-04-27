n = int(input())
num_list = [int(input()) for i in range(n)]

def quick_sorting(num_list):
    if len(num_list) <= 1:
        return num_list
    pivot = num_list[0]
    tail = num_list[1:]

    left = [x for x in tail if x <= pivot]
    right = [x for x in tail if x > pivot]

    return quick_sorting(left) + [pivot] + quick_sorting(right)

for i in quick_sorting(num_list):
    print(i)