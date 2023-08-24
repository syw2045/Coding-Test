n, m = map(int, input().split())

result = 0

for i in range(n):
    data = list(map(int, input().split())) # 행 입력
    min_value = 10001
    for a in data:
        min_value = min(min_value, a) # 행에서 제일 작은 값
    result = max(result, min_value) # 지금까지 제일 작은 값 중 가장 큰 값

print(result)