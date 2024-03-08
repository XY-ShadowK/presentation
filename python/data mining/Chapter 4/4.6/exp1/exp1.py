class Complex:
    def __init__(self,re,im) -> None:
        self.realQuantity = re
        self.imaginaryQuantity = im
    def __str__(self) -> str:
        return f'{self.realQuantity}+{self.imaginaryQuantity}i' if self.imaginaryQuantity >= 0 else f'{self.realQuantity}{self.imaginaryQuantity}i'
    def add(self,cAdd):
        self.realQuantity += cAdd.realQuantity
        self.imaginaryQuantity += cAdd.imaginaryQuantity
    def show(self):
        print(self.__str__())

c1 = Complex(2,3)
c2 = Complex(8,-1)
c1.add(c2)
c1.show()