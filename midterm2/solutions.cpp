// Q21

int main() {
  int arr[3][4];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 5; j++)
      arr[i][j] = i + j;
  cout << "The array is:\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}

int main() {
  int arr[3][4];
  cout << "The array is:\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      arr[i][j] = i + j;
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}


// Q22


#include <iostream>
using namespace std;

void display(char *arr, int size);
void revCharArr(char *arr, int size);

int main(){
  char arr[11] = {'B', 'e', ' ', 'p', 'o', 's', 'i', 't', 'i', 'v', 'e'};
  cout << "The original array is:\n";
  display(arr, 11);
  revCharArr(arr, 11);
  cout << "After reversal, the same array is:\n";
  display(arr, 11);

return 0;
}

void display(char *arr, int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i];
  cout << endl;
}
void revCharArr(char *arr, int size) {
  for (int i = 0; i < size / 2; i ++) {
    int temp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temp;
  }
}