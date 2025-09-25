#include <iostream>

#include "Matrix.h"

using namespace std;


int successCount, passCount;
int totalTestCases, totalAssertions;

bool assert_equal(int, int);
bool assert_equal(char, char);
bool assert_equal(string, string);
bool assert_equal(double, double, double);
void tearDown(bool result);

// ******************* //
// Turn this true once you have implemented the Minimum Four Special Member Functions!!
int testReady = true;
// ******************* //


void testConstructor1Invalid1() {

	printf("\n=== testConstructor1Invalid1() ===\n");
	bool result = true; // true;

	// for constructor1
	int invalid_row1 = -1, invalid_col1 = -2;

	string row1 = "0 0 0 \n", row2 = "0 0 0 \n", row3 = "0 0 0 \n";
	string expected = row1 + row2 + row3;
	// test constructor1; invalid inputs
	Matrix a = Matrix(invalid_row1, invalid_col1);

	result &= assert_equal(expected, a.toString());

	tearDown(result);
}

void testConstructor1Invalid2() {

	printf("\n=== testConstructor1Invalid2() ===\n");
	bool result = true; // true;
	
	// for constructor1
	int invalid_row2 = 1, invalid_col2 = 0;
	string expected = "0 0 0 \n";
	Matrix b = Matrix(invalid_row2, invalid_col2);

	result &= assert_equal(expected, b.toString());

	tearDown(result);

}

void testConstructor1Valid() {

    printf("\n=== testConstructor1Valid() ===\n");
	bool result = true; // true;
	
	int valid_row = 3, valid_col = 4;
		// test constructor1; valid inputs
    string row1 = "0 0 0 0 \n", row2 = "0 0 0 0 \n", row3 = "0 0 0 0 \n";
    string expected = row1 + row2 + row3;
	Matrix d = Matrix(valid_row, valid_col);

    result &= assert_equal(expected, d.toString());

	tearDown(result);

}

void testConstructor2() {
	
	printf("\n=== testConstructor2() ===\n");
	bool result = true; // true;
	
	// for constructor2
	int row = 4, col = 5;
	int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int* input_data[4];
	for(int i = 0; i < 4; i++){
		input_data[i] = data[i];
	}
	Matrix f = Matrix(row, col, input_data);

	string row1 = "1 2 3 4 5 \n", row2 = "6 7 8 9 0 \n", row3 = "0 0 1 2 3 \n", row4 = "0 0 0 4 5 \n";
	string expected = row1 + row2 + row3 + row4;

    result &= assert_equal(expected, f.toString());

	tearDown(result);
}

void testGetElementValid() {
	
	printf("\n=== testGetElementValid() ===\n");
	bool result = true; // true;
	
	// for constructor2
    int row = 4, col = 5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
    int* input_data[4];
    for(int i = 0; i < 4; i++){
    	input_data[i] = data[i];
    }
	Matrix f = Matrix(row, col, input_data);

	int expected = 9;	
    result &= assert_equal(expected, f.getElement(1, 3));

	tearDown(result);

}


void testGetElementInvalid() {
	
	printf("\n=== testGetElementInvalid() ===\n");
	bool result = true; // true;
	
	// for constructor2
    int row = 4, col = 5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
    int* input_data[4];
    for(int i = 0; i < 4; i++){
    	input_data[i] = data[i];
    }
	Matrix f = Matrix(row, col, input_data);
	
	string actual = "Empty for Now";
	int output = 0;

	try {
		output = f.getElement(10, 2);	// invalid indexes
	}
	catch (const std::out_of_range& e){
		actual = e.what();
	}

    string expected = "Invalid indexes.";

    result &= assert_equal(expected, actual);

	tearDown(result);

}


void testSetElementValid() {
	
	printf("\n=== testSetElementValid() ===\n");
	bool result = true; // true;	
	
	int value = 100;
	int setvalid_row = 0, setvalid_col = 0;
	int row = 4, col = 5;
	int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int* input_data[4];
	for(int i = 0; i < 4; i++){
		input_data[i] = data[i];
	}
	Matrix f =  Matrix(row,col, input_data);
	bool check = f.setElement(value, setvalid_row, setvalid_col);
	string row1 = "100 2 3 4 5 \n", row2 = "6 7 8 9 0 \n", row3 = "0 0 1 2 3 \n", row4 = "0 0 0 4 5 \n";
	string expected = row1 + row2 + row3 + row4;

	result &= assert_equal(expected, f.toString());
	result &= assert_equal(true, check);

	tearDown(result);
}



