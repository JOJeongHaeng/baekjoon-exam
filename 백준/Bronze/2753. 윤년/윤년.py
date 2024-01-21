input1 = int(input())
if input1%400 == 0:
    print("1")
elif input1%4 == 0 and input1%100 != 0:
    print("1")
else:
    print("0")