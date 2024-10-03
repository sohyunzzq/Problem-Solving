year = []
a = "ABCDEFGHIJKL"
d = "0123456789"
a_index, d_index = 0, 0

while len(year) != 60:
    tmp = str(a[a_index] + d[d_index])
    year.append(tmp)
    a_index += 1
    if a_index == 12:
        a_index = 0
    d_index += 1
    if d_index == 10:
        d_index = 0

n = int(input())
print(year[n % 60 - 4])