m = int(input().strip())
text = input().strip()

words = text.split()  #деление текста на слова
formatted_lines = []
current_line = ""

for word in words: #проверка вмещается ли текст
    if len(current_line) + len(word) + (1 if current_line else 0) <= m:
        if current_line:  # если не первая строка, добавляется пробел
            current_line += " "
        current_line += word
    else:
        formatted_lines.append(current_line)  # добавляется текущая строка
        current_line = word  #новая строка с текущего слова

# добавляется ласт строка,если она не пустая
if current_line:
    formatted_lines.append(current_line)

for line in formatted_lines:
    print(line)
