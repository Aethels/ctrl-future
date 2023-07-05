# import the random module
import random

# ask the user for the size of the array
N = int(input("Enter the size of the array: "))

# generate a random array of N integers between 1 and 100
array = [random.randint(1, 100) for _ in range(N)]

# sort the array in ascending order
array.sort()

# print the array
print("The array is:", array)

# ask the user for the number to search
X = int(input("Enter the number to search: "))

# define a function for binary search
def binary_search(array, X):
  # initialize the left and right pointers
  left = 0
  right = len(array) - 1

  # loop until the pointers cross or the number is found
  while left <= right:
    # find the middle index
    mid = (left + right) // 2

    # check if the number is at the middle
    if array[mid] == X:
      # return the index
      return mid
    
    # check if the number is smaller than the middle
    elif X < array[mid]:
      # move the right pointer to the left of the middle
      right = mid - 1
    
    # check if the number is larger than the middle
    else:
      # move the left pointer to the right of the middle
      left = mid + 1
  
  # return -1 if the number is not found
  return -1

# call the function and store the result
result = binary_search(array, X)

# print the result
if result == -1:
  print("The number", X, "is not in the array.")
else:
  print("The number", X, "is at index", result, "in the array.")