#include <cassert>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// check if a string consists of all digits
bool isAllDigit(string userInput) {
  int size = userInput.length();
  for (int i = 0; i < size; ++i)
    if (userInput.at(i) < '0' || userInput.at(i) > '9') return false;
  return true;
}

// find first occurrance of a char in a string
// scan until a match if found
int findFirstInString(string word, char toSearch) {
  for (int i = 0; i < word.length(); ++i)
    if (word.at(i) == toSearch) return i;
  return -1;
}

// find the last occurrance
// always scan all elements
int findLastInString1(string word, char toSearch) {
  int result = -1;
  for (int i = 0; i < word.length(); ++i)
    if (word.at(i) == toSearch) result = i;
  return result;
}

// find the last occurrance
// search backwards
int findLastInString2(string word, char toSearch) {
  // memorize this pattern!
  for (int i = word.length() - 1; i >= 0; i--)
    if (word.at(i) == toSearch) return i;
  return -1;
}

// find the last occurrance
// search backwards
int findLastInString3(string word, char toSearch) {
  int size = word.length();
  int i;
  int position;
  for (i = 0; i < size; ++i) {
    position = size - 1 - i;
    if (word.at(position) == toSearch) return i;
  }
  return -1;
}

// how many layer loop?
bool isIdenticalString(string str1, string str2) {
  if (str1.length() != str2.length()) return false;
  int size = str1.length();
  for (int i = 0; i < size; ++i)
    if (str1.at(i) != str2.at(i)) return false;
  return true;
}

// how many layer loop?
// only need to modify one line from the above function
bool isReverse(string str1, string str2) {
  if (str1.length() != str1.length()) return false;
  int size = str1.length();
  for (int i = 0; i < size; ++i)
    if (str1.at(i) != str2.at(size - 1 - i)) return false;
  return true;
}

int findSubStr(string text, string sub) {
  int size1 = text.length();
  int size2 = sub.length();
  int offset = 0;

  // (size1 - size2) * (size2 - 1)
  for (int start = 0; start <= size1 - size2; start++)
    if (text.at(start) == sub.at(0)) {
      for (offset = 1; offset < size2; offset++)
        if (text.at(start + offset) != sub.at(offset)) break;
      if (offset == size2)  // matched
        return start;
    }
  return -1;
}


int findLengthOfLongestPalindrome(string text) {
  for (int i = 0; i < text.length() - 1; ++i) {
    for (int j = text.length() - 1; j > i; j--)
      if (isPalindrome(text, i, j)) {
        // cout << text << " " << i << " " << j << endl;
        return (j - i + 1);
      }
  }
  return 1;
}

bool isPalindrome(string text, int start, int end) {
  for (int i = 0; i <= (end - start) / 2; ++i)
    if (text.at(start + i) != text.at(end - i))
      return false;
  return true;
}

void testLongestPalindrome() {
  string text = "abcdedcba";
  assert(findLengthOfLongestPalindrome(text) == text.length());
  text = "abc";
  // cout << findLengthOfLongestPalindrome(text) << endl;
  assert(findLengthOfLongestPalindrome(text) == 1);

}
void testIsPalindrome() {
  string text = "abcdedcba";
  assert(isPalindrome(text, 3, 5));
  assert(!isPalindrome(text, 2, 5));
  text = "abc";
  assert(!isPalindrome(text, 0, 1));
}
void testSubStringSearch() {
  cout << "Testing sub-string search" << endl;
  string str1 = "abcde";
  assert(findSubStr(str1, "cd") == 2);
  assert(findSubStr(str1, "abcde") == 0);
  assert(findSubStr(str1, "dd") == -1);
  cout << "All tests passed" << endl;
}

void testIsReverse() {
  cout << "Testing isReverse" << endl;
  string str1 = "abcde";
  string str2 = "edcba";
  assert(isReverse(str1, str2));
  cout << "All tests passed" << endl;
}

int main() {
  testSubStringSearch();
  // testIsReverse();
  // testIsPalindrome();
  // testLongestPalindrome();
  return EXIT_SUCCESS;
}