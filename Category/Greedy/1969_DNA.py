from sys import stdin
input = stdin.readline

if __name__ == "__main__":
    n, m = map(int, input().split())
    dna = [input().rstrip() for _ in range(n)]
    newcleo = ['A', 'C', 'G', 'T']
    res = ''
    cnt = 0
    for j in range(m):
        cnt_list = [0]*4  # A,C,G,T
        for i in range(n):
            cnt_list[newcleo.index(dna[i][j])] += 1
        best_index = cnt_list.index(max(cnt_list))
        cnt += sum(cnt_list)-max(cnt_list)
        res += newcleo[best_index]
    print(res)
    print(cnt)
