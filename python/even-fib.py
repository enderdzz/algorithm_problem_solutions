i = 2
j = 1
ans = 2
while i <= 4000000:
    tmp = i
    i = i + j
    print i
    j = tmp
    if i%2 == 0:
        ans = ans + i
print ans

i = 600851475143

def primefact(n):
    tmp = 2
    while tmp*tmp <= n:
        while n%tmp == 0:
            yield tmp
            n = n // tmp
        tmp = tmp + 1
    if n > 1:
        yield n

print max(primefact(i)) 
# just use the bash shell: factor 600851475143
