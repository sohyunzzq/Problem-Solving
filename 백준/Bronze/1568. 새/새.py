n = int(input())
k = 0
time = 0
bird = 0

while True:
	time += 1
	k += 1
	if bird + k < n:
		bird += k
	elif bird + k == n:
		break
	else:
		time -= 1
		k = 0

print(time)