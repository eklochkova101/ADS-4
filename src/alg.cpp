// Copyright 2021 NNTU-CS
size_t binSearch(int* arr, int target, int leftBound, int rightBound);
int countPairs1(int *arr, int len, int value) {
  size_t counter = 0, i = 0, j;
  while (i < len - 1) {
    for (j = i + 1; j < len; j++) counter += (arr[i] + arr[j] == value);
    i++;
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  size_t i = len - 1, j = 0, counter = 0;
  for (; i > j; ) {
    int sum = arr[i] + arr[j];
    if (sum == value) {
      if (arr[i] == arr[j]) {
        counter += (i - j + 1) * (i - j) / 2;
        break;
      }
      else {
        size_t iCntr = 0; int i_value = arr[i];
        while (i >= j && arr[i] == i_value) {
          iCntr++;
          i--;
        }
        size_t jCntr = 0; int j_value = arr[j];
        while (i >= j && arr[j] == j_value) {
          jCntr++;
          j++;
        }
        counter += jCntr * iCntr;
      }
    }
    else if (sum > value) i--;
    else j++;
  }
  return counter;
}
int countPairs3(int *arr, int len, int value) {
  size_t counter = 0;
  for (size_t i = 0; i < len - 1; i++) {
    if (arr[i] > value) break;
    int foundVal = value - arr[i];
    counter += (binSearch(arr, foundVal, i + 1, len - 1));
  }
  return counter;
}
size_t binSearch(int* arr, int target, int leftBound, int rightBound) {
  if (leftBound > rightBound) return 0;
  if (arr[(leftBound + rightBound) / 2] == target) {
    return 1 + binSearch(arr, target, leftBound, (leftBound + rightBound) / 2 - 1) + binSearch(arr, target, (leftBound + rightBound) / 2 + 1, rightBound);
  }
  else if (arr[(leftBound + rightBound) / 2] > target) return binSearch(arr, target, leftBound, (leftBound + rightBound) / 2 - 1);
  else return binSearch(arr, target, ((leftBound + rightBound) / 2 + 1), rightBound);
}
