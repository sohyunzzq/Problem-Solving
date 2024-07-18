dict1 = {"Algorithm": "204", "DataAnalysis": "207", "ArtificialIntelligence": "302", "CyberSecurity": "B101", "Network": "303", "Startup": "501", "TestStrategy": "105"}

n = int(input())
for i in range(n):
	str1 = input()
	for j in dict1:
		if str1 == j:
			print(dict1[j])
			break