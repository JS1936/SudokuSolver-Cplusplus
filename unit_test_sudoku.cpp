#include "gtest/gtest.h"
#include "unit_test_sudoku.h"

TEST(sudoku, constructor_equal) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int *challenge = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        challenge[i] = expect_val(i);
    }

    SudokuLocator locator(ROWS, COLS);
    Sudoku sudoku(challenge, locator);

    ASSERT_TRUE(sudoku == challenge);
    ASSERT_EQ(sudoku, challenge);
    challenge[0] = 99;
    ASSERT_FALSE(sudoku == challenge);
    delete[] challenge;
}

TEST(sudoku, locator_getter_setter) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int *challenge = new int[SIZE];
    SudokuLocator locator(ROWS, COLS);
    Sudoku sudoku(challenge, locator);

    int val = 0;
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            sudoku(row, col) = expect_val(val++);
        }
    }
    val = 0;
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            ASSERT_EQ(sudoku(row, col), expect_val(val++));
        }
    }
    delete[] challenge;
}

TEST(sudoku, challenge_row_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                           5, 2, 9, 1, 3, 4, 7, 6, 8,
                           4, 8, 7, 6, 2, 9, 5, 3, 1,
                           2, 6, 3, 4, 1, 5, 9, 8, 7,
                           9, 7, 4, 8, 6, 3, 1, 2, 5,
                           8, 5, 1, 7, 9, 2, 6, 4, 3,
                           1, 3, 8, 9, 4, 7, 2, 5, 6,
                           6, 9, 2, 3, 5, 1, 8, 7, 4,
                           7, 4, 5, 2, 8, 6, 3, 1, 9};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, challenge_col_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 2, 9, 1, 3, 4, 7, 6, 8,
                           0, 8, 7, 6, 2, 9, 5, 3, 1,
                           0, 6, 3, 4, 1, 5, 9, 8, 7,
                           0, 7, 4, 8, 6, 3, 1, 2, 5,
                           0, 5, 1, 7, 9, 2, 6, 4, 3,
                           0, 3, 8, 9, 4, 7, 2, 5, 6,
                           0, 9, 2, 3, 5, 1, 8, 7, 4,
                           0, 4, 5, 2, 8, 6, 3, 1, 9};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, challenge_paritial_diag_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;

    int challenge[SIZE] = {0, 1, 6, 5, 7, 8, 4, 9, 2,
                           5, 0, 9, 1, 3, 4, 7, 6, 8,
                           4, 8, 7, 6, 2, 9, 5, 3, 1,
                           2, 6, 3, 4, 1, 5, 9, 8, 7,
                           9, 7, 4, 8, 6, 3, 1, 2, 5,
                           8, 5, 1, 7, 9, 2, 6, 4, 3,
                           1, 3, 8, 9, 4, 7, 2, 5, 6,
                           6, 9, 2, 3, 5, 1, 8, 7, 4,
                           7, 4, 5, 2, 8, 6, 3, 1, 9};
    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

