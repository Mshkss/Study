def find_repeating_digits(input_string):
    digit_count = {}
    
    # Подсчет количества каждой цифры
    for char in input_string:
        if char.isdigit():
            if char in digit_count:
                digit_count[char] += 1
            else:
                digit_count[char] = 1
                
    # Сбор цифр, которые встречаются более одного раза
    repeating_digits = [digit for digit, count in digit_count.items() if count > 1]
    
    # Проверка на наличие повторяющихся цифр
    if repeating_digits:
        # Сортировка и вывод результата
        print(''.join(sorted(repeating_digits)))
    else:
        print('NO')

# Пример использования
input_string = input()
find_repeating_digits(input_string)
