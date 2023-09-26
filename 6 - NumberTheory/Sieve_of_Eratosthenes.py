prime = [1 for i in range(10**6+1)]
prime[0], prime[1] = 0, 0

now = 2
while now * now <= 10**6:
    if prime[now]:
        for i in range(2*now, 10**6+1, now):
            prime[i] = 0
    now += 1
