import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    num_list = list(map(int, input().split()))
    sum_list = [num_list[0]]
    for i in range(n-1):
        sum_list.append(max(sum_list[i]+num_list[i+1], num_list[i+1]))
    print(max(sum_list))
