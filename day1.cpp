// This problem was recently asked by Google.

// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

// Bonus: Can you do this in one pass?

#include <bits/stdc++.h>
using namespace std;

// Basic naive method
void basic_method(int arr[], int n, int k) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((arr[i] + arr[j]) == k) {
        cout << "True" << endl;
        return;
      }
    }
  }
  cout << "False" << endl;
  return;
}

// Doing in one pass. Using hashmap because hashmap lookup happens in constant time
void bonus(int arr[], int n, int k) {
  unordered_set<int> s;
  for (int i = 0; i < n; i++) {
    int temp = k - arr[i];
    if (s.find(temp) != s.end()) {
      cout << "True" << endl;
      return ;
    }
    s.insert(arr[i]);
  }
  cout << "False" << endl;
  return ;
} 

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

  basic_method(arr, n, k);

  bonus(arr, n, k);

  return 0;
}