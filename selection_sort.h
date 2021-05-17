#ifndef SORTALGORITHM_SELECTION_SORT_H
#define SORTALGORITHM_SELECTION_SORT_H

#include "algorithm_interface.h"

namespace algorithm_ns
{
    class SelectionSort : public AlgorithmInterface
    {
    public:
        SelectionSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;
    };
}

#endif //SORTALGORITHM_SELECTION_SORT_H
