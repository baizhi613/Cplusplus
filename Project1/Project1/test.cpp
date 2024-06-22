// *******************************************************
// *  �� �� ����101.dsp 	              		  		 *
// *  �� �� ����101.cpp 	              		  		 *
// *  ��Ҫ���ܣ������㷨�Լ������㷨		  			 *
// *  ѧ��������20221113242��һɽ                  	     *
// *  ����ʱ�䣺2023��10��31��             		  		 *
// ********************************************************
//#include <iostream>
//using namespace std;
//void Selection(int a[], int n)
//{
//    int temp = 0;
//    int k, i, j;
//    for (i = 0; i < n - 1; i++)
//    {
//        k = i;
//        for (j = i + 1; j < n; j++)
//        {
//            if (a[j] < a[k])
//            {
//                k = j;
//            }
//        }
//        if (k != i)
//        {
//            temp = a[i];
//            a[i] = a[k];
//            a[k] = temp;
//        }
//    }
//}
//int main() {
//    int a[] = { 5,2,4,8,3,1,7,6,9,10 };
//    int n = sizeof(a) / sizeof(a[0]);
//    Selection(a, n);
//    for (int i = 0; i < n; i++)
//    {
//        cout << a[i] << " ";
//    }
//    return 0;
//}
// 
// *******************************************************
// *  �� �� ����102.dsp 	              		  		 *
// *  �� �� ����102.cpp 	              		  		 *
// *  ��Ҫ���ܣ������㷨�Լ������㷨		  			 *
// *  ѧ��������20221113242��һɽ                  	     *
// *  ����ʱ�䣺2023��10��31��             		  		 *
// ********************************************************
//#include <iostream>
//using namespace std;
//void Insertionsort(int a[], int n)
//{
//    int j = 0, i = 0,key=0;
//    for (j = 0; j <n-1; j++)
//    {
//         int i = j;
//         int key = a[j + 1];
//         while (i >= 0 && a[i] > key)
//         {
//             a[i + 1] = a[i];
//             --i;
//         }
//         a[i + 1] = key;
//    }
//}
//
//int main()
//{
//    int a[] = { 5,2,4,8,3,1,7,6,9,10 };
//    int n = sizeof(a) / sizeof(a[0]);
//    Insertionsort(a, n);
//    for (int i = 0; i < n; i++)
//    {
//        cout << a[i] << " ";
//    }
//    return 0;
//}

// *******************************************************
// *  �� �� ����103.dsp 	              		  		 *
// *  �� �� ����103.cpp 	              		  		 *
// *  ��Ҫ���ܣ������㷨�Լ������㷨		  			 *
// *  ѧ��������20221113242��һɽ                  	     *
// *  ����ʱ�䣺2023��10��31��             		  		 *
// ********************************************************
//#include <iostream>
//using namespace std;
//
//int Split(int a[], int low, int high) {
//    int temp1 = 0, temp2 = 0, w = 0;
//    int i = low;
//    int x = a[low];
//    for (int j = low + 1; j <= high; j++) {
//        if (a[j] <= x) {
//            i++;
//            if (i != j) {
//                temp1 = a[i];
//                a[i] = a[j];
//                a[j] = temp1;
//            }
//        }
//    }
//    if (low != i) {
//        temp2 = a[low];
//        a[low] = a[i];
//        a[i] = temp2;
//    }
//    w = i;
//    return w;
//}
//
//void Quicksort(int a[], int low, int high) {
//    int w = 0;
//    if (low < high) {
//        w = Split(a, low, high);
//        Quicksort(a, low, w - 1);
//        Quicksort(a, w + 1, high);
//    }
//}
//
//int main() {
//    int a[] = { 5, 2, 4, 8, 3, 1, 7, 6, 9, 10 };
//    int n = sizeof(a) / sizeof(a[0]);
//    int low = 0;
//    int high = n - 1;
//    Quicksort(a, low, high);
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    return 0;
//}

// *******************************************************
// *  �� �� ����104.dsp 	              		  		 *
// *  �� �� ����104.cpp 	              		  		 *
// *  ��Ҫ���ܣ������㷨�Լ������㷨		  			 *
// *  ѧ��������20221113242��һɽ                  	     *
// *  ����ʱ�䣺2023��10��31��             		  		 *
// ********************************************************
//#include <iostream>
//using namespace std;
//
//void Merge(int a[], int p, int q, int r) {
//    int x = q - p + 1; // Ԫ����Ŀ
//    int y = r - q;
//    int B[x], C[y]; // ������ʱ���� B �� C
//    for (int i = 0; i < x; i++)
//        B[i] = a[p + i]; // �� A[p..q] ���Ƶ� B[0..x-1]
//    for (int i = 0; i < y; i++)
//        C[i] = a[q + 1 + i]; // �� A[q+1..r] ���Ƶ� C[0..y-1]
//    int i = 0, j = 0, k = p; // ��ʼ������
//    while (i < x && j < y) {
//        if (B[i] <= C[j]) {
//            a[k] = B[i];
//            i++;
//        }
//        else {
//            a[k] = C[j];
//            j++;
//        }
//        k++;
//    }
//    while (i < x) {
//        a[k] = B[i];
//        i++;
//        k++;
//    }
//    while (j < y) {
//        a[k] = C[j];
//        j++;
//        k++;
//    }
//}
//
//void MergeSort(int a[], int p, int r) {
//    if (p < r) {
//        int q = (p + r) / 2;
//        MergeSort(a, p, q);
//        MergeSort(a, q + 1, r);
//        Merge(a, p, q, r);
//    }
//}
//
//int main() {
//    int a[] = { 5, 2, 4, 8, 3, 1, 7, 6, 9, 10 };
//    int n = sizeof(a) / sizeof(a[0]);
//    MergeSort(a, 0, n - 1);
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    return 0;
//}

