from cs50 import get_string

# getting text from users
text = get_string("Text:")

# nitializing variables in term of float
letters = 0.0
words = 0.0
sentences = 0.0
spaces = 0.0

# calculating number of letters, spaces, words and sentences, idea derived from C code, which is from C's readability walkthrough
for i in range(len(text)):
    if (text[i].isalpha()) == True:
        letters += 1
    if (text[i].isspace()) == True:
        spaces += 1
        words = spaces + 1
    if text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentences += 1

# calculating Coleman-Liau index

# converting letters and words into L and S
L = (100*letters)/words
S = (100*sentences)/words

# applying formula
index = 0.0588 * L - 0.296 * S - 15.8

# generating result
if (index >= 16):
    print("Grade 16+")
    print()
elif (index <= 1):
    print("Before Grade 1")
    print()
else:
    print(f"Grade {round(index)}")
