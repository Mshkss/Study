def to_octal_code(n):
    octal_str = oct(n)[2:] 
    

    octal_str = octal_str.zfill(10)
    
    return octal_str

N = int(input())

if 0 <= N < 8**10:
    result = to_octal_code(N)
    print(result)
else:
    print("")