//the whole diagonal is empty //added
//what's missing? (essentially...)
TEST(sudoku, challenge_diag_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {0, 1, 6, 5, 7, 8, 4, 9, 2,
                           5, 0, 9, 1, 3, 4, 7, 6, 8,
                           4, 8, 0, 6, 2, 9, 5, 3, 1,
                           2, 6, 3, 0, 1, 5, 9, 8, 7,
                           9, 7, 4, 8, 0, 3, 1, 2, 5,
                           8, 5, 1, 7, 9, 0, 6, 4, 3,
                           1, 3, 8, 9, 4, 7, 0, 5, 6,
                           6, 9, 2, 3, 5, 1, 8, 0, 4,
                           7, 4, 5, 2, 8, 6, 3, 1, 0};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, challenge_reverse_diag_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 0,
                           5, 2, 9, 1, 3, 4, 7, 0, 8,
                           4, 8, 7, 6, 2, 9, 0, 3, 1,
                           2, 6, 3, 4, 1, 0, 9, 8, 7,
                           9, 7, 4, 8, 0, 3, 1, 2, 5,
                           8, 5, 1, 0, 9, 2, 6, 4, 3,
                           1, 3, 0, 9, 4, 7, 2, 5, 6,
                           6, 0, 2, 3, 5, 1, 8, 7, 4,
                           0, 4, 5, 2, 8, 6, 3, 1, 9};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, real_challenge_1) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {3, 0, 6, 5, 0, 8, 4, 0, 0,
                           5, 2, 0, 0, 0, 0, 0, 0, 0,
                           0, 8, 7, 0, 0, 0, 0, 3, 1,
                           0, 0, 3, 0, 1, 0, 0, 8, 0,
                           9, 0, 0, 8, 6, 3, 0, 0, 5,
                           0, 5, 0, 0, 9, 0, 6, 0, 0,
                           1, 3, 0, 0, 0, 0, 2, 5, 0,
                           0, 0, 0, 0, 0, 0, 0, 7, 4,
                           0, 0, 5, 2, 0, 6, 3, 0, 0};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, real_challenge_2) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {3, 0, 6, 5, 0, 8, 4, 0, 0,
                           5, 2, 0, 0, 0, 0, 0, 0, 0,
                           0, 8, 7, 0, 0, 0, 0, 3, 1,
                           0, 0, 3, 0, 1, 0, 0, 8, 0,
                           9, 0, 0, 8, 6, 3, 0, 0, 5,
                           0, 5, 0, 0, 9, 0, 6, 0, 0,
                           1, 3, 0, 0, 0, 0, 2, 5, 0,
                           0, 0, 0, 0, 0, 0, 0, 7, 4,
                           0, 0, 5, 2, 0, 6, 3, 0, 0};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, real_challenge_3_already_solved) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                           5, 2, 9, 1, 3, 4, 7, 6, 8,
                           4, 8, 7, 6, 2, 9, 5, 3, 1,
                           2, 6, 3, 4, 1, 5, 9, 8, 7,
                           9, 7, 4, 8, 6, 3, 1, 2, 5,
                           8, 5, 1, 7, 9, 2, 6, 4, 3,
                           1, 3, 8, 9, 4, 7, 2, 5, 6,
                           6, 9, 2, 3, 5, 1, 8, 7, 4,
                           7, 4, 5, 2, 8, 6, 3, 1, 9};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, no_solution) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {6, 0, 6, 5, 0, 8, 4, 0, 0,
                           5, 2, 0, 0, 0, 0, 0, 0, 0,
                           0, 8, 7, 0, 0, 0, 0, 3, 1,
                           0, 0, 3, 0, 1, 0, 0, 8, 0,
                           9, 0, 0, 8, 6, 3, 0, 0, 5,
                           0, 5, 0, 0, 9, 0, 6, 0, 0,
                           1, 3, 0, 0, 0, 0, 2, 5, 0,
                           0, 0, 0, 0, 0, 0, 0, 7, 4,
                           0, 0, 5, 2, 0, 6, 3, 0, 0};

    SudokuLocator locator(ROWS, COLS);
    Sudoku sudoku(challenge, locator);
    ASSERT_FALSE(sudoku.solve());
}

// https://www.telegraph.co.uk/news/science/science-news/9359579/Worlds-hardest-sudoku-can-you-crack-it.html
TEST(sudoku, challenge_3_world_hardest) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {8, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 3, 6, 0, 0, 0, 0, 0,
                           0, 7, 0, 0, 9, 0, 2, 0, 0,
                           0, 5, 0, 0, 0, 7, 0, 0, 0,
                           0, 0, 0, 0, 4, 5, 7, 0, 0,
                           0, 0, 0, 1, 0, 0, 0, 3, 0,
                           0, 0, 1, 0, 0, 0, 0, 6, 8,
                           0, 0, 8, 5, 0, 0, 0, 1, 0,
                           0, 9, 0, 0, 0, 0, 4, 0, 0};

    int expected_solution[SIZE] = {8, 1, 2, 7, 5, 3, 6, 4, 9,
                                   9, 4, 3, 6, 8, 2, 1, 7, 5,
                                   6, 7, 5, 4, 9, 1, 2, 8, 3,
                                   1, 5, 4, 2, 3, 7, 8, 9, 6,
                                   3, 6, 9, 8, 4, 5, 7, 2, 1,
                                   2, 8, 7, 1, 6, 9, 5, 3, 4,
                                   5, 2, 1, 9, 7, 4, 3, 6, 8,
                                   4, 3, 8, 5, 2, 6, 9, 1, 7,
                                   7, 9, 6, 3, 1, 8, 4, 5, 2};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

