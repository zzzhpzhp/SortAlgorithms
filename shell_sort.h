#ifndef SORTALGORITHM_SHELL_SORT_H
#define SORTALGORITHM_SHELL_SORT_H

#include "algorithm_interface.h"

namespace algorithm_ns
{
    class ShellSort : public AlgorithmInterface
    {
    public:
        ShellSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;
    };
}

#endif //SORTALGORITHM_SHELL_SORT_H
