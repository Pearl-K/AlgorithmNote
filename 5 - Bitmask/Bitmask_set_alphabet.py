import sys
input = sys.stdin.readline
N, K = map(int, input().split())
#단어를 특정 알파벳들의 집합이라고 생각하기? -> 이걸 비트집합으로 표현

res = 0
word_list = [0]*N
# 백준 1062 : https://www.acmicpc.net/problem/1062

from itertools import combinations

for i in range(N):
    word = input().rstrip()
    for j in word:
        word_list[i] |= (1 << (ord(j) - ord('a')))

if K < 5:
    print(0)
else:
    K -= 5
    est = {'a', 'c', 'i', 'n', 't'}
    alp = {a: i for i, a in enumerate((set(map(chr, range(ord('a'), ord('z')+1))) - est))}

    for i in combinations(alp, K):
        now = 0
        cnt = 0

        for j in est:
            now |= (1 << (ord(j) - ord('a')))
        for j in i:
            now |= (1 << (ord(j) - ord('a')))

        for w in word_list:
            if now & w == w:
                cnt += 1
        res = max(res, cnt)
    print(res)
