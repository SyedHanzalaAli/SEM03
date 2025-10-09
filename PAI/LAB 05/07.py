def fix(word , replace):
    try:
        with open('replacement.txt') as f:
            c = f.read()

        c = c.replace(word , replace)

        print(c)
    
    except FileNotFoundError:
        print("Error: The file 'replacement_needed.txt' was not found.")
    except PermissionError:
        print("Error: You do not have permission to read/write the file.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

fix()
