letters = input()
rot = int(input())
for i in range(len(letters)):
    print(letters[(i + rot) % len(letters)], end='')
print('\n', letters, sep='')
for i in range(len(letters)):
    print(letters[(i - rot) % len(letters)], end='')