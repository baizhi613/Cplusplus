#include <iostream> // 引入标准输入输出流库
using namespace std; // 使用标准命名空间

const int N=1e6+10; // 定义常量N，表示数组的最大容量，1e6+10即1000000+10
int n; // 定义变量n，用于存储待排序元素的数量
int q[N]; // 定义整型数组q，用于存储待排序的元素

// 快速排序函数
void quick_sort(int q[], int l, int r) {
    // 如果左边界索引大于等于右边界索引，说明子数组已经有序，直接返回
    if(l >= r) return;

    // 选择子数组的中间元素作为基准
    int x = q[(l+r)/2];
    // 初始化两个指针，i指向左边界的前一个位置，j指向右边界后一个位置
    int i = l - 1, j = r + 1;

    // 当i和j没有相遇时，继续循环
    while(i < j) {
        // 从左向右移动i，直到找到一个大于等于基准的元素
        do {
            i++;
        } while (q[i] < x);

        // 从右向左移动j，直到找到一个小于等于基准的元素
        do {
            j--;
        } while (q[j] > x);

        // 如果i和j没有相遇，交换它们指向的元素
        if(i < j) swap(q[i], q[j]);
    }

    // 递归地对基准左侧的子数组进行快速排序
    quick_sort(q, l, j);
    // 递归地对基准右侧的子数组进行快速排序
    quick_sort(q, j + 1, r);
}

int main() {
    // 从标准输入读取元素数量
    scanf("%d", &n);
    // 从标准输入读取待排序的元素
    for(int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    // 调用快速排序函数对数组进行排序
    quick_sort(q, 0, n - 1);
    // 将排序后的数组输出到标准输出
    for(int i = 0; i < n; i++) {
        printf("%d ", q[i]);
    }
    // 程序结束，返回0
    return 0;
}
