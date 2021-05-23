#ifndef SORTALGORITHMS_HEAP_SORT_H
#define SORTALGORITHMS_HEAP_SORT_H

#include "algorithm_interface.h"
#include <memory>

namespace algorithm_ns
{
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

#endif //SORTALGORITHMS_HEAP_SORT_H
