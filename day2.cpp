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
#define EPS 1e-9

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

// creating a copy of array and adding at end, then multiplying n - 1 elements from element after a[i]
void bonus_inefficient(int arr[], int n) {
  int new_arr[2 * n];
  for (int i = 0; i < 2 * n; i++) {
    new_arr[i] = arr[i % n];
  }
  long long int res[n];
  for (int i = 0; i < n ;i++) {
    long long prod = 1;
    for (int j = 1; j < n; j++) {
      prod = prod * new_arr[i + j];
    }
    res[i] = prod;
  }
  cout << "Output array : ";
  for (int i = 0; i < n ;i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return;
}

// calculate prefix products and suffix products once. Then multiply corresponding prefix and suffix for each element
void bonus_efficient(int arr[], int n) {
  long long int product[n];
  int temp = 1;
  for (int i = 0; i < n ;i++) {
    product[i] = temp;
    temp = temp * arr[i];
  }
  temp = 1;
  for (int i = n - 1; i >= 0 ;i--) {
    product[i] = product[i] * temp;
    temp = temp * arr[i];
  }
  cout << "Output array : ";
  for (int i = 0; i < n ;i++) {
    cout << product[i] << " ";
  }
  cout << endl;
  return;
}

// use log properties to convert multiplication and division into addition and subtraction
void op_solution(int arr[], int n) {
  long double log_sum = 0;
  for (int i = 0; i < n ; i++) {
    log_sum = log_sum + (long double)log10(arr[i]);
  }
  long long int res[n];
  for (int i = 0; i < n ;i++) {
    res[i] = (long long int)(EPS + pow((long double)10.00, log_sum - (long double)log10(arr[i])));
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

  bonus_inefficient(arr, n);

  bonus_efficient(arr, n);

  op_solution(arr, n);

  return 0;
}