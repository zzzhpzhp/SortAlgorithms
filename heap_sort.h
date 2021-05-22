#ifndef SORTALGORITHM_HEAP_SORT_H
#define SORTALGORITHM_HEAP_SORT_H

#include "algorithm_interface.h"
#include <memory>

namespace algorithm_ns
{
    struct Heap
    {
        explicit Heap(int v)
        {
            val = v;
        }
        int val;
        std::shared_ptr<Heap> left, right;
    };

    class HeapSort : public AlgorithmInterface
    {
    public:
        HeapSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;

    private:

        int end_index_ = 0;

        void
        _heap_init();

        void
        _heap_adjust(int i);
    };
}

#endif //SORTALGORITHM_HEAP_SORT_H
