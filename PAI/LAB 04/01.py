class Vehicle:
    def __init__(self , seatingCapacity):
        self.seatingCapacity = seatingCapacity

    def fare(self):
        return self.seatingCapacity*100

class Bus(Vehicle):
    def fare(self):
        baseFare = super().fare()
        maintainence = baseFare * 0.10
        return baseFare + maintainence

v1 = Vehicle(50)
print("Vehicle fare : " , v1.fare())

b1 = Bus(50)

print("Bus fare : " , b1.fare())
