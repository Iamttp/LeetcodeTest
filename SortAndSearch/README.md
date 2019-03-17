# 排序和搜索

！！！对于二分查找的边界问题，暂时不太确定。

参考：`https://blog.csdn.net/yefengzhichen/article/details/52372407`

* 在有序数组中查找某个数，找到返回数的下标，存在多个返回任意一个即可，没有返回-1。所有程序采用左右均为闭区间，即函数中n为最后一个元素下标，而不是元素个数。典型代码如下：

```cpp
public int binarySearch(int[] a, int n, int key)
{
  //n + 1 个数
  int low = 0;
  int high = n;
  int mid = 0;
  while (low <= high)
  {
    mid = low + ((high - low) >> 1);
    if (key == a[mid])
    {
      return mid;
    }
    else if (key < a[mid])
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
}
```