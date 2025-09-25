
#include <string>
using namespace std;

class Matrix {

	private:

		// Stack Data Members
		int    rowsNum;
		int    colsNum;

		// Heap Data Members - Do you need to release them?  Where, when, and how?
		int    **matrixData;
	
	public:

		// Default Constructor
		Matrix();		

		// Additional Constructors
		Matrix( int row, int col );
		Matrix( int row, int col, int **table );

		// Do you think you need a Destructor?  Why or why not?
		~Matrix();

		// Rule of Minimum 4 - You need to implement Copy Constructor and Copy Assignment Operator Overload
		// 		Deep Copy ONLY!!
		Matrix(const Matrix &other);
		Matrix& operator=(const Matrix &other);

		// Getters
		int getElement(int i, int j);
		int getsizeofrows();
		int getsizeofcols();

		// Setters
		bool setElement(int x, int i, int j);

		// Other Member Functions
		Matrix copy();						// Create a Copy of This Matrix
		void addTo( Matrix m );				// Add Matrix m to this matrix
		Matrix subMatrix(int i, int j);     // Obtain the upper-left submatrix of this matrix
		string toString();					// String Conversion Method
};
