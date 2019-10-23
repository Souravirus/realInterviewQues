#include<bits/stdc++.h>
#define mp make_pair
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
#define mod 1000000007
using namespace std;

void max_heapify(int arr[], int i, int k){
  int left = 2*i;
  int right = 2*i + 1;
  int largest;
  if(left < k && arr[left] > arr[i]){
    largest = left;
  }

  else
    largest = i;

  if(right < k && arr[right] > arr[i]){
    largest = right;
  }

  if(largest != i){
    std::swap(arr[i], arr[largest]);
    max_heapify(arr, largest, k);
  }
}
int max_heap(int arr[], int n, int k){
  for(int i = k/2-1; i >= 0; i--){
    max_heapify(arr, i, k);
  }

  for(int i = k; i < n; i++){
    if(arr[0] > arr[i]){
      arr[0] = arr[i];
      max_heapify(arr, 0, k);
    }
  }

  return arr[0];
}
int kthSmallest(int arr[], int n, int k){
  return max_heap(arr,n, k); 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cout << kthSmallest(arr, n, k) << endl;
	return 0;
}
//Hi there Sourav Sahoo please use lli instead of int
