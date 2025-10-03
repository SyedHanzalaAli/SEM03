class Student:
    def __init__(self , studentID , name):
        self.studentID = studentID
        self.name = name

    def displayInfo(self):
        print(f"Student ID :{self.studentID} \nStudent Name :{self.name}")

class Marks(Student):
    def __init__(self, studentID, name , algo , ds , cal):
        super().__init__(studentID, name)
        self.algo = algo
        self.ds = ds
        self.cal = cal

    def displayMarks(self):
        print(f"Marks in algorithm :{self.algo} \nMarks in Data Sci :{self.ds}\nMarks in Calculus {self.cal}")

class Result(Marks):
    def __init__(self, studentID, name, algo, ds, cal):
        super().__init__(studentID, name, algo, ds, cal)

    def calculateResult(self):
        total = self.algo + self.cal + self.ds
        average = total / 3
        print(f"total marks {total} \naverage marks {average}\n")

s1 = Result(101 , "Hanzala" , 67 ,89, 100)

s1.displayInfo()
s1.displayMarks()
s1.calculateResult()
    
        