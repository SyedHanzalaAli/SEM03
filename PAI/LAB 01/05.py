studentRecords = {}

while True:
    print("\nStudent Management System")
    print("1. Add Student")
    print("2. Update Marks")
    print("3. Delete Student")
    print("4. Find Topper")
    print("5. Show All Student")
    print("6. Exit")

    choice = input("Enter choice (1-6): ")

    if choice == '1':
        name = input("enter student name : ")
        marks = int(input("enter student marks : "))
        studentRecords[name] = marks
        print("student added successfully")

    elif choice == '2':
        name = input("enter student name to update : ")
        if name in studentRecords:
           marks = int(input("enter new marks : "))
           studentRecords[name] = marks
           print("student marks updated successfully")
        else:
            print("student not found")

    elif choice == '3':
        name = input("enter student name to delete : ")
        if name in studentRecords:
           del studentRecords[name] 
           print("student deleted successfully")
        else:
            print("student not found")

    elif choice == '4':
        if studentRecords:
           topper = max(studentRecords , key=studentRecords.get) 
           print("Topper is :")
           print(topper)
        else:
            print("no student found")

    elif choice == '5':
        if studentRecords:
           for name, marks in studentRecords.items():
               print(name,"-",marks)
        else:
            print("no student found")

    elif choice == '6':
        print("exiting system")
        break

    else :
        print("invalid choice")

        
    


    