void testSetElementInvalid() {
	
	printf("\n=== testSetElementInvalid() ===\n");
	bool result = true; // true;	
	
	int value = 100;
	int setinvalid_row = 10, setinvalid_col = 10;
	int row = 4, col = 5;
	int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int* input_data[4];
	for(int i = 0; i < 4; i++){
		input_data[i] = data[i];
	}
	Matrix f = Matrix(row, col, input_data);
	bool check = f.setElement(value, setinvalid_row, setinvalid_col);
	string row1 = "1 2 3 4 5 \n", row2 = "6 7 8 9 0 \n", row3 = "0 0 1 2 3 \n", row4 = "0 0 0 4 5 \n";
	string expected = row1 + row2 + row3 + row4;

	result &= assert_equal(expected, f.toString());
	result &= assert_equal(false, check);

	tearDown(result);
}

void testCopy() {
	
	printf("\n=== testCopy() ===\n");
	bool result = true; // true;	
	
	int row = 4, col = 5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int* input_data[4];
	for(int i = 0; i < 4; i++){
	    input_data[i] = data[i];
	}
	Matrix origin = Matrix(row, col, input_data);
    Matrix copied = origin.copy(); // make a copy
	string row1 = "1 2 3 4 5 \n", row2 = "6 7 8 9 0 \n", row3 = "0 0 1 2 3 \n", row4 = "0 0 0 4 5 \n";
	string expected = row1 + row2 + row3 + row4;

    result &= assert_equal(expected, copied.toString());

	tearDown(result);
}

void testAddToInvalid() {
	
	printf("\n=== testAddToInvalid() ===\n");
	bool result = true; // true;	
	
	/*Add-to Matrix*/
	int row_to_add = 4; 
	int col_to_add = 3;
	int add_to_data[4][3] = {{3,4,5}, {1,2,3}, {0,0,0},{1,2,1}}; // add to 'data' matrix, dimension not match

	int* add_input_data[4];
	for(int i = 0; i < 4; i++){
		add_input_data[i] = add_to_data[i];
	}

	/*Original Matrix*/
	int row = 4;int col = 5;
	int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int* input_data[4];
	for(int i = 0; i < 4; i++){
		input_data[i] = data[i];
	}
	Matrix origin = Matrix(row, col, input_data);

	string actual ="Empty for Now";
	string expected = "Invalid operation.";
	Matrix m = Matrix(row_to_add, col_to_add, add_input_data);

	try{
		m.addTo(origin);
	}
	catch (const std::invalid_argument& e) {
		actual = e.what();
	}

	result &= assert_equal(expected, actual);

	tearDown(result);
}


void testAddToValid() {
	
	printf("\n=== testAddToValid() ===\n");
	bool result = true; // true;	
	
	int add_to_data[4][3] = {{3,4,5}, {1,2,3}, {0,0,0},{1,2,1}}; // add to 'data' matrix, dimension not match
	int add_to_above[4][3] = {{1,0,-1}, {2,1,0}, {2,2,2},{0,-1,0}}; // add to 'add_to_data' matrix
	int row = 4, col = 3;

	int* input_data[4];
	for(int i = 0; i < 4; i++){
		input_data[i] = add_to_data[i];
	}
	Matrix m = Matrix(row, col, input_data);

	for(int i = 0; i < 4; i++){
		input_data[i] = add_to_above[i];
	}
	Matrix m1 = Matrix(row, col, input_data);
	string row1 = "4 4 4 \n", row2 = "3 3 3 \n", row3 = "2 2 2 \n", row4 = "1 1 1 \n";
	string expected = row1 + row2 + row3 + row4;

	try{
		m.addTo(m1);
		result &= assert_equal(expected, m.toString());
	}
    catch (const std::invalid_argument& e) {
		std::cerr << "supposed to be a valid input: " << e.what() << '\n';
		result = 0;
    }

	tearDown(result);
}




