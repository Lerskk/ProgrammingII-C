#include <stdio.h>
#include <stdlib.h>

void bubble_sort(float arreglo[], int longitud) {
  for (int i = 0; i < longitud - 1; i++) {
    for (int j = 0; j < longitud - i - 1; j++) {
      if (arreglo[j] > arreglo[j + 1]) {
        float aux = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = aux;
      }
    }
  }
}

float median(float arr[], int length) {
  float newArr[length];

  for (int i; i < length; i++)
    newArr[i] = arr[i];

  bubble_sort(newArr, length);

  if (length % 2 != 0)
    return newArr[(length - 1) / 2];
  return (newArr[(length / 2) - 1] + newArr[length / 2]) / 2;
}

int main() {
  float arr[] = {3.0, 2.2, 2.4, 2.3};
  int length = sizeof(arr) / sizeof(arr[0]);
  printf("%.2f\n", median(arr, length));
  return 0;
}
