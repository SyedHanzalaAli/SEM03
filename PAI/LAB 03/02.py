def checkLetter(word):

    if not word:
        return "empty"
    
    last = word[-1].lower()
    vowels = "aieou"

    if last.isalpha():
        if last in vowels:
            return "Vowel"
        else:
            return "Consonant"
    else:
        return "not a letter"
    
print(checkLetter("hanzala"))
