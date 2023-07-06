# Memoization using a dictionary
def fibonacci(n, cache={}):
    # Check if the input is already in the cache
    if n in cache:
        return cache[n]
    # Base case: return 0 or 1 for n = 0 or 1
    if n == 0:
        return 0
    if n == 1:
        return 1
    # Recursive case: calculate the nth Fibonacci number and store it in the cache
    result = fibonacci(n-1, cache) + fibonacci(n-2, cache)
    cache[n] = result
    return result
# Get the number of array elements from the user
N = int(input("Enter the number you want to find of: "))
# Test the function
print(fibonacci(N)) 