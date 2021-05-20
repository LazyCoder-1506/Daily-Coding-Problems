// This problem was recently asked by Google.

// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

// Bonus: Can you do this in one pass?

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cout << "Enter size of array : ";
  cin >> n;
  int arr[n];
  cout << "Enter array elements :" << endl;
  for (int i = 0; i < n ; i++) {
    cin >> arr[i];
  }
  cout << "Enter the required sum : ";
  cin >> k;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((arr[i] + arr[j]) == k) {
        cout << "True" << endl;
        return 0;
      }
    }
  }
  cout << "False" << endl;
  return 0;
}