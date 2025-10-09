import json

def save(file , data):
    try:
        with open(file , "w") as j:
            json.dump(data , j)
    
    except PermissionError:
       print("you dont have permission to write file")
    except Exception as e:
       print(f"error : {e}")

def load(file):
    try:
        with open(file , "r") as j:
            data = json.load(j)
        return data
    
    except FileNotFoundError:
        print(f"Error: The file '{file}' was not found.")
        return None
    except json.JSONDecodeError:
        print(f"Error: The file '{file}' does not contain valid JSON.")
        return None
    except PermissionError:
        print(f"Error: You do not have permission to read the file '{file}'.")
        return None
    except Exception as e:
        print(f"An error occurred while loading the dictionary: {e}")
        return None
    
def max(data):
    try:
        if not data:
            raise ValueError("the disctionary is empty or invalid")
        
        maxAge = -1
        maxAgePerson = ""
        sameAgePeople = []

        for name , age in data.items():
            if age > maxAge:
                maxAge = age
                maxAgePerson = name
                sameAgePeople = [name]
            elif age == maxAge:
                sameAgePeople.append(name)

        print(f"person with max age :  {maxAgePerson  , maxAge}")

        if len(sameAgePeople) > 1:
            print(sameAgePeople)
        
    except ValueError as ve:
        print(f"Error: {ve}")
    except Exception as e:
        print(f"An error occurred while finding the maximum age person: {e}")

dicti = {
            'Ali': 23,
            'Saad': 24,
            'Salman': 15,
            'Shams': 25,
            'Sadiq': 46,
            'Hammad': 23
        }

save('ages.json' , dicti)
loaddict = load('ages.json')
max(loaddict)

