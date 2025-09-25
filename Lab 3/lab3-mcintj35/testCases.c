#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Questions.h"
        
int successCount;
int passCount;

int totalTestCases, totalAssertions;

int assert_equal_int(int, int);
int assert_equal_char(char, char);
int assert_equal_str(char*, char*);
int assert_equal_double(double, double, double);
void tearDown(int result);


// ******************* //
// Turn this true once you are ready to test Q1 strcat()
int testStrCatReady = 1;
// ******************* //

// ******************* //
// Turn this true once you are ready to test Q2
int testQ2Ready = 1;
// ******************* //


   
    
//=========Question 1==================================
	void TestQ1_strlen_case1()
	{
		printf("\n=== TestQ1_strlen_case1() ===\n");
		int result = 1; // true;

		char str[] = "This is a test!";
		int expected = 15;
		int actual = 0;

		actual = my_strlen(str);

        result &= assert_equal_int(expected, actual);

		tearDown(result);
	}
	
	void TestQ1_strlen_case2()
	{
		printf("\n=== TestQ1_strlen_case2() ===\n");
		int result = 1; // true;

		char str[] = "This is another test...";
		int expected = 23;
		int actual = 0;

		actual = my_strlen(str);

        result &= assert_equal_int(expected, actual);

		tearDown(result);
	}

	void TestQ1_strlen_case0()
	{
		printf("\n=== TestQ1_strlen_case0() ===\n");
		int result = 1; // true;

		char str[] = "";
		int expected = 0;
		int actual = 0;

		actual = my_strlen(str);

		result &= assert_equal_int(expected, actual);

		tearDown(result);	
	}

	void TestQ1_strcmp_caseEqual()
	{
		printf("\n=== TestQ1_strcmp_caseEqual() ===\n");
		int result = 1; // true;

		char str1[] = "This is a test!";
		char str2[] = "This is a test!";
		int expected = 1;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		result &= assert_equal_int(expected, actual);

		tearDown(result);
	}

	void TestQ1_strcmp_caseUnequalLength()
	{
		printf("\n=== TestQ1_strcmp_caseUnequalLength() ===\n");
		int result = 1; // true;

		char str1[] = "This is a test!";
		char str2[] = "This is a test! ";
		int expected = 0;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		result &= assert_equal_int(expected, actual);

		tearDown(result);
	}

	void TestQ1_strcmp_caseUnequalContents()
	{
		printf("\n=== TestQ1_strcmp_caseUnequalContents() ===\n");
		int result = 1; // true;

		char str1[] = "This is a test!";
		char str2[] = "This is a pass!";
		int expected = 0;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		result &= assert_equal_int(expected, actual);

		tearDown(result);
	}

	void TestQ1_strcmp_caseEmpty()
	{
		printf("\n=== TestQ1_strcmp_caseUnequalContents() ===\n");
		int result = 1; // true;

		char str1[] = "";
		char str2[] = "";
		int expected = 1;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		result &= assert_equal_int(expected, actual);

		tearDown(result);
	}

	void TestQ1_strcmpOrder_caseSmaller()
	{
		printf("\n=== TestQ1_strcmpOrder_caseSmaller() ===\n");
		int result = 1; // true;

		char str1[] = "Absolutely";
		char str2[] = "new start";
		int expected = 0;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		result &= assert_equal_int(expected, actual);

		tearDown(result);
	}

	void TestQ1_strcmpOrder_caseLarger()
	{
		printf("\n=== TestQ1_strcmpOrder_caseLarger() ===\n");
		int result = 1; // true;

		char str1[] = "more than";
		char str2[] = "an apple";
		int expected = 1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		result &= assert_equal_int(expected, actual);

		tearDown(result);
	}

	void TestQ1_strcmpOrder_caseSame()
	{
		printf("\n=== TestQ1_strcmpOrder_caseSame() ===\n");
		int result = 1; // true;

		char str1[] = "Timeless Content";
		char str2[] = "Timeless Content";
		int expected = -1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		result &= assert_equal_int(expected, actual);

		tearDown(result);
	}

	void TestQ1_strcmpOrder_caseSomewhatDiff()
	{
		printf("\n=== TestQ1_strcmpOrder_caseSomewhatDiff() ===\n");
		int result = 1; // true;

		char str1[] = "Timeless Content";
		char str2[] = "Timeless Contents";
		int expected = 0;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		result &= assert_equal_int(expected, actual);

		tearDown(result);
	}
	
	void TestQ1_strcat_TwoStrings() 
	{
		printf("\n=== TestQ1_strcat_TwoStrings() ===\n");
		int result = 1; // true;

		char str_expected[] = "HelloWorld!";
		char str1[] = "Hello";
		char str2[] = "World!";
		char* str_actual = my_strcat(str1, str2);
		
		result &= assert_equal_str(str_expected, str_actual);
		tearDown(result);

		free(str_actual);		
	}

	void TestQ1_strcat_FirstEmpty() 
	{
		printf("\n=== TestQ1_strcat_FirstEmpty() ===\n");
		int result = 1; // true;

		char str_expected[] = "World!";
		char str1[] = "";
		char str2[] = "World!";
		char* str_actual = my_strcat(str1, str2);
		
		result &= assert_equal_str(str_expected, str_actual);
		tearDown(result);

		free(str_actual);
	}

	void TestQ1_strcat_SecondEmpty() 
	{
		printf("\n=== TestQ1_strcat_SecondEmpty() ===\n");
		int result = 1; // true;

		char str_expected[] = "Hello";
		char str1[] = "Hello";
		char str2[] = "";
		char* str_actual = my_strcat(str1, str2);
		
		result &= assert_equal_str(str_expected, str_actual);
		tearDown(result);

		free(str_actual);
	}



