#ifndef SORTALGORITHMS_RADIX_SORT_H
#define SORTALGORITHMS_RADIX_SORT_H

#include "algorithm_interface.h"

namespace algorithm_ns
{
    class RadixSort : public AlgorithmInterface
    {
    public:
        RadixSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;
    };
}

#endif //SORTALGORITHMS_RADIX_SORT_H
