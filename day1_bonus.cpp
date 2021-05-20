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
  unordered_set<int> s;
  for (int i = 0; i < n; i++) {
    int temp = k - arr[i];
    if (s.find(temp) != s.end()) {
      cout << "True" << endl;
      return 0;
    }
    s.insert(arr[i]);
  }
  return 0;
}