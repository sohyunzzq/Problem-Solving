n = int(input())
cnt = 0
for i in range(n):
    num = int(input())
    
    if num % 2 == 1:
        cnt += 1

print(cnt)