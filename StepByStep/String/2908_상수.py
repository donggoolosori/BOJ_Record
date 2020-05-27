A, B = input().split()
r_A, r_B = (A[::-1], B[::-1])
print(int(r_A) if int(r_A) > int(r_B) else int(r_B))