//===========================================================
//=================Question 2================================  
	void TestQ2_readandSortBubble() {

		printf("\n=== TestQ2_readandSortBubble() ===\n");
		int result = 1; // true;

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Bubble(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};
		
		int i;
		for (i=0;i<size;i++)
			result &= assert_equal_str(expectedList[i], actualList[i]);

		tearDown(result);

		delete_wordlist(actualList, size);
	}
   
	void TestQ2_readandSortSelection() {

		printf("\n=== TestQ2_readandSortSelection() ===\n");
		int result = 1; // true;

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words_Selection(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};

		int i;
		for (i=0;i<size;i++)
			result &= assert_equal_str(expectedList[i], actualList[i]);

		tearDown(result);

		delete_wordlist(actualList, size);

	}
 


	

//===========================================================
	int runAllTests(int argc, char const *argv[]) {
		
		TestQ1_strlen_case1();
		TestQ1_strlen_case2();
		TestQ1_strlen_case0();
		
		TestQ1_strcmp_caseEqual();
		TestQ1_strcmp_caseUnequalLength();
		TestQ1_strcmp_caseUnequalContents();
		TestQ1_strcmp_caseEmpty();

		TestQ1_strcmpOrder_caseSmaller();
		TestQ1_strcmpOrder_caseLarger();
		TestQ1_strcmpOrder_caseSame();
		TestQ1_strcmpOrder_caseSomewhatDiff();

		if(testStrCatReady)
		{
			TestQ1_strcat_TwoStrings();
			TestQ1_strcat_FirstEmpty();
			TestQ1_strcat_SecondEmpty();
		}
		else
		{
			totalTestCases += 3;
		}

		if(testQ2Ready)
		{
			TestQ2_readandSortBubble();
			TestQ2_readandSortSelection();
		}
		else
		{
			totalTestCases += 2;
		}
		
		return (successCount == totalAssertions);
	}

int main(int argc, char const *argv[]) {
  		
	successCount = 0;
	passCount = 0;
    totalAssertions = 0;
    totalTestCases = 0;
    
	int successCode = runAllTests(argc, argv);

    printf("\n=== Lab Test Report ===");
	if(successCode && testQ2Ready && testStrCatReady)	printf("\nPassed All Tests\n"); 
	else			printf("\nFailed Tests, Check Failure\n");

	printf("Test Case Score (Graded): %d / %d\n", passCount, totalTestCases);
    printf("Total Assertion Score (For Reference): %d / %d\n\n", successCount, totalAssertions);

	if(!testStrCatReady)
		printf("\t==== REMINDER: Set Line 21 to TRUE in testCases.c to test strcat() in Question 1 ===\n");

	if(!testQ2Ready)
		printf("\t==== REMINDER: Set Line 26 to TRUE in testCases.c to test Question 2 ===\n");

	printf("\t==== REMINDER: Before Submission - Check Memory Leak!! (If leaked, fix it in testCases.c) ===\n");
	
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

int assert_equal_str(char* a, char* b)
{
	int result = !strcmp(a, b);  // because strcmp returns 0 when identical
	if(result)	
		successCount++;
	else
	{
		printf("\t\t[ASSERTION] Expected: %s, but Actual: %s \n", a, b);	
	}

    totalAssertions++;
	return result;
}


int assert_equal_double(double a, double b, double tolRange)
{
	int result = ((a <= (b + tolRange)) && (a >= (b - tolRange)));
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