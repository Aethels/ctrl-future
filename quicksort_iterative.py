# import random module
import random

# define a function for quicksort
def quicksort(arr):
  # create an empty stack
  stack = []
  # push the initial subarray indices to the stack
  stack.append((0, len(arr) - 1))
  # loop until the stack is empty
  while stack:
    # pop the top subarray indices from the stack
    low, high = stack.pop()
    # base case: if the subarray is empty or has one element, skip it
    if low >= high:
      continue
    # choose a pivot element randomly
    pivot = arr[random.randint(low, high)]
    # partition the subarray into two subarrays: left and right
    left = low
    right = high
    while left <= right:
      # find the first element in the left subarray that is greater than or equal to the pivot
      while arr[left] < pivot:
        left += 1
      # find the first element in the right subarray that is less than or equal to the pivot
      while arr[right] > pivot:
        right -= 1
      # swap the elements if they are out of order
      if left <= right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1
    # push the left and right subarrays to the stack
    stack.append((low, right))
    stack.append((left, high))
  # return the sorted array
  return arr

# take N from user and validate it
N = int(input("Enter the size of the array: "))
if N < 0:
  print("Invalid input. Size must be positive.")
else:
  # randomly generate an array of N elements from 1 to 100
  arr = [random.randint(1,100) for _ in range(N)]
  # print the original array
  print("Original array:", arr)
  # sort the array using quicksort and print it
  sorted_arr = quicksort(arr)
  print("Sorted array:", sorted_arr)
