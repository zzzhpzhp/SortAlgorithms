#ifndef SORTALGORITHMS_BUBBLE_SORT_H
#define SORTALGORITHMS_BUBBLE_SORT_H

#include "algorithm_interface.h"

namespace algorithm_ns
{
    class BubbleSort : public AlgorithmInterface
    {
    public:
        BubbleSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;
    };
}

#endif //SORTALGORITHMS_BUBBLE_SORT_H
