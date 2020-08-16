from sys import stdin
input = stdin.readline


def solve():
    cnt = 0
    i = 0
    while i <= text_len-target_len:
        if text[i:i+target_len] == target:
            cnt += 1
            i += target_len
        else:
            i += 1
    print(cnt)


if __name__ == "__main__":
    text = input().rstrip()
    text_len = len(text)
    target = input().rstrip()
    target_len = len(target)
    solve()
