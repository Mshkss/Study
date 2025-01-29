def to_hex(n):
    if n == 0:
        return ""

    hex_chars = "0123456789ABCDEF"
    remainder = n % 16
    return to_hex(n // 16) + hex_chars[remainder]

def convert_to_hex(n):
    if n < 0:
        n = -n
        hex_result = to_hex(n)
        return "-" + hex_result if hex_result else "0"
    elif n == 0:
        return "0"
    else:
        return to_hex(n)

input_number = int(input())
hexadecimal_representation = convert_to_hex(input_number)
print(hexadecimal_representation)
