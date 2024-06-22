// *******************************************************
// *  工 程 名：101.dsp 	              		  		 *
// *  程 序 名：101.cpp 	              		  		 *
// *  主要功能：排序算法以及分治算法		  			 *
// *  学号姓名：20221113242刘一山                  	     *
// *  编制时间：2023年10月31日             		  		 *
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
// *  工 程 名：102.dsp 	              		  		 *
// *  程 序 名：102.cpp 	              		  		 *
// *  主要功能：排序算法以及分治算法		  			 *
// *  学号姓名：20221113242刘一山                  	     *
// *  编制时间：2023年10月31日             		  		 *
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
// *  工 程 名：103.dsp 	              		  		 *
// *  程 序 名：103.cpp 	              		  		 *
// *  主要功能：排序算法以及分治算法		  			 *
// *  学号姓名：20221113242刘一山                  	     *
// *  编制时间：2023年10月31日             		  		 *
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
// *  工 程 名：104.dsp 	              		  		 *
// *  程 序 名：104.cpp 	              		  		 *
// *  主要功能：排序算法以及分治算法		  			 *
// *  学号姓名：20221113242刘一山                  	     *
// *  编制时间：2023年10月31日             		  		 *
// ********************************************************
//#include <iostream>
//using namespace std;
//
//void Merge(int a[], int p, int q, int r) {
//    int x = q - p + 1; // 元素数目
//    int y = r - q;
//    int B[x], C[y]; // 创建临时数组 B 和 C
//    for (int i = 0; i < x; i++)
//        B[i] = a[p + i]; // 将 A[p..q] 复制到 B[0..x-1]
//    for (int i = 0; i < y; i++)
//        C[i] = a[q + 1 + i]; // 将 A[q+1..r] 复制到 C[0..y-1]
//    int i = 0, j = 0, k = p; // 初始化索引
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

