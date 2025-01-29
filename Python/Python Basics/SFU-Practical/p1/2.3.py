#    3 (задача 112158). Программа принимает три числа: возраст Антона,
#    возраст Бориса и возраст Виктора. Определите, кто из них старше остальных

ages = input()
a, b, c = map(int, ages.split())

if a == b == c:
    print(0)
else:
    max_age = max(a, b, c)
    result = []
    
    if a == max_age:
        result.append('A')
    if b == max_age:
        result.append('B')
    if c == max_age:
        result.append('C')
    
    print(' '.join(sorted(result)))