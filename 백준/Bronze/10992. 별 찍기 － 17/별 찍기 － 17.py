n = int(input())

for i in range(n-1):
    print(" " * (n - i - 1), end = "")
    print("*", end = "")
    if i == 0:
        print()
        continue
    print(" " * (2 * i - 1), end = "")
    print("*")
print("*" * (2 * n- 1))