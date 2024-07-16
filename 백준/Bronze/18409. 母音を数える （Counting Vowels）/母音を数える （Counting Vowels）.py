len1 = int(input())
str1 = input()
count = 0

for i in str1:
	if i in "aeiou":
		count += 1

print(count)