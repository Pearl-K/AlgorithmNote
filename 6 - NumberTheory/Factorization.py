now = 2
while now * now <= N_cp:
    if prime[now]:
        while N_cp%now == 0:
            N_factors.append(str(now))
            N_cp //= now
    now += 1
if N_cp != 1:
    N_factors.append(str(N_cp))
