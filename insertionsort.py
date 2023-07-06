# import the random module
import random

# Get the number of array elements from the user
N = int(input("Enter the number of array elements: "))

# Generate a random array of size N
array = [random.randint(1, 100) for _ in range(N)]

# Print the original array
print("Original array:", array)

# Insertion sort algorithm
def insertion_sort(array):
    # Loop through the array from the second to the last element
    for i in range(1, len(array)):
        # Store the current element in a temporary variable
        temp = array[i]
        # Initialize a pointer to track the position of the current element in the sorted subarray
        j = i - 1
        # Loop through the sorted subarray from right to left and shift the elements that are greater than the current element to the right
        while j >= 0 and array[j] > temp:
            array[j + 1] = array[j]
            j -= 1
        # Insert the current element into its correct position in the sorted subarray
        array[j + 1] = temp
    # Return the sorted array
    return array

# Call the insertion sort function and print the sorted array
sorted_array = insertion_sort(array)
print("Sorted array:", sorted_array)
