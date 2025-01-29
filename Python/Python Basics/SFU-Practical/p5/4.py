def is_valid_ip(ip):
    # Разделяем строку по точкам
    octets = ip.split('.')
    
    # Проверяем, что у нас 4 октета
    if len(octets) != 4:
        return False
    
    for octet in octets:
        # Проверяем, что октет состоит только из цифр
        if not octet.isdigit():
            return False
        
        # Преобразуем октет в целое число
        num = int(octet)
        
        # Проверяем, что число в диапазоне от 0 до 255
        if num < 0 or num > 255:
            return False
        
        # Проверяем, что октет не имеет ведущих нулей (например, '01' недопустим)
        if len(octet) > 1 and octet[0] == '0':
            return False

    return True

# Чтение входных данных
ip_address = input().strip()

# Проверка и вывод результата
if is_valid_ip(ip_address):
    print("YES")
else:
    print("NO")
