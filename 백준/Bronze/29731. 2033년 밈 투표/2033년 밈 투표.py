lst = ["Never gonna give you up", 
"Never gonna let you down", 
"Never gonna run around and desert you", 
"Never gonna make you cry", 
"Never gonna say goodbye", 
"Never gonna tell a lie and hurt you", 
"Never gonna stop"]

result = "No"
n = int(input())
for i in range(n):
	str1 = input()
	if str1 not in lst:
		result = "Yes"

print(result)