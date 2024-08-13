n, x = map(int, input().split()) #x분 이내 도착해야 함

ans = -1
for i in range(n):
	s, t = map(int, input().split()) #정류장에서 s분 후 출발, 학교까지 t분 걸림

	if s + t <= x and s > ans:
		ans = s

print(ans)