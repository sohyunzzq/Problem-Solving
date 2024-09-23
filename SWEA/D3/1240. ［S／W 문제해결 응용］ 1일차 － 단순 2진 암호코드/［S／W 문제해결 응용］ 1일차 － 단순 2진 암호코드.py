def get_data():
	for line in lst:
		for i in range(m - 56 + 1):
			data = []
			for j in range(0, 57, 7):
				if line[i+j:i+j+7] not in code:
					break

				data.append(code[line[i+j:i+j+7]])
				if len(data) == 8:
					return data

def check():
	odd = 0
	even = 0

	for i in range(8):
		if i % 2 == 0: #홀수
			odd += data[i]
		else:
			even += data[i]

	if (odd * 3 + even) % 10 == 0:
		return odd + even
	else:
		return 0


code = {"0001101": 0, "0011001": 1, "0010011": 2, "0111101": 3, "0100011": 4, "0110001": 5, "0101111": 6, "0111011": 7, "0110111": 8, "0001011": 9}

t = int(input())
for case in range(1, t + 1):
	n, m = map(int, input().split())
	lst = []
	for i in range(n):
		lst.append(input())

	data = get_data()

	print("#{} {}".format(case, check()))