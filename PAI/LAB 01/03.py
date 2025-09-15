num = input("enter 4 digit number : ")

swapped = num[3] + num[2] + num[1] + num[0]

encryptedDigits = ""
for digit in swapped:
    new = (int(digit)+7)%10
    encryptedDigits += str(new)

print(encryptedDigits)