integer = int(input("Type a number: "))
if integer % 2 == 0:
    print("even")
elif integer % 2 != 0:
    print("odd")


if 10 > 20:
    print("10>20")
elif 10<30:
    print("10>30")
    if 10<200:
        print("10<200")
else:
    raise ValueError
