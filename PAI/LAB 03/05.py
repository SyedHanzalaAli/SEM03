def palindrome(text):
    text = text.lower()
    return text == text[::-1]

print(palindrome("madam"))
print(palindrome("hello"))
print(palindrome("race car"))