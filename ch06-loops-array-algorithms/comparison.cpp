/**
 * @brief Examples of array comparison functions
 *        No tests provided
 */

bool isReverse(int *arr1, int size1, int *arr2, int size2) {
  if (size1 != size2) return false;
  for (int i = 0; i < size1; ++i)
    if (arr1[i] != arr2[size1 - 1 - i]) return false;
  return true;
}

bool isPalindrome(int *arr, int size) {
  for (int i = 0; i < size / 2; ++i)
    if (arr[i] != arr[size - 1 - i]) return false;
  return true;
}
