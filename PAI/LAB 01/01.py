def checkPassword(passwordInput):
    charCount = 0
    for char in passwordInput:
        charCount += 1
    if charCount < 8:
        return "Password should be at least 8 characters long"

    hasLetter = False
    hasDigit = False
    hasSpecialChar = False
    specialChars = ["@", "#", "$", "%"]

    for char in passwordInput:
        if 'a' <= char <= 'z' or 'A' <= char <= 'Z':
            hasLetter = True
        elif '0' <= char <= '9':
            hasDigit = True
        elif char in specialChars:
            hasSpecialChar = True

    if hasLetter and hasDigit and hasSpecialChar:
        return "Password is valid"
    else:
        return "Password invalid"

userPassword = input("Enter password: ")
print(checkPassword(userPassword))