void testSubMatrixValid() {
	
	printf("\n=== testSubMatrixValid() ===\n");
	bool result = true; // true;	
	
	int subvalid_row = 3, subvalid_col = 3;

	int row = 4, col = 5;
	int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int* input_data[4];
	for(int i = 0; i < 4; i++){
		input_data[i] = data[i];
	}
	Matrix f = Matrix(row, col, input_data);

	string row1 = "1 2 3 4 \n", row2 = "6 7 8 9 \n", row3 = "0 0 1 2 \n", row4 = "0 0 0 4 \n";
	string expected = row1 + row2 + row3 + row4;

	try{
		Matrix y = f.subMatrix(subvalid_row, subvalid_col);
		result &= assert_equal(expected, y.toString());
	}
	catch (std::out_of_range& e){
		std::cerr << "supposed to be a valid input: " << e.what() << '\n';
		result = 0;
    }

	tearDown(result);
}



void testSubMatrixInvalid() {
	
	printf("\n=== testSubMatrixInvalid() ===\n");
	bool result = true; // true;	
	
	int subinvalid_row = 3, subinvalid_col = 6;

	int row = 4,col = 5;
	int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int* input_data[4];
	for(int i = 0; i < 4; i++){
		input_data[i] = data[i];
	}
	Matrix f = Matrix(row, col, input_data);

	string actual ="Empty for Now";
	string expected = "Submatrix not defined.";

	try{
		Matrix y = f.subMatrix(subinvalid_row, subinvalid_col);
	}
	catch (std::out_of_range& e){

		actual = e.what();
	}

	result &= assert_equal(expected, actual);

	tearDown(result);
}












//===========================================================
	bool runAllTests(int argc, char const *argv[]) {
		
		testConstructor1Invalid1();
		testConstructor1Invalid2();
		testConstructor1Valid();
		testConstructor2();

		testGetElementValid();
		testGetElementInvalid();

		testSetElementValid();
		testSetElementInvalid();

		testCopy();

		testAddToInvalid();
		testAddToValid();
		testSubMatrixValid();
		testSubMatrixInvalid();
		
		return (successCount == totalAssertions);
	}

int main(int argc, char const *argv[]) {
  		
	bool testResult = false;
	successCount = 0;
	passCount = 0;
    totalAssertions = 0;
    totalTestCases = 0;
    
	if(testReady)
	{
		testResult = runAllTests(argc, argv);

		cout << endl << "=== Lab Test Report ===";
		if(testResult)	cout << endl << "Passed All Tests" << endl; 
		else			cout << endl << "Failed Tests, Check Failure" << endl;

		cout << "Test Case Score (Graded): " << passCount << " / " << totalTestCases << endl;
		cout << "Total Assertion Score (For Reference): " << successCount << " / " << totalAssertions << endl << endl;

		cout << "\t==== REMINDER: Respect the C++ Rule of Six / Minimum Four!! ===" << endl;
		cout << "\t==== REMINDER: Before Submission - Check Memory Leak!! If Leaked, Fix It!! ===" << endl;
	}	
	else
	{
		cout << endl << "=== Test Not Run! ===" << endl;
		cout << "==== REMINDER: Respect the C++ Rule of Six / Minimum Four!! ===" << endl;
		cout << "==== REMINDER: Implement Minimum Four Special Member Functions, then Set Line 19 in testCases.cpp to TRUE to run the Test Bench! ===" << endl;
	}
	
	return testResult? EXIT_SUCCESS : EXIT_FAILURE;
}
    
bool assert_equal(int a, int b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		cout << "\t\t[ASSERTION] Expected: " << a << ", but Actual: " << b << endl;	
	}

    totalAssertions++;
	return result;
}

bool assert_equal(char a, char b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		cout << "\t\t[ASSERTION] Expected: " << a << ", but Actual: " << b << endl;
	}

    totalAssertions++;
	return result;
}

bool assert_equal(string a, string b)
{
	bool result = (a == b); 
	if(result)	
		successCount++;
	else
	{
		cout << "\t\t[ASSERTION] Expected: " << a << ", but Actual: " << b << endl;
	}

    totalAssertions++;
	return result;
}


bool assert_equal(double a, double b, double tolRange)
{
	bool result = ((a <= (b + tolRange)) && (a >= (b - tolRange)));
	if(result)	
		successCount++;
	else
	{
		cout << "\t\t[ASSERTION] Expected: " << a << ", but Actual: " << b << endl;
	}

    totalAssertions++;
	return result;
}

void tearDown(bool result)
{
    totalTestCases++;
    
    if(result) 
    {
        passCount++;
        cout << "Passed" << endl;
    }
    else
    {
        cout << "!!! FAILED !!!" << endl;
    }
} 
