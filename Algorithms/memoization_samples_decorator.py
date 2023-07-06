# Memoization using a decorator
def memoize(f):
    # Initialize an empty dictionary to store the input and output pairs
    cache = {}
    # Define a wrapper function that applies memoization to f
    def wrapper(*args):
        # Check if the input is already in the cache
        if args in cache:
            return cache[args]
        # Call f and store the result in the cache
        result = f(*args)
        cache[args] = result
        return result
    # Return the wrapper function
    return wrapper

# Define a function to be memoized
@memoize # Apply the memoize decorator to factorial
def factorial(n):
    # Base case: return 1 for n = 0 or 1
    if n == 0 or n == 1:
        return 1
    # Recursive case: return n * factorial(n-1)
    return n * factorial(n-1)

N = int(input("Enter the number you want to find of: "))
# Test the function
print(factorial(N)) 
