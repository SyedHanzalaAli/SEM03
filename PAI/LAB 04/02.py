from abc import ABC , abstractmethod

class Shape(ABC):
    def area(self):
        pass

class Rectangle(Shape):
    def __init__(self, length , width):
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

class Triangle(Shape):
    def __init__(self, base , height):
        self.base = base
        self.height = height

    def area(self):
        return self.base * self.height * 0.5

class Square(Shape):
    def __init__(self, side):
        self.side = side
     
    def area(self):
        return self.side * self.side

rect = Rectangle(10,5)
tri = Triangle(6,4)
sq = Square(7)

print(rect.area())
print(tri.area())
print(sq.area())
