def fizzbuzz(num):
    if num % 3 == 0 and num % 5 == 0:
        print("FizzBuzz")
    elif num % 3 == 0:
        print("Fizz")
    elif num % 5 == 0:
        print("Buzz")
    else:
        print(num)

str1 = input()
str2 = input()
str3 = input()

if str3[0].isdigit():
    fizzbuzz(int(str3) + 1)
elif str2[0].isdigit():
    fizzbuzz(int(str2) + 2)
else:
    fizzbuzz(int(str1) + 3)