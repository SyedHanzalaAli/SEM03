def replace(file , word , rep):
    try:
     with open(file) as f:
        content = f.read()

     content = content.replace(word , rep)

     with open(file , "w") as f:
        f.write(content)
        
    except FileNotFoundError:
       print("file not found")
    except PermissionError:
       print("you dont have permission to open file")
    except Exception as e:
       print(f"error : {e}")

replace("file.txt")