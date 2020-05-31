import math

R = int(input())
U_area = round(math.pi*(R**2), 6)
T_area = round((R**2)*2, 6)
print(U_area, T_area, sep='\n')
