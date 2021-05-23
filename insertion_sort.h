#ifndef SORTALGORITHMS_INSERTION_SORT_H
#define SORTALGORITHMS_INSERTION_SORT_H

#include "algorithm_interface.h"

namespace algorithm_ns
{
    class InsertionSort : public AlgorithmInterface
    {
    public:
        InsertionSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;
    };
}

#endif //SORTALGORITHMS_INSERTION_SORT_H
