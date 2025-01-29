import customtkinter as ctk
import os

# Класс для представления автомобиля
class Car:
    def __init__(self, brand, model, year, color):
        self.brand = brand
        self.model = model
        self.year = year
        self.color = color

    def __str__(self):
        return f"{self.brand},{self.model},{self.year},{self.color}"

# Функция для загрузки автомобилей из файла
def load_cars(filename):
    cars = []
    if os.path.exists(filename):
        with open(filename, "r") as file:
            lines = file.readlines()[1:]  # Пропускаем заголовок
            for line in lines:
                brand, model, year, color = line.strip().split(",")
                cars.append(Car(brand, model, year, color))
    return cars

# Функция для сохранения автомобиля в файл
def save_car(filename, car):
    with open(filename, "a") as file:
        file.write(str(car) + "\n")

# Основное приложение
class CarApp(ctk.CTk):
    def __init__(self):
        super().__init__()

        self.title("Автомобильное приложение")
        self.geometry("600x500")

        self.cars = load_cars("cars.txt")
        self.filtered_cars = self.cars  # Список для хранения отфильтрованных автомобилей

        # Таблица для отображения автомобилей
        self.table = ctk.CTkTextbox(self)
        self.table.pack(pady=10, padx=10, fill="both", expand=True)
        self.update_table()

        # Поля для добавления нового автомобиля
        self.brand_entry = ctk.CTkEntry(self, placeholder_text="Марка")
        self.brand_entry.pack(pady=5)

        self.model_entry = ctk.CTkEntry(self, placeholder_text="Модель")
        self.model_entry.pack(pady=5)

        self.year_entry = ctk.CTkEntry(self, placeholder_text="Год")
        self.year_entry.pack(pady=5)

        self.color_entry = ctk.CTkEntry(self, placeholder_text="Цвет")
        self.color_entry.pack(pady=5)

        # Кнопка для добавления нового автомобиля
        self.add_button = ctk.CTkButton(self, text="Добавить автомобиль", command=self.add_car)
        self.add_button.pack(pady=10)

        # Поля для фильтрации
        self.filter_brand_entry = ctk.CTkEntry(self, placeholder_text="Фильтр по марке")
        self.filter_brand_entry.pack(pady=5)

        self.filter_model_entry = ctk.CTkEntry(self, placeholder_text="Фильтр по модели")
        self.filter_model_entry.pack(pady=5)

        self.filter_year_entry = ctk.CTkEntry(self, placeholder_text="Фильтр по году")
        self.filter_year_entry.pack(pady=5)

        self.filter_color_entry = ctk.CTkEntry(self, placeholder_text="Фильтр по цвету")
        self.filter_color_entry.pack(pady=5)

        # Кнопка для применения фильтрации
        self.filter_button = ctk.CTkButton(self, text="Применить фильтр", command=self.apply_filter)
        self.filter_button.pack(pady=10)

    def update_table(self):
        self.table.delete("1.0", ctk.END)  # Очистка таблицы
        self.table.insert(ctk.END, "Марка,Модель,Год,Цвет\n")  # Заголовок
        for car in self.filtered_cars:
            self.table.insert(ctk.END, str(car) + "\n")

    def add_car(self):
        brand = self.brand_entry.get()
        model = self.model_entry.get()
        year = self.year_entry.get()
        color = self.color_entry.get()

        if brand and model and year and color:
            new_car = Car(brand, model, year, color)
            save_car("cars.txt", new_car)
            self.cars.append(new_car)
            self.filtered_cars.append(new_car)  # Добавляем в отфильтрованные
            self.update_table()

            # Очистка полей ввода
            self.brand_entry.delete(0, ctk.END)
            self.model_entry.delete(0, ctk.END)
            self.year_entry.delete(0, ctk.END)
            self.color_entry.delete(0, ctk.END)

    def apply_filter(self):
        brand_filter = self.filter_brand_entry.get().lower()
        model_filter = self.filter_model_entry.get().lower()
        year_filter = self.filter_year_entry.get()
        color_filter = self.filter_color_entry.get().lower()

        # Фильтрация списка автомобилей
        self.filtered_cars = [
            car for car in self.cars
            if (brand_filter in car.brand.lower() if brand_filter else True) and
               (model_filter in car.model.lower() if model_filter else True) and
               (year_filter in car.year if year_filter else True) and
               (color_filter in car.color.lower() if color_filter else True)
        ]

        # Обновление таблицы после фильтрации
        self.update_table()

if __name__ == "__main__":
    app = CarApp()
    app.mainloop()
