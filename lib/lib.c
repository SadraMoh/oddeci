int largest(int arr[], int len) {

  int l = arr[0];

  for (int i = 0; i < len; i++) 
    if (arr[i] > l) 
      l = arr[i];

  return l;
  
}