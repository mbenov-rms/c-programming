#include <stdio.h>
#include <string.h>

// Helper function to split the code
int find_most_common(int *array, unsigned int size) {
  // Helper variables to track the most common value
  int most_common = array[0];
  int most_occurances = 1;
  
  // size - most_occurances because if less than most_occurances items remain
  // then none of them can beat the current most common
  for(int i = 0; i < size - most_occurances; i++) {
    int curr_item = array[i];
    int curr_occurances = 1;
    
    // Search all reamaining items to the right
    for(int j = i + 1; j < size; j++) {
      if(array[j] == curr_item) curr_occurances++;
    }
    
    // Update the most common value if we found a new one
    if(curr_occurances > most_occurances) {
      most_common = curr_item;
      most_occurances = curr_occurances;
    }
  }
  
  return most_common;
}

void sort_most_common(int *array, unsigned int size) {
  int most_common = find_most_common(array, size);
  
  /*
  // Option 1 - use a front-to-back index to iterate all items and a back-to-front 
  // index to track the last position that doesn't have a most_common value
  // This DOES NOT preserve the order of items
  int bf = size - 1;
  // In case the array ends with one or more most_common find where they end
  while(array[bf] == most_common) bf--;
  
  // Iterate all elements except the list of most_common at the end
  for(int fb = 0; fb < bf; fb++) {
    if(array[fb] == most_common) {
      // Swap
      int c = array[fb];
      array[fb] = array[bf];
      array[bf] = c;
      // Move the back-to-front index to the new last free position
      bf--;
    }
  }*/
  
  // Option 2 - use a temporary lsit of items to help store the correct order
  // This WILL preserve the order of items
  int buffer[size];
  int buffer_index = 0;
  for(int i = 0; i < size; i++) {
    // Move all items that are not most_common to the buffer in the same order as they appear
    if(array[i] != most_common) {
      buffer[buffer_index] = array[i];
      buffer_index++;
    }
  }
  
  // Fill all remaining positions with most_common
  for(int i = buffer_index; i < size; i++) {
    buffer[i] = most_common;
  }
  
  // Copy back to the original array
  memcpy(array, buffer, sizeof(int) * size);
}

void print_array(int *array, unsigned int size) {
  for(int i = 0; i < size; i++)
    printf("%d ", array[i]);
  
  puts("");
}

int main() {
  int arr1[] = {1, 3, 5, 3, 7};
  int arr2[] = {3, 4, 2, 4, 3};
  
  sort_most_common(arr1, 5);
  sort_most_common(arr2, 5);
  
  print_array(arr1, 5);
  print_array(arr2, 5);
  
  return 0;
}
