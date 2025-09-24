
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Question1.h"

int successCount;
int passCount;

int totalTestCases, totalAssertions;

int assert_equal_int(int, int);
int assert_equal_char(char, char);
void tearDown(int result);

   
    
//=========test 1==================================
	void TestQ1_1() {
		
        printf("\n=== TestQ1_1() ===\n");

		int result = 0; // false

		int input1 = 2, input2 = 4, expected = 6, actual = 0;
		actual = addFunction(input1,input2);
		result = assert_equal_int(expected, actual);

        tearDown(result);
	}

//=========test 2==================================
    
	void TestQ1_2() {
		
        printf("\n=== TestQ1_2() ===\n");

		int result = 0; // false

		int input1 = 0, input2 = 4, expected = 4, actual = 0;
		actual = addFunction(input1,input2);
		result = assert_equal_int(expected, actual);

        tearDown(result);
	}

//=========Custom Test Cases==================================

	void TestQ1_Custom1()
    {
        printf("\n=== TestQ1_Custom1() ===\n");

        int result = 0;

        int input1 = 7, input2 = -2, expected = 5, actual = 0;
		actual = addFunction(input1,input2);
		result = assert_equal_int(expected, actual);

        tearDown(result);
    }

	void TestQ1_Custom2()
    {
        printf("\n=== TestQ1_Custom2() ===\n");

        int result = 0;

        int input1 = 3, input2 = -5, expected = -2, actual = 0;
		actual = addFunction(input1,input2);
		result = assert_equal_int(expected, actual);

        tearDown(result);
    }

	void TestQ1_Custom3()
    {
        printf("\n=== TestQ1_Custom3() ===\n");

        int result = 0;

        int input1 = -2, input2 = -5, expected = -7, actual = 0;
		actual = addFunction(input1, input2);
		result = assert_equal_int(expected, actual);

        tearDown(result);
    }
   
  
//===========================================================
	int runAllTests(int argc, char const *argv[]) {
		
		TestQ1_1();
		TestQ1_2();

		TestQ1_Custom1();
		TestQ1_Custom2();
		TestQ1_Custom3();

		return (successCount == totalAssertions);
	}

int main(int argc, char const *argv[]) {
  		
	successCount = 0;
	passCount = 0;
    totalAssertions = 0;
    totalTestCases = 0;
    
	int successCode = runAllTests(argc, argv);

    printf("\n=== Lab Test Report ===");
	if(successCode)	printf("\nPassed All Tests\n"); 
	else			printf("\nFailed Tests, Check Failure\n");

	printf("Test Case Score (Graded): %d / %d\n", passCount, totalTestCases);
    printf("Total Assertion Score (For Reference): %d / %d\n\n", successCount, totalAssertions);

	return successCode? EXIT_SUCCESS : EXIT_FAILURE;
}
    
int assert_equal_int(int a, int b)
{
	int result = (a == b);
	if(result)	
		successCount++;
	else
	{
		printf("\t\t[ASSERTION] Expected: %d, but Actual: %d \n", a, b);	
	}

	totalAssertions++;
	return result;
}

int assert_equal_char(char a, char b)
{
	int result = (a == b);
	if(result)	
		successCount++;
	else
	{
		printf("\t\t[ASSERTION] Expected: %c, but Actual: %c \n", a, b);	
	}

	totalAssertions++;
	return result;
}

void tearDown(int result)
{
    totalTestCases++;
    
    if(result) 
    {
        passCount++;
        printf("Passed\n");
    }
    else
    {
        printf("!!! FAILED !!!\n");
    }
} 
