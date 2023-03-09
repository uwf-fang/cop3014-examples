/**
 * @brief Examples of map functions
 *        No tests provided
 */

// double all values
// in-place algorithm
void doubleAll(int *arr, int size) {
  for (int i = 0; i < size; ++i)
    arr[i] *= 2;
}

// convert all values to their absolute values
void absolute(int *arr, int size) {
  for (int i = 0; i < size; ++i)
    if (arr[i] < 0) arr[i] *= -1;
}

