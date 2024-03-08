def getFibonacci(fib0,fib1,now,num):
    return (fib1 if num == now else getFibonacci(fib1,fib0 + fib1,now + 1,num))

n = int(input('input n:'))
print(getFibonacci(0,1,1,n))