// This problem was asked by Stripe.

// Given an array of integers, find the first missing positive integer in linear time and constant space.
// In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

// For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

// You can modify the input array in-place.

// Naive solution is too unoptimized, so won't do it.

#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  heapSort(arr, n);

  // checking for 1
  bool absent_1 = true;
  for (int  i = 0; i < n; i++) {
    if (arr[i] == 1) {
      absent_1 = false;
    }
  }
  if (absent_1) {
    cout << "1" << endl;
    return 0;
  }

  // 1 is present, checking for gaps
  for (int i = 0; i < n - 1 ; i++) {
    if ((arr[i + 1] - arr[i] > 1) && (arr[i] > 0)) {
      cout << (arr[i] + 1) << endl;
      return 0;
    }
  }

  // no gaps. next number of array last element will be answer
  cout << (arr[n - 1] + 1) << endl;

  return 0;
}