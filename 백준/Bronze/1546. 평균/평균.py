n = int(input())
lst = list(map(int, input().split()))

maxi = max(lst)
sum1 = 0

for i in range(n):
	sum1 += lst[i] / maxi * 100

print(sum1 / n)