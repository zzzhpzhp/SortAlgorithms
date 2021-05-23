#ifndef SORTALGORITHM_RADIX_SORT_H
#define SORTALGORITHM_RADIX_SORT_H

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

#endif //SORTALGORITHM_RADIX_SORT_H
