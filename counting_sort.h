#ifndef SORTALGORITHMS_COUNTING_SORT_H
#define SORTALGORITHMS_COUNTING_SORT_H

#include "algorithm_interface.h"

#include <unordered_map>

namespace algorithm_ns
{
    class CountingSort : public AlgorithmInterface
    {
    public:
        CountingSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void sort() override;

    private:
        std::unordered_map<int, int> bucket_;
    };
}

#endif //SORTALGORITHMS_COUNTING_SORT_H
