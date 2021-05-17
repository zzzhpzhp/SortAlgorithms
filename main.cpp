#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>

#include "algorithm_interface.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "shell_sort.h"

std::vector<int> nums;
std::vector<std::shared_ptr<algorithm_ns::AlgorithmInterface>> algorithms_ptr;


int main()
{
    std::default_random_engine rd;
    rd.seed(time(0));

    for (int i = 0; i < 100; i++)
    {
        nums.emplace_back(rd() % 1000);
    }

    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::BubbleSort>("BubbleSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::SelectionSort>("SelectionSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::InsertionSort>("InsertionSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::ShellSort>("ShellSort", nums));

    for (auto &alg : algorithms_ptr)
    {
        std::cout << alg->getName() << std::endl;
        alg->sort();
        alg->printNums();

        alg->check();
    }

    return 0;
}
