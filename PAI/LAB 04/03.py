class Account:
    def __init__(self):
        self.__accountNo = None
        self.__accountBal = None
        self.__securityCode = None

    def setData(self, no , bal , cod):
        self.__accountNo = no
        self.__accountBal = bal
        self.__securityCode = cod

    def displayData(self):
        print(f"Account Number :{self.__accountNo} \nAccount Balance :{self.__accountBal} \nSecurity Code :{self.__securityCode} \n ")


a1 = Account()
a1.setData(12345 , 500000.75 , 9875)
a1.displayData()