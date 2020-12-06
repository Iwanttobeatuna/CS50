from cs50 import get_int

# Get height by using a while loop (height must be more than 0 or <=8)
while True:
    height = get_int("Height:")
    if height > 0 and height <= 8:
        break

for i in range(height):
   
    # From C code: building dots/space, relationship found: the spaces needed =  height - x -1
    for j in range(0, height - i - 1, +1):
        print(" ", end="")
    
    # From C code
    for y in range(0, i + 1, +1):
        print("#", end="")
    
    # print new line after finishing a line of " " and  "#"
    print()
