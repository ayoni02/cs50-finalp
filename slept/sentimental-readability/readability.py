import re

user = input('Text: ').strip()
letters = [i for i in user if i.isalpha()] #list comprehension
words = user.split(' ')
sentences = re.split(r'[.!?]+', user)

Le = len(letters)
Wo = len(words)
Se = len(sentences) - 1

L = Le / Wo * 100
S = Se / Wo * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print('Before Grade 1')
elif index >= 16:
    print('Grade 16+')
else:
    print(f'Grade {index}')