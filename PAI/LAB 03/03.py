def employee(name, sal=10000):
    tax = 0.02 * sal
    net = sal - tax
    print(f"Employee: {name}, Salary after tax: {net:.2f}")


employee("Hanzala", 20000)
employee("zahid")
