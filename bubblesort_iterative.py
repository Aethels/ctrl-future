#import the random module
import random

# Get the number of array elements from the user
N = int(input("Enter the number of array elements: "))

# Generate a random array of size N
array = [random.randint(1, 100) for _ in range(N)]

# Print the original array
print("Original array:", array)

# Bubble sort algorithm
def bubble_sort(array):
    # Loop through the array from the first to the second last element
    for i in range(len(array) - 1):
        # Loop through the array from the first to the last unsorted element
        for j in range(len(array) - 1 - i):
            # Compare adjacent elements and swap them if they are out of order
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    # Return the sorted array
    return array

# Call the bubble sort function and print the sorted array
sorted_array = bubble_sort(array)
print("Sorted array:", sorted_array)