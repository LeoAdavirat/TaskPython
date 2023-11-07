# Guess the number of lottery
import random
lottery = random.randint(1,100)
while True:
    guess = int(input("Guess your number: "))
    if guess == lottery:
        print("That's correct.")
        break
    elif guess > lottery:
        print("Your number is bigger.")
    else:
        print("Your number is lower.")