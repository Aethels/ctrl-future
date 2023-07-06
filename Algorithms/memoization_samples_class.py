# Memoization using a class
class Memoize:
    def __init__(self, f):
        # Store the function to be memoized
        self.f = f
        # Initialize an empty dictionary to store the input and output pairs
        self.cache = {}
    
    def __call__(self, *args):
        # Check if the input is already in the cache
        if args in self.cache:
            return self.cache[args]
        # Call the function and store the result in the cache
        result = self.f(*args)
        self.cache[args] = result
        return result

# Define a function to be memoized
def factorial(n):
    # Base case: return 1 for n = 0 or 1
    if n == 0 or n == 1:
        return 1
    # Recursive case: return n * factorial(n-1)
    return n * factorial(n-1)

# Wrap the function with the Memoize class
factorial = Memoize(factorial)

N = int(input("Enter the number of array elements: "))
# Test the function
print(factorial(N)) 
