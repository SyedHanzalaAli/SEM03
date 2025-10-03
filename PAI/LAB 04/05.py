from datetime import date

class Vehicle:
    def __init__(self , make , model , rentalPrice):
        self.make = make
        self.model = model
        self.__rentalPrice = rentalPrice
        self.isAvailable = True

    def getRentalPrice(self):
        return self.__rentalPrice
    
    def checkAvailability(self):
        return self.isAvailable
    
    def rentVehicle(self):
        if self.isAvailable:
            self.isAvailable = False
            print(f"{self.make} {self.model} has been rented")
        else:
            print(f"{self.make} {self.model} is not available")

    def returnVehicle(self):
        self.isAvailable = True
        print(f"{self.make} {self.model} is available for rent")

    def calculateRentalCost(self , days):
        return self.__rentalPrice *days
    
    def displayDetails(self):
        status = "Available" if self.isAvailable else "Rented"
        print(f"Make : {self.make} , Model : {self.model} , Price/Day: {self.__rentalPrice} , Status : {status}")

class Car(Vehicle):
    def displayDetails(self):
        print("Car Details : ")
        super().displayDetails()

class SUV(Vehicle):
    def displayDetails(self):
        print("SUV Details : ")
        super().displayDetails()

class Truck(Vehicle):
    def displayDetails(self):
        print("Truck Details : ")
        super().displayDetails()

class Customer:
    def __init__(self , name , contactInfo):
        self.name = name
        self.__contactInfo = contactInfo
        self.rentalHistory = []

    def getContactInfo(self):
        return self.__contactInfo
    
    def addRental(self , reservation):
        self.rentalHistory.append(reservation)

    def displayRentalHistory