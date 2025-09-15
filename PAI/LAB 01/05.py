import random

name = input("enter name ")
year = input("enter birth year ")

first3 = name[:3]
last2 = year[-2:]

symbols = "@#%&*"
asciival = ord(name[0])
symbol = symbols[asciival % len(symbols)]

password = first3 + last2 + symbol

print("generated password : " , password)