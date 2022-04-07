from sys import stdin, stdout

n = stdin.readline()
n_list = sorted(map(int, stdin.readline().split()))
m = stdin.readline()
m_list = map(int, stdin.readline().split())

def binary_search(array, target, start, end):
    if start > end:
        return 0
    mid = (start+end)//2
    if array[mid] == target:
        return 1
    elif array[mid]>target:
        return binary_search(array,target,start,mid-1)
    else:
        return binary_search(array,target,mid+1,end)

for target in m_list:
    start = 0
    end = len(n_list)-1
    print(binary_search(n_list,target,start,end))
