dp = [0, 1, 2]

def tiling(num):
	if num <= 2:
		return num

	if num-2 > len(dp) - 1:
		dp.append(tiling(num-2))

	if num-1 > len(dp) - 1:
		dp.append(tiling(num-1))
	
	return dp[num-1] + dp[num-2]

n = int(input())

ans = tiling(n)
print(ans % 10007)