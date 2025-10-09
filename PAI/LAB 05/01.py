def count(file):
    try:
         
     with open(file) as f:
        content = f.read()

        char = len(content)
        words = len(content.split())

        print(f"total characters {char}")
        print(f"total words {words}")
    
    except FileNotFoundError:
       print("file not found")
    except PermissionError:
       print("you dont have permission to open file")
    except Exception as e:
       print(f"error : {e}")

file = "file.txt"
count(file)


