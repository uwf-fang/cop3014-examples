// String content parsing using istringstream

string text = "John Smith 20 180.1";
istringstream inSS(text);

string firstName, firstName;
int age;
double height;
inSS >> firstName >> lastName >> age >> height;

// When delimiters are not white spaces (space, tab, etc.)
string text = "John Smith, 20, 180.1";
istringstream inSS(text);

string name, ageStr, heightStr;
int age;
double height;
getline(inSS, name, ',');
getline(inSS, ageStr, ',');
getline(inSS, heightStr , ',');
// convert ageStr, heightStr to the right type
// cannot use static_cast<int>(ageStr)


// Generate formatted text in a string using ostringstream
string makeFormattedText(string firstName, string lastName, int age, double height) {
    ostringstream outSS;
    outSS << firstName << " " << lastName << " " << age;
    outSS << " " << fixed << setprecision(1) << height;
    return outSS.str();
}


// Read from a file
// check open status
ifstream inFS("numbers.txt");
if (!inFS.is_open()) {
    cerr << "Error\n";
    return EXIT_FAILURE;
}

// alternative method
// if (inFS.fail()) {
//     cerr << "Error\n";
//     return EXIT_FAILURE;
// }

// === Read numbers from a file until the end of file ===

// 1. Cleanest method
int num;
while (inFS >> num) {
    cout << num << endl;
}

// 2. While
inFS >> num;
while (!inFS.eof()) {
    cout << num << endl;
    inFS >> num;
}

// 3. While
while (!inFS.eof()) {
    inFS >> num;
    if (!inFS.fail())
       cout << num << endl;
}

// 4. While true
while (true) {
    inFS >> num;
    if (inFS.eof())
        break;
    cout << num << endl;
}

// 5. Check fail rather than eof
inFS >> num;
while (!inFS.fail()) {
    cout << num << endl;
    inFS >> num;
}

// wrong! will display a wrong value in the very last iteration
while (!inFS.eof()) {
    inFS >> num;
    cout << num << endl;
}



// getline after extraction >>

int num1;
cout << "Give me an int";
cin >> num1;
string name;
cout << "Give me your full name";
// getline(cin, name); // wrong way, will read in an empty string
while (name.empty())
  getline(cin, name);
cout << "Name is " << name << endl;

