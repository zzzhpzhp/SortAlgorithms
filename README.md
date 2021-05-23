# 介绍
十大经典排序算法的实现：快速排序、堆排序、希尔排序、插入排序、冒泡排序、选择排序、归并排序、计数排序、桶排序、基数排序。  
# 说明
自动生成10000个在0-9999之间的随机数，为每个算法创建一个线程对这些数进行排序，最后打印每种算法完成排序所需的时间。
# 依赖安装
```bash
sudo apt-get install build-essential cmake
```
# 编译与运行
```bash
mkdir build
cd build
cmake ..
make -j
./SortAlgorithms
```