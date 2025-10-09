def create(l1 , l2):

    if len(l1) != len(l2):
        raise ValueError("number of elements not equal")
    
    result = {}

    for i in range(len(l1)):
        result[l1[i]] = l2[i]

    return result

def save(file , data):
    try:
        with open(file , "w") as f:
            for key , value in data.items():
                f.write(f"{key} : {value}\n")

    except PermissionError:
       print("you dont have permission to writefile")
    except Exception as e:
       print(f"error : {e}")

list1 = [1 ,2 , 3]
list2 = ["hanzala" , "ali" , "zahid"]

save("file.txt" , create(list1 , list2))