#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <stdarg.h>

#define check(M) fprintf(stderr, "(%s:%d)" M "\n", __FILE__, __LINE__);
#define check_mem(A)                                                           \
  if (!A) {                                                                    \
    check("Out of memory");                                                    \
  }

std::chrono::system_clock::time_point(*now);

template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// insertionsort(data[],n):
//    for i = 1 to n-1:
//       move all elements data[j] greater than data[i] by one position;
//       place data[i] in its proper position;

template <typename T> void insertion_sort(T arr[], int n) {
  int writing_count = 0;
  for (int i = 1, j; i < n; i++) {
    // store ihe current item in temp cause it may
    // change while sorting
    T tmp = arr[i];
    for (j = i; j > 0 && tmp < arr[j - 1]; j--) {
      ++writing_count;
      arr[j] = arr[j - 1];
    }
    // put temp in the right position
    if (i != j) {
      arr[j] = tmp;
    }
  }

  std::cout << " Writing count: " << writing_count << std::endl;
}

// selectionsort(data[],n)
//    for i = 0 to n-2
//       select the smallest element among data[i], . . . , data[n-1];
//       swap it with data[i];

template <typename T> void selection_sort(T arr[], int n) {
  int writing_count = 0;
  for (int i = 0, least, k; i < n - 1; i++) {
    for (k = i + 1, least = i; k < n; k++) {
      writing_count++;
      if (arr[k] < arr[least]) {
        least = k;
      }
    }
    swap(arr[least], arr[i]);
  }
  std::cout << " Writing count: " << writing_count << std::endl;
}

template <typename T> void bubble_sort(T arr[], int n) {
  int writing_count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; --j) {
      writing_count++;
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  std::cout << " Writing count: " << writing_count << std::endl;
}

template <typename T> void shell_sort(T arr[], int n) {
  for (int difference = n / 2; difference > 0; difference /= 2) {
    // setting the gap sequence from n / 2 to 1
    // from now on it is same as insertion sort
    for (int i = difference; i < n; i++) {
      int tmp = arr[i];
      int j;
      for (j = i; j >= difference && tmp < arr[j - difference];
           j -= difference) {
        arr[j] = arr[j - difference];
      }
      if (i != j) {
        arr[j] = tmp;
      }
    }
  }
}

template <typename T> void shell_sort_gap(T arr[], int n) {
  int writing_count = 0;
  int gaps[20];
  int gap_count = 1;
  gaps[0] = 1;
  for (int i = 1;; i++) {
    int gap = pow(4, i) + 3 * pow(2, i - 1) + 1;
    if (gap >= n) {
      break;
    }
    gaps[i] = gap;
    ++gap_count;
  }
  for (int c = gap_count - 1; c >= 0; c--) {
    int difference = gaps[c];
    for (int i = difference; i < n; i += 1) {
      int tmp = arr[i];
      int j;
      for (j = i; j >= difference && tmp < arr[j - difference];
           j -= difference) {
        arr[j] = arr[j - difference];
        writing_count++;
      }
      if (i != j) {
        arr[j] = tmp;
      }
    }
  }
}

void quick_sort(int arr[], int n) {
  struct index {
    int l, right;
  };
  std::stack<index> s;
  s.push(index{0, n - 1});
  while (!s.empty()) {
    index ind = s.top();
    s.pop();
    // taking the left most element as pivot
    int lower = ind.l, upper = ind.right;
    std::cout << "Partition: "
              << " ";
    for (int i = lower; i <= upper; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int pivot = arr[ind.l];
    while (lower <= upper) {
      while (pivot > arr[lower]) {
        lower++;
      }
      while (pivot < arr[upper]) {
        upper--;
      }
      if (lower <= upper) {
        swap(arr[lower++], arr[upper--]);
      }
    }
    if (ind.l < upper) {
      s.push(index{ind.l, upper});
    }
    if (ind.right > lower) {
      s.push(index{lower, ind.right});
    }
  }
}

void quick_sort_single(int arr[], int n) {
  struct partition {
    int left, right;
  };
  std::stack<partition> s;

  s.push(partition{0, n - 1});

  while (!s.empty()) {

    partition p = s.top();
    s.pop();

    int pivot = arr[p.left];

    int storeIndex = p.left + 1;
    for (int i = p.left + 1; i <= p.right; i++) {

      if (arr[i] < pivot) {
        swap(arr[storeIndex], arr[i]);
        storeIndex++;
      }
    }

    int newPivotIndex = storeIndex - 1;
    swap(arr[p.left], arr[newPivotIndex]);

    if (p.left < (newPivotIndex - 1)) {
      s.push(partition{p.left, newPivotIndex - 1});
    }
    if (p.right > (newPivotIndex + 1)) {
      s.push(partition{newPivotIndex + 1, p.right});
    }
  }
}

void radix_sort(int arr[], int n) {
  std::queue<int> q[10]{};
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    max = max > arr[i] ? max : arr[i];
  }
  int max_count = std::log10(max) + 1;
  for (int i = 0; i < max_count; i++) {
    for (int j = 0; j < n; j++) {
      int index = arr[i] % 10;
      q[index].push(arr[i]);
      arr[i] /= 10;
    }
    for (int i = 0; i < 10; i++) {
      int index = 0;
      while (!(q[i].empty())) {
        arr[index++] = q[i].front();
        q[i].pop();
      }
    }
  }
}

void merge(int arr[], int start, int end) {
  int middle = (start + end) >> 1;

  int k = 0, f = start, s = middle + 1;

  int temp[end - start + 1];

  while (f <= middle && s <= end) {

    if (arr[f] < arr[s]) {
      temp[k++] = arr[f++];
    } else {
      temp[k++] = arr[s++];
    }
  }

  while (f <= middle) {
    temp[k++] = arr[f++];
  }
  while (s <= end) {
    temp[k++] = arr[s++];
  }

  int putIndex = start;
  for (int i = 0; i < (end - start + 1); i++) {
    arr[putIndex++] = temp[i];
  }
}

void merge_sort_helper(int arr[], int start, int end) {
  if (start < end) {
    int middle = (start + end) / 2;
    std::cout << "Hello" << std::endl;
    // split the array into two parts
    merge_sort_helper(arr, start, middle);
    merge_sort_helper(arr, middle + 1, end);

    merge(arr, start, end);
  }
}

void merge_sort_rec(int arr[], int n) { merge_sort_helper(arr, 0, n - 1); }

void merge_sort(int arr[], int n) {
  int temp[n];
  int divisions[20];
  for (int i = n / 2; i > 0; i++) {
  }
  for (int i = 1; i < n; i *= 2) {
    for (int j = 0; (j + 2 * i) <= n; j += 2 * i) {
      int l = j;
      int r = j + i;
      int k = j;
      while (l < j + i && r < j + 2 * i) {
        if (arr[l] < arr[r]) {
          temp[k] = arr[l];
          l++;
        } else {
          temp[k] = arr[r];
          r++;
        }
        k++;
      }
      while (l < j + i) {
        temp[k] = arr[l];
        k++;
        l++;
      }
      while (r < j + 2 * i) {
        temp[k] = arr[r];
        k++;
        r++;
      }
    }
    for (int i = 0; i < n; i++) {
      arr[i] = temp[i];
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
}

bool is_sorted(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int arr[10] = {10, 3, 12, 2, 16, 21, 1, 34, 1, 31};
  quick_sort(arr, 10);
  for (int i = 0; i < 10; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
