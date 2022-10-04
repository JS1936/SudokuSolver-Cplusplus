/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "problem_3/sudoku.h"

int expect_val(int v) {
    return v * 2;
}

// uncomment the following to print out the board, for debugging
// #define PRINT_SUDOKU

void assert_solution(int *challenge, int *solution, int rows, int cols) {
    const testing::TestInfo *const test_info =
            testing::UnitTest::GetInstance()->current_test_info();
    SudokuLocator locator(rows, cols);
    Sudoku sudoku(challenge, locator);

#ifdef PRINT_SUDOKU
    sudoku.print();
#endif

    std::string failure_msg = "Test Case '" + std::string(test_info->name()) + "' has failed :(";
    ASSERT_TRUE(sudoku.solve()) << failure_msg;

    ASSERT_TRUE(sudoku == solution) << failure_msg;
}