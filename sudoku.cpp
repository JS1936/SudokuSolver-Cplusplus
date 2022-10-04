#include <set>
#include "sudoku.h"
#include <iostream>
using namespace std;

Sudoku::~Sudoku() {
    delete[] challenge;
}

bool Sudoku::solve() {
    cout << "\nOriginal Sudoku grid:" << endl;
    print();

    set<int> isZero; //Holds each index where 0s exist (for 9x9 grid, indices are [0-80], inclusive, by row)
    bool validUpdateAttempt = updateSetOfZeros(isZero, 0);
    if(!validUpdateAttempt)
    {
        return false;
    }

    bool isSolved = solve(*isZero.begin() / 9,*isZero.begin() % 9, isZero);
    bool isSolvedAndValid = isSolved && solutionHasValidFrequencyAndRangeOfNumbers();

    //Clarification printouts
    if(isSolvedAndValid)
    {
        cout << "Solved result:" << endl;
        print();
    }
    else //isSolved but not valid OR not even solved in the first place
    {
        cout << "No valid solution was found." << endl;
    }
    return isSolvedAndValid;

}

bool Sudoku::solve(size_t row, size_t col, set<int> &isZero)
{
    if(isZero.size() == 0) //Can catch pre-solved sudoku game
    {
        return true; //Assumes valid contents. Validity of contents is checked before solve()'s final return
    }
    int index = *isZero.begin();

    //Update possibleValues for location "index"
    set<int> possibleValues = {1,2,3,4,5,6,7,8,9};
    updatePossibleValuesRowColBox(row, col, possibleValues);

    //Try each possible value until one is found that works (fits a final solution)--or there is no solution.
    //If there are no possible values, fitsThere remains false because for/each loop does not run.
    bool fitsThere = false;
    for(int possibleValue : possibleValues)
    {
        if(isZero.size() == 0) //Final solution found.
        {
            return true; //Assumes valid contents. Validity of contents is checked before solve()'s last return
        }
        set_board_val(row, col, possibleValue);
        isZero.erase(index);

        int indexOfNextZero = *isZero.begin();
        fitsThere = solve(indexOfNextZero / 9, indexOfNextZero % 9, isZero);
        if(!fitsThere && !isZero.empty())
        {
            set_board_val(row, col, 0);
            isZero.insert(index);
        }
    }
    return fitsThere;
}

/*
 * A Sudoku puzzle filled with numbers is not necessarily a valid solution.
 * Valid solutions have only numbers in the valid range, and those numbers occur only once per row, col, and 3x3 box.
 */
bool Sudoku::solutionHasValidFrequencyAndRangeOfNumbers()
{
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            //Check if valid number range: [1,9] inclusive
            int val = *challenge_board(row, col);
            if(val <= 0 || val > 9)
            {
                cout << "Found: " << val << ". Invalid number range" << endl;
                return false;
            }

            //Check if valid number frequency (once per row, once per column, and once per box [3x3])
            set<int> possibleValues = {1,2,3,4,5,6,7,8,9};
            updatePossibleValuesRowColBox(row, col, possibleValues);
            if(possibleValues.size() != 0)
            {
                cout << "Error: solution does not have valid number quantities." << endl;
                cout << "Each appropriate number should appear once per row, once per column, and once per box (3x3)" << endl;
                return false; //There should be no values possible if the value is filled and the solution completed
            }
        }
    }
    return true;
}

//Prints the Sudoku game visually in a grid. Contents are up-to-date for when called.
void Sudoku::print()
{

    for(int layer = 0; layer < 9; layer++)
    {
        if(layer % 3 == 0 && layer != 0)
        {
            cout << "\t     ______________________________" << endl;
        }
        cout << "layer " << layer << " | ";
        for (int i = 0; i < 9; i++)
        {
            if(i % 3 == 0 && i != 0)
            {
                cout << "| ";
            }
            cout << *challenge_board(layer, i) << "  ";
        }
        cout << endl;
    }
    cout << "\t     ______________________________\n" << endl;
}

bool Sudoku::updateSetOfZeros(set<int> &isZero, int index)
{
    if(index >= 0 && index <= 80)
    {
        int row = index / 9;
        int col = index % 9;
        if(*challenge_board(row, col) == 0)
        {
            isZero.insert(index);
        }
        else //not 0
        {
            if(*challenge_board(row, col) < 0 || *challenge_board(row, col) > 9)
            {
                cout << "(" << row << ", " << col << ") = " << *challenge_board(row, col) << endl;
                cout << "Error: the starting board holds invalid values" << endl;
                return false;
            }
        }
        return updateSetOfZeros(isZero, index + 1);
    }
    return true;
}

void Sudoku::updatePossibleValuesRowColBox(size_t row, size_t col, set<int>& possibleValues)
{
    updatePossibleColValues(0, col, possibleValues);
    updatePossibleRowValues(row, 0, possibleValues);
    int rowStartBox = determineBoxStart(row);
    int colStartBox = determineBoxStart(col);
    updatePossibleBoxValues(rowStartBox, colStartBox, possibleValues, 0);
}

void Sudoku::updatePossibleRowValues(size_t row,size_t col, set<int> &possibleValues)
{
    int val = *challenge_board(row, col);
    possibleValues.erase(val);
    if(col < 8)
    {
        updatePossibleRowValues(row, col + 1, possibleValues);
    }
}

void Sudoku::updatePossibleColValues(size_t row, size_t col, set<int> &possibleValues, size_t boxWidth)
{
    int val = *challenge_board(row, col);
    possibleValues.erase(val);
    if(row < (boxWidth - 1))
    {
        updatePossibleColValues(row + 1, col, possibleValues, boxWidth);
    }
}

void Sudoku::updatePossibleColValues(size_t row, size_t col, set<int> &possibleValues) {
    updatePossibleColValues(row, col, possibleValues, 9);
}

void Sudoku::updatePossibleBoxValues(int boxStart_row, int boxStart_col, set<int> &possibleValues, int count)
{
    while(count < 3)
    {
        updatePossibleColValues(boxStart_row, boxStart_col + count, possibleValues, boxStart_row + 3);
        count++;
    }
}

int Sudoku::determineBoxStart(int loc)
{
    if(loc < 3)
    {
        return 0;
    }
    else if(loc < 6)
    {
        return 3;
    }
    else //Assumes loc not greater than 8
    {
        return 6;
    }
}