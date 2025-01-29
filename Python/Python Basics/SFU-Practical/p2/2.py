def xor(x, y):
    return (x and not y) or (not x and y)

input_values = input()
x_str, y_str = input_values.split()  

x = int(x_str)
y = int(y_str)

if x not in (0, 1) or y not in (0, 1):
    print("error x и y != 0/1")
else:
    result = xor(x, y)
    print(int(result))  
