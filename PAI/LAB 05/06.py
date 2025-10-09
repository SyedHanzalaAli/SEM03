def question():
    try:
        sentence = input("enter : ")

        if sentence.endswith('?'):
            with open("questions.txt" , 'a') as f:
                f.write(sentence+"\n")
        else:
            print("not a question")

    except PermissionError:
        print("Error: You do not have permission to write to the file 'questions.txt'.")
    except Exception as e:
        print(f"An error occurred: {e}")

question()