#include <iostream>
using namespace std;

const int HEIGHT = 9;
const int WIDTH = 9;

//function for making the set numbers
void setNum(int arr[][HEIGHT]);

// printing the array
void printArr(int arr[][HEIGHT]);

// universal iteration amount func
int getInput(string output);

// validating number in row
bool colVal(int arr[WIDTH][HEIGHT], int x, int y);

// validating number in column
bool rowVal(int arr[WIDTH][HEIGHT], int x, int y);

// validating the number in the box
bool boxVal(int arr[WIDTH][HEIGHT], int x, int y);

// solving the puzzle
void solve(int arr[WIDTH][HEIGHT]);

// tell user possible numbers in each box
void valNums(int arr[WIDTH][HEIGHT],int x ,int y);

bool hasZeros(int arr[WIDTH][HEIGHT]);

int main()
{
    // setting the arr to the differnt difficulties 
    cout << " *Niall's Sudoku Hub*" << endl;
    int arr[WIDTH][HEIGHT] = {3, 0, 6, 5, 0, 8, 4, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 0, 0, 0, 0, 3, 1, 0, 0, 3, 0, 1, 0, 0, 8, 0, 9, 0, 0, 8, 6, 3, 0, 0, 5, 0, 5, 0, 0, 9, 0, 6, 0, 0, 1, 3, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 7, 4, 0, 0, 5, 2, 0, 6, 3, 0, 0};
    int hardArr[WIDTH][HEIGHT] = {0, 2, 0, 6, 0, 8, 0, 0, 0, 5, 8, 0, 0, 0, 9, 7, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 3, 7, 0, 0, 0, 0, 5, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 8, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 9, 8, 0, 0, 0, 3, 6, 0, 0, 0, 3, 0, 6, 0, 9, 0};
    int impossArr[WIDTH][HEIGHT] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 3, 0, 7, 4, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 2, 0, 8, 0, 0, 4, 0, 0, 1, 0, 6, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 8, 0, 5, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0};
    // making all the numbers in the array 0/empty
    bool run = true;
    int choice;
    // if statement for the different difficulties
    while (run)
    {
        choice = 0;
        cout << "Would you like the easy or hard puzzle? (easy 1, hard  2, impossible 3)";
        cin >> choice;
        if (choice == 1 || 2 || 3)
            run = false;
        else
            cout << "Invalid " << endl;
    }
    if (choice == 2)
    {
        for (int i = 0; i < WIDTH; i++)
            {
                for (int j = 0; j < HEIGHT; j++)
                    {
                        arr[i][j] = hardArr[i][j];
                    }
            }
    }
    else if (choice == 3)
    {
        for (int i = 0; i < WIDTH; i++)
            {
                for (int j = 0; j < HEIGHT; j++)
                    {
                        arr[i][j] = impossArr[i][j];
                    }
            }
    }
    //easy
    //{3, 0, 6, 5, 0, 8, 4, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 0, 0, 0, 0, 3, 1, 0, 0, 3, 0, 1, 0, 0, 8, 0, 9, 0, 0, 8, 6, 3, 0, 0, 5, 0, 5, 0, 0, 9, 0, 6, 0, 0, 1, 3, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 7, 4, 0, 0, 5, 2, 0, 6, 3, 0, 0};
    //hard
    //{0, 2, 0, 6, 0, 8, 0, 0, 0, 5, 8, 0, 0, 0, 9, 7, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 3, 7, 0, 0, 0, 0, 5, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 8, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 9, 8, 0, 0, 0, 3, 6, 0, 0, 0, 3, 0, 6, 0, 9, 0,};
    //impossible
    //{0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 3, 0, 7, 4, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 2, 0, 8, 0, 0, 4, 0, 0, 1, 0, 6, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 8, 0, 5, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0}

    // running the functions
    printArr(arr);
    setNum(arr);
    
}

// setting the numbers in the array
void setNum(int arr[WIDTH][HEIGHT])
{
    bool running = true;
    int min = 17;
    int setNum;
    while (running == true)
        {
            //getting input
            int x = getInput("What is the row you would like to change: ");
            int y = getInput("What is the column you would like to change: ");
            int backUpArr[WIDTH][HEIGHT];
            for (int i = 0; i < WIDTH; i++){
                for (int j = 0; j < HEIGHT; j++){
                    backUpArr[i][j] = arr[i][j];
                }
            }
            // asking user for number
            int setNum = getInput("What is the number you would like to change it to: ");
            arr[x-1][y-1] = setNum;
            printArr(arr);
            printArr(backUpArr);
            // validating the number to the puzzle
            if (rowVal(arr, x, y) == true && colVal(arr, x, y) == true && boxVal(arr, x, y) == true)
            {
                cout << endl << "This is a valid number " << endl;
            }
            //invalidating the number and setting the puzzle back to its og state
            else
            {
                cout << "INVALID NUMBER" << endl;
                arr[x-1][y-1] = backUpArr[x-1][y-1];
            }
            printArr(arr);
            }
}
    

