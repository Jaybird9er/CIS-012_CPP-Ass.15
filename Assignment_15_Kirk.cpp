#include <iostream>
using namespace std;

// function prototypes
void setZero(int newArray[]);
void inputArray(int inputArray[]);
void doubleArray(int doubleArray[], int sourceArray[]);
void copyGamma(int gammaArray[4], int inStockArray[10][4]);
void copyAlphaBeta(int alpha[], int inStock[10][4], int beta[]);
void print1DArray(int printArray[]);
void printMultiArray(int printArray[10][4]);
void setInStock(int setInStock[10][4], int delta[10]);

int main ()
{
    // variables
    int inStock[10][4];
    int alpha[20];
    int beta[20];
    int gamma[4] = {11, 13, 15, 17};
    int delta[10] = {3, 5, 2, 6, 10, 9, 7, 11, 1, 8};
    int userSet[10][4];

    // body
    setZero(alpha);
    setZero(beta);
    cout << "Alpha after initialization" << endl;
    print1DArray(alpha);
    cout << endl;
    cout << "***********************************************" << endl;

    cout << "Enter 20 integers" << endl;
    inputArray(alpha);
    cout << endl;

    cout << "Alpha after reading 20 numbers" << endl;
    print1DArray(alpha);
    cout << endl;
    cout << "***********************************************" << endl;

    cout << "Beta after a call to doubleArray" << endl;
    doubleArray(beta, alpha);
    print1DArray(beta);
    cout << endl;
    cout << "***********************************************" << endl;

    cout << "inStock after a call to copyGamma" << endl;
    copyGamma(gamma, inStock);
    printMultiArray(inStock);
    cout << "***********************************************" << endl;

    cout << "inStock after a call to copyAlphaBeta" << endl;
    copyAlphaBeta(alpha, inStock, beta);
    printMultiArray(inStock);
    cout << "***********************************************" << endl;

    cout << "Enter 10 integers" << endl;
    setInStock(userSet, delta);
    cout << "inStock after a call to setInStock" << endl;
    printMultiArray(userSet);
    cout << "***********************************************" << endl;

    return 0;
}

// functions
// initialize and set arrays to 0
void setZero(int newArray[])
{
    for (int i = 0; i < 20; i++)
    {
        newArray[i] = 0;
    }
}

// user inputs 20 numbers
void inputArray(int inputArray[])
{
    for (int index = 0; index < 20; index++)
    {
        cin >> inputArray[index];
    }
}

// array to copy and double elements
void doubleArray(int doubleArray[], int sourceArray[])
{
    for (int index = 0; index < 20; index++)
    {
        doubleArray[index] = sourceArray[index] * 2;
    }
}

// 1D print array function
void print1DArray(int printArray[])
{
    for (int index = 0; index < 20; index++)
    {
        cout << printArray[index] << '\t';
    }
}

// Multi D print array function
void printMultiArray(int printArray[10][4])
{
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << printArray[row][col] << '\t';
            if ((col + 1) % 4 == 0)
            {
                cout << endl;
            }
        }
    }
}

// sets the elements of the first row of inStock from gamma and the remaining rows of inStock to three times the previous row of inStock
void copyGamma(int gammaArray[4], int inStockArray[10][4])
{
    int num[4];
    for (int index = 0; index < 4; index++)
    {
        num[index] = gammaArray[index];
    }
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (row != 0)
            {
                num[col] = num[col] * 3;
            }
            inStockArray[row][col] = num[col];
        }
    }
}

// inStock after a call to copyAlphaBeta
void copyAlphaBeta(int alpha[], int inStock[10][4], int beta[])
{
    int num = 0;
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (num < 20)
            {
                inStock[row][col] = alpha[num];
            }
            else
            {
                inStock[row][col] = beta[num - 20];
            }
            num++;
        }
    }
}

// user sets integers for 1st column, then numbers are doubled and delta is subtracted from each row
void setInStock(int setInStock[10][4], int delta[10])
{
    int userNum[10];
    for (int num = 0; num < 10; num++)
    {
        cin >> userNum[num];
    }
    cout << endl;
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if ((col + 1) % 4 == 1)
            {
                setInStock[row][col] = userNum[row];
            }
            else
            {
                setInStock[row][col] = setInStock[row][col - 1] * 2 - delta[row];
            }
        }
    }
}
