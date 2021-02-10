import sys

def powI(power, base):
    acc, p = 1, 0
    for p in range(power):
        acc *= base
    return acc

def powF(power, base):
    return 1 if power <= 0 else base*powF(power-1, base)

b = int(sys.argv[1])
p = int(sys.argv[2])
print(powI(p, b))
print(powF(p, b))


