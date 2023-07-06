# import the random module
import random

# Get the number of array elements from the user
N = int(input("Enter the number of array elements: "))

# Generate a random array of size N
array = [random.randint(1, 100) for _ in range(N)]

# Print the original array
print("Original array:", array)

# Merge sort algorithm
def merge_sort(array):
    # Base case: if the array has one or zero elements, it is already sorted
    if len(array) <= 1:
        return array
    # Divide the array into two halves and sort them recursively
    mid = len(array) // 2
    left = merge_sort(array[:mid])
    right = merge_sort(array[mid:])
    # Merge the two sorted halves into one sorted array
    return merge(left, right)

# Helper function to merge two sorted arrays
def merge(left, right):
    # Initialize an empty result array
    result = []
    # Initialize two pointers to track the indices of left and right arrays
    i = 0
    j = 0
    # Loop until one of the arrays is exhausted
    while i < len(left) and j < len(right):
        # Compare the current elements of left and right arrays and append the smaller one to the result
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    # Append the remaining elements of the non-exhausted array to the result
    result.extend(left[i:])
    result.extend(right[j:])
    # Return the merged result array
    return result

# Call the merge sort function and print the sorted array
sorted_array = merge_sort(array)
print("Sorted array:", sorted_array)
