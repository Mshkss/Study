def possible_numbers(n, questions_answers):
    possible = set(range(1, n + 1))  # Множество всех возможных чисел

    for question, answer in questions_answers:
        if answer == "YES":
            # Убираем из возможных чисел все, что не в вопросе
            possible.intersection_update(set(question))
        elif answer == "NO":
            # Убираем из возможных чисел все, что в вопросе
            possible.difference_update(set(question))

    return sorted(possible)  # Возвращаем отсортированный список возможных чисел

# Чтение входных данных
n = int(input().strip())
questions_answers = []

while True:
    line = input().strip()
    if line == "HELP":
        break
    question = list(map(int, line.split()))
    answer = input().strip()  # Читаем ответ (YES или NO)
    questions_answers.append((question, answer))

# Получаем возможные числа
result = possible_numbers(n, questions_answers)

# Выводим результат
print(" ".join(map(str, result)))
