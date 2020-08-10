import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    dy = [0, 1, 3]
    for i in range(3, n+1):
        dy.append(dy[i-1]+2*dy[i-2])
    print(dy[n] % 10007)
