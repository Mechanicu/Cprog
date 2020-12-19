#include <iostream>
#include <fstream>
#include <cinttypes>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <initializer_list>
#include <vector>
#include <string>

using namespace std;
using namespace chrono;

#include "sort.h"

template <typename value_type = RecordType>
class benchmark final
{
private:
    //sort_algo是一种函数指针类型的别名
    using sort_algo_t = void (*)(value_type[], int);

    struct alignas(int64_t) sort_algo_info //算法信息表项类型
    {
        const char *algo_name; //排序算法名
        sort_algo_t sort;   //排序算法（指针，指向排序函数）
        int64_t duration = 0; //时间耗费
    };

    vector<sort_algo_info> algos; //算法信息表

    //测试数据的总字节数(len)、数目(num)和存储数据的缓冲区(origin)
    int len, num;
    value_type *origin;

public:
    benchmark(initializer_list<sort_algo_info> list)
    {
        for (auto &e : list)
            algos.push_back(e); //初始化算法信息表

        //从文件里读出测试数据
        ifstream f("data/test.data");
        f.seekg(0, f.end);  //将文件内部指针从头移动到尾部
        len = f.tellg();    //获取文件内部指针移动的字节数，即是文件的大小
        num = len / sizeof(KeyType); //计算测试数据的数量。注意，第一个单元的值是真正测试数据的数目。
        origin = new value_type[num]; //分配缓冲区的存储空间
        f.seekg(0, f.beg);            //文件内部指针卷绕回到头部
        f.read(reinterpret_cast<char *>(origin), len); //读取整个文件的数据
        f.close();
    }
    ~benchmark()
    {
        delete[] origin;
    }

    void launch()
    {
        ofstream f;

        cout << "Benchmarking Sorting Algorithms. Dataset: " << origin[0].key << " 16-bit unsigned integers." << endl;
        cout << "Sorting..." << endl << endl;

        value_type *r = new value_type[num]; //分配工作单元，保存待排序的数据
        for (auto &a : algos) //遍历算法信息表
        {
            memcpy(r, origin, len); //将原始数据复制到工作单元中

            auto start = steady_clock::now();
            a.sort(r, r[0].key); //r[0].key是测试数据的数量。真正的数据从r[1]开始
            auto end = steady_clock::now();
            a.duration = duration_cast<microseconds>(end - start).count();

            f.open(string(a.algo_name) + ".sorted");
            for (int i = 1; i <= len / 10; ++i) f << r[i].key << ' ';
            f.close();
        }

        delete[] r;
    }

    void summary()
    {
        size_t i, j, n = algos.size();

        //对结果进行排序
        for (i = 0; i < n - 1; ++i)
            for (j = 0; j < n - i - 1; ++j)
                if (algos[j].duration > algos[j + 1].duration)
                    swap(algos[j], algos[j + 1]);

        int64_t max = algos[algos.size() - 1].duration;
        int64_t k;
        double score;

        cout << "======== Performance ========" << endl;
        for (auto &algo : algos)
        {
            score = max * 1.0 / algo.duration; //一个简单的计算某种排序算法性能得分的方法
            k = int64_t(score) + 1; //要显示的*的数目
            if (k > 100) k /= 5; //如果太多，就缩减到一行能够显示的数量
            cout << setfill(' ') << setw(9) << algo.algo_name << ":" << setw(8) << algo.duration << " mms |";
            cout << setfill('*') << setw(k) << ' ' << fixed << setprecision(2) << score << endl;
        }
    }
};

int main()
{
    benchmark<> b({
        //insertion
        // {"Insertion", InsSort}
        // ,
        // {"Binary", BinSort}
        // ,
        // {"Shell", ShellSort}
        // ,
        //swap
        // {"Bubble", BubbleSort}
        // ,
        // {"Quick", QuickSort}
        // ,
        //selection
        // {"Selection", SelectSort}
        // ,
        // {"Heap", HeapSort}
        // ,
        //merging
        //注意：因为归并算法在运行时，需要反复申请额外的存储空间，所以可能造成内存耗费过大而跑不动。
        //建议在测试时，用少量的数据。这可以通过运行data目录下的gen_data工具来生成测试数据。
        //用法：gen_data <data_num>
        {"Merging", MergeSort},
        {"Merging2", MergeSort2}
        //,
        // //distribution
        // {"Radix", RadixSort}
    });

    b.launch();
    b.summary();

    return 0;
}