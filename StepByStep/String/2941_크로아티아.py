S = input()
croatia_Alphabet = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

for i in croatia_Alphabet:
    S = S.replace(i, 'x')

print(len(S))
