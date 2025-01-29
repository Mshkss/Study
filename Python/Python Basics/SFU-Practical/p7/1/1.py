with open(r'p7\1\input.txt', 'r', encoding='utf-8') as file:
    lines = file.readlines()

sample_word = lines[0].strip()
replacement_word = lines[1].strip()

text_lines = lines[2:]

words = []
for line in text_lines:
    words.extend(line.strip().split())

filtered_words = [word for word in words if word.rstrip('.,!?;:') == sample_word]

for i in range(len(words)):
    if words[i].rstrip('.,!?;:') == sample_word:
        words[i] = replacement_word 

with open(r'D:\Python Projects\OPP\p7\1\output.txt', 'w', encoding='utf-8') as file:
    file.write(' '.join(words))