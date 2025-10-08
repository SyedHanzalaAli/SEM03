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
        return self.__rentalPrice * days
    
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

class RentalReservation:
    def __init__(self, vehicle, customer, start_date, end_date):
        self.vehicle = vehicle
        self.customer = customer
        self.start_date = start_date
        self.end_date = end_date
        self.total_cost = self.vehicle.calculateRentalCost((self.end_date - self.start_date).days)
        self.customer.addRental(self)

    def displayReservationDetails(self):
        print(f"Reservation Details for {self.customer.name}:")
        self.vehicle.displayDetails()
        print(f"Rental Period: {self.start_date} to {self.end_date}")
        print(f"Total Cost: ${self.total_cost}")
        print(f"Customer Contact Info: {self.customer.getContactInfo()}")
        print("-" * 50)

class Customer:
    def __init__(self , name , contactInfo):
        self.name = name
        self.__contactInfo = contactInfo
        self.rentalHistory = []

    def getContactInfo(self):
        return self.__contactInfo
    
    def addRental(self , reservation):
        self.rentalHistory.append(reservation)

    def displayRentalHistory(self):
        print(f"Rental History for {self.name}:")
        if self.rentalHistory:
            for rental in self.rentalHistory:
                rental.displayReservationDetails()
        else:
            print("No rental history found.")
        print("-" * 50)



car1 = Car("Toyota", "Camry", 50)
suv1 = SUV("Ford", "Explorer", 75)
truck1 = Truck("Ram", "1500", 100)

customer1 = Customer("John Doe", "john.doe@example.com")

car1.rentVehicle()
reservation1 = RentalReservation(car1, customer1, date(2025, 10, 1), date(2025, 10, 7))

customer1.displayRentalHistory()

car1.returnVehicle()

car1.displayDetails()
