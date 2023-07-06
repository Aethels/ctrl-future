# Import random module
import random

# Define a function to generate a random string of a given length
def random_string(length):
  # Define the alphabet
  alphabet = "abcdefghijklmnopqrstuvwxyz"
  # Initialize an empty string
  result = ""
  # Loop for the given length
  for i in range(length):
    # Append a random character from the alphabet
    result += random.choice(alphabet)
  # Return the result
  return result

# Define a function to perform recursive binary search on a sorted array of strings
def binary_search(array, target, low, high):
  # Check if the array is empty
  if low > high:
    # Return -1 if not found
    return -1
  # Find the middle index
  mid = (low + high) // 2
  # Compare the middle element with the target
  if array[mid] == target:
    # Return the index if found
    return mid
  elif array[mid] < target:
    # Recursively search the right subarray
    return binary_search(array, target, mid + 1, high)
  else:
    # Recursively search the left subarray
    return binary_search(array, target, low, mid - 1)
  
  # Ask the user to enter N
N = int(input("Enter the size of the array: : "))

# Generate an array of N random strings of length 5
array = [random_string(5) for i in range(N)]

# Sort the array in ascending order
array.sort()

# Print the array
print("Array:", array)

# Ask the user to enter a target string
target = X =input("Enter the word to search: ")

# Perform binary search on the array and print the result
result = binary_search(array, target, 0, len(array) - 1)
# print the result
if result == -1:
  print("The word", target, "is not in the array.")
else:
  print("The word", target, "is at index", result, "in the array.")
