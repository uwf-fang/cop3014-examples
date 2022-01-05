/******************************************************************************
 * Text menu sample code
*******************************************************************************/

#include <iostream>
using namespace std;

void menu() {
  // cout << "1. Option 1\n";
  cout << "1. Option 1" << endl;
  cout << "2. Option 2\n";
  cout << "3. Option 3\n";
  cout << "4. Option 4\n";
  cout << "5. Option 5\n";
  cout << "Please make your choice (e to exit): ";
}

int main()
{
  char choice;
  do {
    // display menu to user
    menu();
    // get choice
    cin >> choice;
    // do works according to user choice
    switch (choice) {
      case '1':
        // job 1
        cout << "Working on option 1\n";
        break;
      case '2':
        // job 2
        cout << "Working on option 2\n";
        break;
      case '3':
        // job 3
        cout << "Working on option 3\n";
        break;
      case '4':
        // job 4
        cout << "Working on option 4\n";
        break;
      case '5':
        // job 5
        cout << "Working on option 5\n";
        break;
      default:
        cout << "Invalid option\n";
    }
  } while (choice != 'e' && choice != 'E'); // when user do not want to exit

  return EXIT_SUCCESS;
}
