class Employee:
    def __init__(self , name , salary):
        self.name = name
        self.salary = salary

    def calculateBonus(self):
        return 0
    
class Manager(Employee):
    def __init__(self, name, salary):
        super().__init__(name, salary)

    def calculateBonus(self):
        return self.salary*0.20
    
    def hire(self, employeeName):
        print(f"Manager {self.name} is hiring {employeeName}")

class Developer(Employee):
    def __init__(self, name, salary):
        super().__init__(name, salary)

    def calculateBonus(self):
        return self.salary * 0.10
    
    def writecode(self):
        print(f"Developer {self.name} is writing code")

class SeniorManager(Manager):
    def __init__(self, name, salary):
        super().__init__(name, salary)

    def calculateBonus(self):
        return self.salary * 0.30
    
m = Manager("Hanzala" , 1000000)
d = Developer("Ali" , 40000)
s = SeniorManager("zahid" , 120000)

print(m.calculateBonus())
print(d.calculateBonus())
print(s.calculateBonus())

m.hire("saad")
d.writecode()