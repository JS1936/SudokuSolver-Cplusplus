# SudokuSolver in C++ 
This project was a school assignment. This course introduced me to C++.

## Purpose ##
Given a Sudoku puzzle, the program eliminates impossibilities (checks current location against row, col, and box), and then uses guess/check with recursive backtracking to find a solution, if one exists.

Note: It is possible for no solution to exist. It is also possible for more than one solution to exist. If more than one solution exists, the program finds and prints the first solution it encounters. 

## Example of Input/Output ##
Once a solution is found (or not found), the original Sudoku and the resulting Sudoku are printed to console.

A zero indicates an empty location in the Sudoku grid. 


![image](https://user-images.githubusercontent.com/102188643/192682836-8f244192-246a-4bc7-aaa2-5d48574a57a1.png)


## Classes Breakdown ##

Files I wrote/created:
* [sudoku.cpp](https://github.com/JS1936/SudokuSolver-Cplusplus-uwb/blob/main/src/problem_3/sudoku.cpp)
* [testcases_output](https://github.com/JS1936/SudokuSolver-Cplusplus-uwb/blob/main/SudokuTestcasesOutput_.docx)
* [sudoku_solver_all_testcases_pass_screenshot](https://user-images.githubusercontent.com/102188643/192669625-01b78f56-c1bf-48d6-aea6-e63ed5ab3c95.png)

Files I contributed to:
* [sudoku.h](https://github.com/JS1936/SudokuSolver-Cplusplus-uwb/blob/main/src/problem_3/sudoku.h) (Added the appropriate method headers)
* [unit_test_sudoku.cpp](https://github.com/JS1936/SudokuSolver-Cplusplus-uwb/blob/main/test/problem_3/unit_test_sudoku.cpp) (Added rigged_input testcase)

Files provided by the instructor, which I did not contribute to:
* All other files

## Testing ## 
For privacy reasons, the testcases themselves are included below, but not the GoogleTests setup for running them.

### Testcases: ### 
All testcases are provided by the instructor, with the exception of "sudoku.rigged_output", which I added to unit_test_sudoku.cpp.
* [unit_test_sudoku.cpp](https://github.com/JS1936/SudokuSolver-Cplusplus-uw/blob/main/unit_test_sudoku.cpp)
* [unit_test_sudoku_locator.cpp](https://github.com/JS1936/SudokuSolver-Cplusplus-uw/blob/main/unit_test_sudoku_locator.cpp)


### Output of Testcases: ###
The unabridged output includes all testcases. The summary screenshot shows all testcases passing, no memory leaks.
* Unabridged: [testcases_output](https://github.com/JS1936/SudokuSolver-Cplusplus-uw/blob/main/SudokuTestcasesOutput_.docx)
* Summary:
  [sudoku_solver_all_testcases_pass_screenshot](https://user-images.githubusercontent.com/102188643/192669625-01b78f56-c1bf-48d6-aea6-e63ed5ab3c95.png)
  
## Development ##
* IDE: CLion
* OS: Ubuntu/Linux, via Windows computer

