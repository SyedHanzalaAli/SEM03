list1 = input("enter elements of list 1 separated by space: ").split()
list2 = input("enter elements of list 2 separated by space: ").split()

if len(list1) != len(list2):
    print("both lists must have the same number of elements")
else:
    myDict = {}
    for i in range(len(list1)):
        myDict[list1[i]] = list2[i]

    print("Dictionary : " , myDict)

    with open ("output.txt" , "w") as f:
        for key in myDict:
            f.write(key + ":" + myDict[key] + "\n")

