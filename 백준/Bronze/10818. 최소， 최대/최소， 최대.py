n = int(input())

lst = list(map(int, input().split()))

lst.sort()

print(lst[0], lst[n-1])