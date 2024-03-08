import math

class Shape(object):
    pass

class Rectangle(Shape):
    def __init__(self,l1 = 0,l2 = 0,l3 = 0) -> None:
        self.len1 = l1
        self.len2 = l2
        self.len3 = l3
    def getCircumference(self):
        return self.len1 + self.len2 + self.len3
    def getArea(self):
        p = (self.len1 + self.len2 + self.len3) / 2
        return math.sqrt(p * (p - self.len1) * (p - self.len2) * (p - self.len3))

class Circle(Shape):
    PI = 3.1415926
    def __init__(self,r) -> None:
        self.round = r
    def getCircumference(self):
        return 2 * Circle.PI * self.round
    def getArea(self):
        return Circle.PI * self.round * self.round

class Square(Rectangle):
    def __init__(self, l1 = 0, l2 = 0) -> None:
        super().__init__(l1, l2)
    def getCircumference(self):
        return (self.len1 + self.len2) * 2
    def getArea(self):
        return self.len1 * self.len2

rLengthList = input('input length of rectangle in one line : ').split(' ')
rLengthList = list(map(float,rLengthList))
cRound = float(input('input round of the circle : '))
sLengthList = input('input length of square in one line : ').split(' ')
sLengthList = list(map(float,sLengthList))

rect = Rectangle(rLengthList[0],rLengthList[1],rLengthList[2])
circle = Circle(cRound)
square = Square(sLengthList[0],sLengthList[1])

print('rect circumference :',rect.getCircumference(),', area :',rect.getArea())
print('circle circumference :',circle.getCircumference(),', circle :',circle.getArea())
print('square circumference :',square.getCircumference(),', square :',square.getArea())