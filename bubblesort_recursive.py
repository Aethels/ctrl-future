# Import the random module
import random

# Get the number of array elements from the user
N = int(input("Enter the number of array elements: "))

# Generate a random array of size N
array = [random.randint(1, 100) for _ in range(N)]

# Print the original array
print("Original array:", array)

# Recursive bubble sort algorithm
def bubble_sort(array, n):
    # Base case: if the array has one or zero elements, it is already sorted
    if n <= 1:
        return array
    # Loop through the array from the first to the second last element
    for i in range(n - 1):
        # Compare adjacent elements and swap them if they are out of order
        if array[i] > array[i + 1]:
            array[i], array[i + 1] = array[i + 1], array[i]
    # Recursively call the bubble sort function on the subarray excluding the last element
    return bubble_sort(array, n - 1)

# Call the bubble sort function and print the sorted array
sorted_array = bubble_sort(array, N)
print("Sorted array:", sorted_array)
