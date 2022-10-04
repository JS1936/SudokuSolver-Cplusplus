/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "problem_3/sudoku_locator.h"

TEST(sudoku_locator, null_data_input) {
    SudokuLocator locator(2, 3);
    std::vector<std::pair<size_t, size_t>> test_cases{
            std::pair{0, 1},
            std::pair{1, 0},
            std::pair{0, 0},
            std::pair{2, 4},
            std::pair{4, 2},
    };
    for (auto test_case: test_cases) {
        ASSERT_EQ(nullptr, locator.locate(nullptr, test_case.first, test_case.second));
    }
}

TEST(sudoku_locator, out_of_bound) {
    SudokuLocator locator_1(0, 0);

    int *data = new int[5];
    ASSERT_THROW(locator_1.locate(data, 1, 2), std::out_of_range);
    delete[] data;

    SudokuLocator locator_2(2, 3);
    data = new int[6];
    std::vector<std::pair<size_t, size_t>> test_cases{
            std::pair{3, 3},
            std::pair{3, 2},
            std::pair{2, 4},
            std::pair{1, 4},
    };
    for (auto test_case: test_cases) {
        ASSERT_THROW(locator_2.locate(data, test_case.first, test_case.second), std::out_of_range);
    }
    delete[] data;
}

TEST(sudoku_locator, normal_range) {
    size_t rows = 2, cols = 3;
    SudokuLocator locator(rows, cols);
    int *data = new int[6]{0, 2, 4, 6, 8, 10};
    int val = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int expect = (val++) * 2;
            ASSERT_EQ(expect, *locator.locate(data, i, j));
        }
    }
    delete[] data;
}