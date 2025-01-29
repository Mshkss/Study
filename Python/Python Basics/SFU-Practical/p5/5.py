def format_string(s):
    s = s.strip() # Удаляем начальные и конечные пробелы
    
    # Заменяем множественные пробелы одним пробелом
    s = ' '.join(s.split())
    
    # Заменяем пробелы перед запятыми и точками
    s = s.replace(' ,', ',').replace(' .', '.')
    
    # Добавляем пробел после запятой и точки, если они стоят в конце слова
    s = s.replace(',', ', ').replace('.', '. ')
    
    # Удаляем пробелы перед концом строки
    s = s.rstrip()
        
    return s

input_string = input()

formatted_string = format_string(input_string)

print(formatted_string)
