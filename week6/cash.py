from cs50 import get_float

# ask dollars owed
while True:
    dollars = get_float("Change owed:")
    if dollars > 0:
        break

# changing dollars to cent and rounding it
cents = round(dollars*100)
# initialize coin = 0
coins = 0

# start calculation (From C code)
while (cents >= 25):
    cents = cents - 25
    coins += 1

while (cents >= 10 and cents < 25):
    cents = cents - 10
    coins += 1

while (cents >= 5 and cents < 10):
    cents = cents - 5
    coins += 1

while (cents >= 1 and cents < 5):
    cents = cents - 1
    coins += 1

# print out result of calculation
print(f"Coins needed:{coins}")
