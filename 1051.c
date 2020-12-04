void merge(int arr[], int lo, int mid, int hi) {
    int i, j, k;
    int lSize = mid - lo + 1;
    int rSize = hi - mid;

    // temp arrays to hold subarrays
    int L[lSize], R[rSize];

    // copy data into temp arrays
    for (i = 0; i < lSize; i++) {
      L[i] = arr[lo + i];
    }

    for (j = 0; j < rSize; j++) {
      R[j] = arr[mid + 1 + j];
    }

    // merge temp arrays
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = lo; // Initial index of merged subarray
    while (i < lSize && j < rSize) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of L[]
    while (i < lSize) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy remaining elements of R[]
    while (j < rSize) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lo, int hi) {

    if (lo < hi) {

      //stores the middle index of the array
      int mid = (lo + hi) / 2;

      //divide up the left half of the array
      mergeSort(arr, lo, mid);

      //divide up the right half of the array
      mergeSort(arr, mid + 1, hi);

      //merge and sort the two halves
      merge(arr, lo, mid, hi);
    }
}

int heightChecker(int* heights, int heightsSize){

    // create array to keep the sorted heights
    int sortedHeights[heightsSize];

    // copy values over
    for(int i=0; i<heightsSize; i++) {
        sortedHeights[i] = heights[i];
    }

    // sort heights
    mergeSort(sortedHeights, 0, heightsSize - 1);

    // compare sorted to original array to see how many spots changed

    int diff = 0;
    for(int i=0; i<heightsSize; i++) {
        if(heights[i] != sortedHeights[i]) {
            diff++;
        }
    }

    return diff;
}
