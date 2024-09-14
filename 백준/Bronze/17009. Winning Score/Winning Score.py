apples = 0
bananas = 0

for i in range(3):
	apples += int(input()) * (3-i)

for i in range(3):
	bananas += int(input()) * (3-i)

if apples > bananas:
	print("A")
elif apples < bananas:
	print("B")
else:
	print("T")