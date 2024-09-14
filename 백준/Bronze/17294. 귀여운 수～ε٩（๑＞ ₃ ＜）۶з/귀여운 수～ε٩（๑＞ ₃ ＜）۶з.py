def cute(n):
	if int(n) < 100:
		return True
	
	length = len(n)
	for i in range(1, length - 1):
		if int(n[i]) - int(n[i-1]) != int(n[i+1]) - int(n[i]):
			return False
	return True

n = input()
if cute(n):
	print("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!")
else:
	print("흥칫뿡!! <(￣ ﹌ ￣)>")