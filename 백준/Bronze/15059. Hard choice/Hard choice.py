ca, ba, pa = map(int, input().split())
cr, br, pr = map(int, input().split())

total = 0

if ca < cr:
	total += cr - ca
if ba < br:
	total += br - ba
if pa < pr:
	total += pr - pa

print(total)