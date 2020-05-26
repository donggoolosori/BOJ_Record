# 각 자리수의 수가 등차수열을 이루는지 확인
# 100~999의 수가 인풋


def IsAberration(num):
    str_num = str(num)
    a = int(str_num[0]) - int(str_num[1])
    b = int(str_num[1]) - int(str_num[2])
    if(a == b):
        return True
    else:
        return False


def IsHanSu(num):
    if(num == 1000):
        return False
    if(num < 100):
        return True
    else:
        if IsAberration(num):
            return True
        else:
            return False


cnt = 0
N = int(input())
for i in range(1, N+1):
    if IsHanSu(i):
        cnt += 1
print(cnt)
