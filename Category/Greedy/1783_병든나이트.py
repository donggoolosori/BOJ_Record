import sys
input = sys.stdin.readline


if __name__ == "__main__":
    n, m = map(int, input().split())
    # 움직일 수 없다
    if n == 1:
        print(1)
    # 오직 2,3번 방법만 사용가능 하다.
    elif n == 2:
        print(min(4, (m+1)//2))
    else:
        # 만약 m이 6보다 작으면 모든 방법을 사용할 수 없으므로
        # 4와 1번 4번 방법을 사용해 움직인 값중 최소값 선택
        if m <= 6:
            print(min(4, m))
        else:
            # 2,3번을 사용해야 하므로 1번과 4번만 사용한 경우에서 2를 빼준다
            print(m-2)
