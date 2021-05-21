// This problem was asked by Uber.

// Given an array of integers, 
// return a new array such that 
// each element at index i of the new array is 
// the product of all the numbers in the original array except the one at i.

// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. 
// If our input was [3, 2, 1], the expected output would be [2, 3, 6].

// Follow-up: what if you can't use division?

#include <bits/stdc++.h>
using namespace std;

// basic method. Calculate total product and divide it with eavh element to get corresponding product
void naive(int arr[], int n) {
  long long int prod = 1;
  for (int i = 0; i < n; i++) {
    prod = prod * arr[i];
  }
  long long int res[n];
  for (int i = 0; i < n ;i++) {
    res[i] = prod / arr[i];
  }
  cout << "Output array : ";
  for (int i = 0; i < n ;i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return;
}

int main() {
  int n;
  cout << "Enter size of array : ";
  cin >> n;
  int arr[n];
  cout << "Enter array elements : ";
  for (int i = 0;i < n; i++) {
    cin >> arr[i];
  }

  naive(arr, n);

  return 0;
}