/**
 * @brief Examples of aggregate functions
 *        No tests provided
 */

// Count the occurrence of a certain value
int count(int *arr, int size, int value) {
  int count = 0;
  for (int i = 0; i < size; ++i)
    if (arr[i] == value)
      ++count;
  return count;
}

int sum(int *arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; ++i)
    sum += arr[i];
  return sum;
}

double average(int *arr, int size) {
  return static_cast<double>(sum(arr, size)) / size;
}

// Assuming non-empty array
int argMin(int *arr, int size) {
  int currMin = arr[0];
  int location = 0;
  for (int i = 1; i < size; ++i)
    if (arr[i] < currMin) {
      currMin = arr[i];
      location = i;
    }
  return location;
}