// validating the user input and getting it
int getInput(string output)
{
    int input;
    bool val = false;
    cout << output << endl;
    while (val == false)
    {
        cin >> input;
        if (input >= 1 && input <= 9)
        {
            val = true;
            return input;
        }
    }
}

// printing the array visibly to the user
void printArr(int arr[][HEIGHT])
{
    int sideNum = 1;
    cout << "    1 2 3   4 5 6   7 8 9" << endl;
    cout << "    _____________________";
    for (int i = 0; i < WIDTH; i++)
        {
            if (sideNum != 3 && sideNum != 6)
                cout << endl << sideNum << " | ";
            else
                cout << endl << sideNum << " | ";
            
            for (int j = 0; j < HEIGHT; j++)
                {
                    if (j == 3 || j == 6)
                        cout << "| ";
                    cout << left <<arr[i][j] << " ";
                }
            if (sideNum == 3 || sideNum == 6)
                cout << endl <<"   ----------------------";
            sideNum++;
        }
    cout << endl << endl;
}

//validating the column 
bool colVal(int arr[WIDTH][HEIGHT], int x, int y)
{
    //checking for dups in the row
    cout << "***RUNNING colVal***" << endl;
    for (int i = 0; i < HEIGHT; i++)
        {
            cout << "row " << x << " colum: " << i+1 << " value: " << arr[x-1][i];
            cout << " = ";
            cout <<  "row " << x << " colum: " << y << " value: "<<arr[x-1][y-1] << endl;
            if (arr[x-1][y-1] == arr[x-1][i] && y-1 != i && arr[x-1][y-1] != 0 && arr[x-1][i] != 0)
            {
                return false;
                break;
            }
        }
    return true;
}

//validating the row
bool rowVal(int arr[WIDTH][HEIGHT], int x, int y)
{
    //checking for dups in the row
    cout << "***RUNNING rowVal***" << endl;
    for (int i = 0; i < HEIGHT; i++)
        {
            cout << "All #'s- row: " << i+1 << " colum: " << y << " value: " << arr[i][y-1];
            cout << " = ";
            cout <<  "Entered #- row " << x << " colum: " << y << " value: "<<arr[x-1][y-1] << endl;
            if (arr[x-1][y-1] == arr[i][y-1] && x+y != (i+1)+y && arr[x-1][y-1] != 0 && arr[i][y-1] != 0)
            {
                return false;
                break;
            }
        }
    return true;
}

// validating the box depending on the entry
bool boxVal(int arr[WIDTH][HEIGHT], int x, int y)
{
    // if statement for finding the box it is in 
    int boxX = 0;
    int boxY = 0;
    int i = 0;
    int j = 0;
    int xMax = 3;
    int yMax = 3;
    if (x <= 3)
        boxX += 1;
    else if (x >= 4 && x <= 6)
        boxX += 2;
    else if (x >= 7 && x <= 9)
        boxX += 3;

    if (y <= 3)
        boxY += 1;
    else if (y >= 4 && y <= 6)
        boxY += 2;
    else if (y >= 7 && y <= 9)
        boxY += 3;

    if (boxX == 2 && boxY == 1)
    {
        xMax += 3;
        i += 3;
    }
    else if (boxX == 3 && boxY == 1)
    {
        xMax += 6;
        i += 6;
    }
    else if (boxX == 1 && boxY == 2)
    {
        yMax += 3;
        j += 3;
    }
    else if (boxX == 1 && boxY == 3)
    {
        yMax += 6;
        j += 6;
    }
    else if (boxX == 2 && boxY == 2)
    {
        yMax += 3;
        j += 3;
        xMax += 3;
        i += 3;
    }
    else if (boxX == 3 && boxY == 3)
    {
        yMax += 6;
        j += 6;
        xMax += 6;
        i += 6;
    }
    else if (boxX == 2 && boxY == 3)
    {
        yMax += 6;
        j += 6;
        xMax += 3;
        i += 3;
    }
    else if (boxX == 3 && boxY == 2)
    {
        yMax += 3;
        j += 3;
        xMax += 3;
        i += 3;
    }

    cout << "***RUNNING boxVal***" << endl;
    cout << "i: " << i << " j: " << j << " xMax: " << xMax << " yMax: " << yMax << endl;
    cout << "x: " << x << " y: " << y << endl;

    //validating the box
    while (j < yMax)
        {
            int setNum = arr[x-1][y-1];
            cout << "row " << x-1 << " colum: " << y-1 << " value: " << setNum;
            cout << " = ";
            cout <<  "row " << i << " colum: " << j << " value: "<<arr[i][j] << endl;

            if (setNum == arr[i][j] && i != x-1 && j != y-1 && setNum != 0 && arr[i][j] != 0)
            {
                return false;
            }
            i++;
            if (i == xMax)
            {
                i -= 3;
                j++;
            }
        }
    return true;
}