/*
 * Added test (Extra Credit). Initial input is "rigged", meaning the allowed number range (1-9 for 9x9 grid) is exceeded,
 * and/or the allowed frequency of each number (once per row, once per column, and once per 3x3 box) is not met.
 */
TEST(sudoku, rigged_input) {

    //Following format of other tests
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;

    //Filled but values given are not valid (some values exceed acceptable range)
    int rigged_input[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                              10, 11, 12, 13, 14, 15, 16, 17, 18,
                              19, 20, 21, 22, 23, 24, 25, 26, 27,
                              28, 29, 30, 31, 32, 33, 34, 35, 36,
                              37, 38, 39, 40, 41, 42, 43, 44, 45,
                              46, 47, 48, 49, 50, 51, 52, 53, 54,
                              55, 56, 57, 58, 59, 60, 61, 62, 63,
                              64, 65, 66, 67, 68, 69, 70, 71, 72,
                              73, 74, 75, 76, 77, 78, 79, 80, 81};

    //Partially filled (every other border value is empty). Most non-zero values given exceed acceptable range.
    int rigged_input2[SIZE] = {1, 0, 3, 0, 5, 0, 7, 0, 9,
                              0, 11, 12, 13, 14, 15, 16, 17, 0,
                              19, 20, 21, 22, 23, 24, 25, 26, 27,
                              0, 29, 30, 31, 32, 33, 34, 35, 0,
                              37, 38, 39, 40, 41, 42, 43, 44, 45,
                              0, 47, 48, 49, 50, 51, 52, 53, 0,
                              55, 56, 57, 58, 59, 60, 61, 62, 63,
                              0, 65, 66, 67, 68, 69, 70, 71, 0,
                              73, 0, 75, 0, 77, 0, 79, 0, 81};

    //Filled but only holds ones. Values do not exceed acceptable range, but instead exceed acceptable quantity.
    int rigged_input3[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1};

    //Challenge_3_world_hardest solution BUT with index 80 = -1.
    int almost_expected_solution[SIZE] = {8, 1, 2, 7, 5, 3, 6, 4, 9,
                                   9, 4, 3, 6, 8, 2, 1, 7, 5,
                                   6, 7, 5, 4, 9, 1, 2, 8, 3,
                                   1, 5, 4, 2, 3, 7, 8, 9, 6,
                                   3, 6, 9, 8, 4, 5, 7, 2, 1,
                                   2, 8, 7, 1, 6, 9, 5, 3, 4,
                                   5, 2, 1, 9, 7, 4, 3, 6, 8,
                                   4, 3, 8, 5, 2, 6, 9, 1, 7,
                                   7, 9, 6, 3, 1, 8, 4, 5, -1};

    //Following format of other tests
    SudokuLocator locator(ROWS, COLS);
    Sudoku sudoku(rigged_input, locator);
    ASSERT_FALSE(sudoku.solve());

    SudokuLocator locator2(ROWS, COLS);
    Sudoku sudoku2(rigged_input2, locator2);
    ASSERT_FALSE(sudoku2.solve());

    SudokuLocator locator3(ROWS, COLS);
    Sudoku sudoku3(rigged_input3, locator3);
    ASSERT_FALSE(sudoku3.solve());

    SudokuLocator locator4(ROWS, COLS);
    Sudoku sudoku4(almost_expected_solution, locator4);
    ASSERT_FALSE(sudoku4.solve());
}

