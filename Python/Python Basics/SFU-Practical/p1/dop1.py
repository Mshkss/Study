
x, y = map(float, input().split())
bit_code = ""

if y <= 1:
    bit_code += '1'
else:
    bit_code += '0'


if y <= -x:
    bit_code += '1'
else:
    bit_code += '0'

if (x ** 2 + y ** 2) <= 1:
    bit_code += '1'
else:
    bit_code += '0'

if ((x - 1) ** 2 + y ** 2) <= 1:
    bit_code += '1'
else:
    bit_code += '0'

print(bit_code)