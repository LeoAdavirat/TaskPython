a = int(input("Please enter a: "))
b = int(input("please enter b: "))
while True:
    if a-b>0:
        a, b= b, a-b
    else:
        break
print(a)