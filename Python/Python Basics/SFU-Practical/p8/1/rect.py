class Rectangle:
    def __init__(self, name, width, height):
        """Инициализация атрибутов ширины и высоты."""
        self.name = name
        self.width = width  # атрибут ширины
        self.height = height  # атрибут высоты

    def getwidth(self):
        return self.width

    def getheight(self):
        return self.height


    def area(self):
        """Метод для вычисления площади прямоугольника."""
        return self.width * self.height

    def perimeter(self):
        """Метод для вычисления периметра прямоугольника."""
        return 2 * (self.width + self.height)

    def digonal(self):
        
        return ((self.width**2)+(self.height**2))**0.5
    
    def isSquare(self):
        if self.width == self.height:
            return("Square!")
        else: return("Not a square.")

    def __str__(self):
        """Метод для представления объекта в виде строки."""
        return f"Rectangle(width={self.width}, height={self.height})"
    
    def ask_to_change_dimensions(self):
        change = input("Хотите изменить размеры? (да/нет): ")
        if change.lower() == 'да':
            new_width = float(input("Введите новую ширину: "))
            new_height = float(input("Введите новую высоту: "))
            self.width = new_width
            self.height = new_height
            print("Размеры изменены.")
        else:
            print("Размеры остались прежними.")