#ifndef SORTALGORITHMS_ALGORITHM_INTERFACE_H
#define SORTALGORITHMS_ALGORITHM_INTERFACE_H

#include <iostream>
#include <vector>
#include <string>
#include "assert.h"

namespace algorithm_ns
{
    class AlgorithmInterface
    {
    public:

        virtual void
        initialize(std::string name, std::vector<int> &nums)
        {
            name_ = name;
            nums_ = nums;
        }

        virtual void
        printNums()
        {
            for (const auto &n : nums_)
            {
                std::cout << n << " ";
            }
            std::cout << std::endl;
        }

        virtual std::string
        getName()
        {
            return name_;
        }

        virtual void
        check()
        {
            for (int i = 0; i < nums_.size()-1; i++)
            {
                assert(nums_[i] <= nums_[i + 1]);
            }
        }

        virtual void
        sort() = 0;

    protected:

        std::vector<int> nums_;
        std::string name_;
    };
}

#endif //SORTALGORITHMS_ALGORITHM_INTERFACE_H
