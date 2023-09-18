#이분탐색으로 블랙홀 위치 찾기
#일치하는 위치 없으면 가장 왼쪽 아이 찾기

def BS(start, end, target):
    Flag = False
    while start <= end:
        mid = (start + end)//2

        if black[mid] == target:
            Flag = True
            return mid
        elif black[mid] < target:
            start = mid + 1
        else: #black[mid] > target
            end = mid - 1

    if not Flag:
        if start == N:
            start -= 1
        if end == -1:
            end += 0
        low = abs(black[start]-target)
        high = abs(black[end]-target)
        if low < high:
            return start
        else: return end
