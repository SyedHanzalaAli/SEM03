def getData():

    name = input("enter name: ")
    nic = input("enter nic: ")
    age = input("enter age: ")
    salary = input("enter salary: ")

    bio = f"Name : {name}\nCNIC : {nic}\nAge : {age}\nSalary : {salary}\n"

    return bio

def save(file , bio):
    try:
        with open(file , "w") as f:
            f.write(bio)

    except PermissionError:
       print("you dont have permission to write file")
    except Exception as e:
       print(f"error : {e}")

def append(file , contact):
    try:
        with open(file , "a") as f:
            f.write(contact)

    except PermissionError:
       print("you dont have permission to write file")
    except Exception as e:
       print(f"error : {e}")

def reaD(file):
    try:
        with open(file) as f:
            c = f.read()
            print(c)
    
    except FileNotFoundError:
        print(f"Error: The file '{file}' was not found.")
    except PermissionError:
       print("you dont have permission to write file")
    except Exception as e:
       print(f"error : {e}")

save("emp.txt" , getData())
contact = 203047
append("emp.txt" , contact)
reaD("emp.txt")
