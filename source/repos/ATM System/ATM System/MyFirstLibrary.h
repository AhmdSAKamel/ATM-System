// Breakpoint & Memory values.
// f5 for executing code between 2 breakpoints.
// Debug Dropdown/ Disable/Delete/enable all breakpoints.
// Autos Window.
// Quick Watch Window. When debugging, Highlight the values, then press shift + f9.
// Step Into: f11 /Over: f10 /Out: shift + f11 .
// Create Library: Local Library as a file on the Computer.	ctrl + alt + l || veiw drop down / Selution Explorer, Double click then Add.
// Ternary Operator/ Short Hand If  :	condition   ?   expression1   :   expression2;			also nested ternary operator is possible.
// Ranged Loop	{ '1','2','3','4' } this called setts of items.
// Validatation Number.
// Bitwise AND operator '&'   |    Logical And is (&&) .
// Bitwise Or Operator '|'
// Declaration Vs Definition.
// Default Parameters (Default = Fail), (Optional Paramter).
// Function Overloading (To have the same name for more than one function), Compiler differentiates them by the number of parameters + the type of.
// ctrl + shift + b = Build
// Active Frame (Active Functioning frame), During the execution, there is only one active frame. Last execution enter the stack is the first one exists.
// if you want to look through the hierarachy, use breakpoint/ or without, view call hierarachy/stack option.
// Functions Tips, Find all refrences options for discovering where exactly the function have been called in the programme (shift + f11).
// Rename in right click for changing the name only one time
// Recurtion, recursive call for functions.
// Static Variables: A variable keeps its value in the lifetime of the programme. (like globale variables)
// Automatic Variables.
// Register Variables: In past, C++ had the ability to define a variable (adding "register" word to it) then preserve a place in Registers (not RAM)
// Two dimensional Arrays, Rows & Culamns
// Vectors : Declaration & Initialization. (Dynamic Array)
// Add elements to vectors : push-back function.
// Vector of Structure
// Remove elements from Vectors: pop_back (It removes the last element added to the Vector).
// Call ByRef/ByVal: When calling by val, Compiler Creates a variable, gives it an address, then add the value of the parameter into it.
// When calling by Ref: Compiler doesn't create a new variable as Calling by Val do, it gives the parameter a nickname (Same address), it can access from both names.
// Syntax for printing Hexadecimal Address: "cout << & + variable"
// Creating References, By creating a reference of a variable, both are pointing at the same place in memory : int &x = a; Here a and x are pointing at the same place in memory, so address of 'a' and address of 'x' are the same.
// Pointers: Other languages use Pointers automatically in the backgroud and don't allow developers to use Pointer, only C and C++ do.
// Pointers give you full access to memory for maneging it. Pointer is a variable for storing address belongs to another variable, function or anything in memory.
// Dereferencing Pointers: Reaching the Value of Pointers, write "cout << *Variable", Both the pointer and the variable points at the same locatation in memory.
// Pointers Vs References: Reference is like a nickname for the variable, When we create a reference to a variabel, compiler gives a nicname to that variable in the same memory slot in memory.
// When creating a pointer of a variable, compiler creates a different slot in memory, then stores the address of that variable into it.
// When we assign a reference to a variable, we can't change it to another variable during the execution, While we can with pointers.
// Call by Reference: Using Pointers.
// Pointers and Arrays: When we assign a pointer to an array from the same type, The Pointer points at the first element at the array.
// Dynamic Memory Allocation New-Delete: it gives power to C++ to have full controll over memory
// Dynamic Array New-Delete
// Stack vs Heap: Heap is a location in the memory stores dynamic variable/objects/array...etc.	We reach it only by pointers.
// Vectors part || : Access Elements.
// Vectors Change Elements.
// Vector Iterators: a Way for going through the Elements of Vectors using pointers.
// Exception Handling: Try Catch
// String Object. (Common Methods)
// Some cctype Library Functions.
// Write Mode: Write Data To File.
// Append mode - Append Data to File.
// Files Read Mode.
// Load Data From File to Vector.
// Save Vector to File.
// Files Delete Record From File.
// Update Record.
// Files Update Record In File.
// Local/UTC Datetime.
// Datetiem Structure.

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>


#pragma warning(disable: 4996) // When C++ douts in any code, it'll pop up a warning message, this line makes compiler disable the warning with the number 4996.
#pragma once

using namespace std;


namespace Course6Test
{
	int ReadNumberTest(string Message)
	{
		int Number = 0;

		cout << Message;
		cin >> Number;

		while (cin.fail())
		{

			cin.clear();	//Delete the error
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //Ignore rest of the line
			cout << "Invalid Number, Enter a valid one: " << endl;

			cin >> Number;
		}
		return Number;
	}

	string PositiveNegetiveTest(short Number)
	{
		string Status = "";

		Status = (Number == 0) ? "Zero" : ((Number > 0) ? "Positive" : "Negative");		//Nested Ternary Operator.

		return Status;
	}

	struct stName
	{
		string FirstName = "";
		string LastName = "";
		short Salary = 0;
	};

	struct stEmployee
	{
		string FirstName = "";
		string LastName = "";
		short Salary = 0;
	};

	//function decleration
	short Add(short, short);

	int MySum(int a, int b, int c = 0, int d = 0)
	{				//Optional Parameters/ Default Parameters

		return a + b + c + d;

	}

	void PrintNumbers(int N, int M)
	{
		if (N <= M)		//Recursive call 
		{
			cout << N << endl;
			PrintNumbers(N + 1, M); //Calling itslf.
		}

	}

	void RecursiveFromMToN(short M, short N = 0)
	{
		if (M >= 1)
		{
			cout << M << endl;
			RecursiveFromMToN(M - 1);
		}
	}

	short RecursivePowFunction(short N, short P)
	{

		if (P == 0)
			return 1; //Will not be executed untill the call stack is empty.
		else
		{
			short M = (N * RecursivePowFunction(N, P - 1));		//Will come back here for emptying the call stack.
			return M;
		}
	}

	void FillDimensionalArrayInMultTableTest(int arr10[10][10])
	{

		for (short i = 0; i < 10; i++)
		{
			for (short j = 0; j < 10; j++)
			{
				arr10[i][j] = (i + 1) * (j + 1);
			}
		}
	}

	void PrintDimensionalArray(int arr[10][10])
	{
		FillDimensionalArrayInMultTableTest(arr);

		for (short i = 0; i < 10; i++)
		{
			for (short j = 0; j < 10; j++)
			{
				printf("%0*d ", 2, arr[i][j]);
			}
			cout << endl;
		}
	}

	void FillVecotrsTest(vector <short>& vtor)
	{

		for (short& Number : vtor) //When we add the reference sign, it does not copy the item, it goes directly to its location at the memory.
		{
			cout << Number << " "; //Ranged loop will go to the first item reference and print it in a new variable.
		}
		cout << endl;
	}

	void VectorsTest()
	{
		vector <string> vNumbers = { "[]" , "{}" };

		vNumbers.push_back("8"); //Adding elements
		vNumbers.push_back("oop");
		vNumbers.push_back("oop");

		for (string& S : vNumbers)
		{
			cout << S << endl;
		}
	}

	void ReadNumbers(vector <short>& vNumbers)
	{
		short Number = 0;

		char Again = 'y';

		do
		{
			cout << "Please enter a number? ";
			cin >> Number;
			vNumbers.push_back(Number);

			cout << "\nDo you want to read more numbers? Y/N ? ";
			cin >> Again;


		} while (Again == 'y' || Again == 'Y');

	}

	void PrintVectorNumbers(vector <short>& vNumbers) //By refrence is prefered over making a copy then printing it.
	{

		for (short& Num : vNumbers)
		{
			cout << Num << "\n";
		}
		cout << endl;
	}

	void ReadEmployees(vector <stEmployee>& Employees)
	{

		char Again = 'y';

		stEmployee Employee;

		do
		{
			cout << "Enter First Name? ";
			cin >> Employee.FirstName;

			cout << "Enter Last Name? ";
			cin >> Employee.LastName;

			cout << "Enter Salary? ";
			cin >> Employee.Salary;

			Employees.push_back(Employee);

			cout << "\nDo you want to add more employees? Y/N ? ";
			cin >> Again;

		} while (Again == 'y' || Again == 'Y');
	}

	void PrinVectortEmployees(vector <stEmployee>& Employees)
	{

		cout << "\nEmployees vector:\n\n";

		for (stEmployee& Employee : Employees)
		{
			cout << Employee.FirstName << endl;
			cout << Employee.LastName << endl;
			cout << Employee.Salary << endl;

			cout << endl;
		}
	}

	void TestCreateReference()
	{

		int a = 10;
		int& x = a;

		cout << &a << endl;
		cout << x << endl;

		x = 19;		// Changing one will change the other. Because both have the same location in memory.

		cout << a << endl;
		cout << x << endl;
	}

	void TestPointer()
	{
		int a = 10;

		int* P = &a; // Here we defined a variable from pointer of integer kind, stored in P.

		cout << *P + 10;   //  Changing the value by pointer.

	}

	void SwapByPointersTest(int* n1, int* n2) // Sometimes within the function we need to make a variable points at another one at memory.
	{
		int Temp = 0;
		Temp = *n1;
		*n1 = *n2;
		*n2 = Temp;
	}

	void ArrayWithPointersTest(short arr[4])
	{
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		arr[3] = 4;


		short* prr;

		prr = arr; //Equivalent to the address of arr[0].

		cout << *(prr);		// Value of arr[0];

		cout << *(prr + 1);	// Value of arr[1];
	}

	void StructuresWithPointersTest()
	{
		stName Name, * pst; //Assigning a Pointer from the structure type.

		Name.FirstName = "Ahmed";
		Name.LastName = "Kamel";
		Name.Salary = 5000;

		cout << &Name.FirstName;

		pst = &Name;

		cout << pst->LastName; //Accessing the value of structure through a pointer.
	}

	void voidPointerTest()
	{
		//This makes us able to make a data pointer pointing at different data types in the run time.

		void* ppr;	//Generic Pointer, a typeless pointer that can point at any type of data at the memory.

		float f1 = 10.5;
		int x = 50;

		ppr = &f1;

		cout << ppr;	//Note: Void Pointers can't print the value of the variable, because it's Generic that does not know its type.

		cout << *(static_cast<float*>(ppr)); //By this, compiler will cast this generic pointer to a float pointer (Exciplicit Casting), so it could print its value.

		ppr = &x;	//This transfered the pointer from pointing at the float f1 to integer x.

		cout << *(static_cast<int*>(ppr));
	}

	void DynamicMemoryAllocationTest()
	{
		int* prrx; // Pointer does not preserve a space in memory

		// Dynamically allocate memory in the run time.

		prrx = new int;	// A variable from integer type, then pointed at prrx.

		*prrx = 10;

		delete prrx; //Deallocate from the memory, for every "new" function, use "delete" in return.
	}

	void PointerNewArrayTest()
	{
		short NumberOfStudents = 4;

		float* prt;

		prt = new float[NumberOfStudents];

		delete[] prt;	// Deleting the array
	}

	void VectorsAccessElements()
	{
		vector <int> num{ 1,2,3,4,5 };

		cout << num.at(4);

		cout << num[4];
	}

	void VectorsIteratorTest()
	{
		vector <int>num{ 1, 2, 3, 4, 5 };


		//Declare iterator.
		vector <int>::iterator iter;	// Iterator must be the same type of vector.

		//Iterator with for loop.

						// First		/Last element in vector
		for (iter = num.begin(); iter != num.end(); iter++)
		{
			cout << *iter << "  ";  //Iter is pointing at element by element's pointer.
		}

	}

	void ExceptionHandlingTest()
	{
		vector<int>num{ 1,2,3,4,5 };

		try
		{
			cout << num.at(5);		// Any exception happens will not cause to crash the programme.
		}
		catch (...)
		{
			cout << "Out of bound\n";	// Any thing could cause an error put it in here.
		}


	}

	void StringObjectTest() // String Library should be used.
	{
		string s1 = "My Name is Ahmed, I like programming. ";

		cout << s1.length();		// Length

		cout << s1.at(3);			// Return the letter at position 3.

		s1.append("@It'sme.com");	//Add @It'sme.com to the end of string.

		s1.insert(7, " Test ");		// insert "test" at position 7.

		cout << s1.substr(16, 8);	// Print all the next 8 letters from position 16.

		s1.push_back('k');			// Add one character to the end of the string.

		s1.pop_back();				// Remove one character from the end of the string

		cout << s1.find("Test");	// Find "Test" in the string.

		cout << s1.find("test");	// Find "test" in the string.

		if (s1.find("test") == s1.npos) // No Position
		{
			cout << "\"test\" is not found";
		}

		s1.clear();					// Clear all string letters.


	}

	void cctypeFunctionsTest()
	{
		char x, w;

		x = toupper('a');	// From small to capital

		w = tolower('A');	// From capital to small

		cout << x << endl;
		cout << w << endl;

		isupper('A');	// If it's uppercase, it'll return a positive number.

		islower('a');   // if it's not lowercase, it'll return a negative number.

		isdigit('9');   // Check if this chatacter is a digit or not, if not it'll return 0.

		ispunct(';');	// Check it this is a punctuation, if not it'll return 0.

	}

	void WriteDataToFileTest()
	{
		fstream MyFile;			//Assign a variable from file stream.

		// Open the file by write mode. When using write mode. whatever exists in the file. C++ will erase it, then rewrite on.
		MyFile.open("AFile.txt", ios::out);		// Set the name of the file that would store on the SSD by the end of execution.

		if (MyFile.is_open())		// It means that code above works without errors.
		{
			MyFile << "Ali\n";	// For adding to MyFile instead of screen.
			MyFile << "Maher\n";
			MyFile << "Fadi\n";
			MyFile << "Shadi\n";
			MyFile << "Ali\n";
			MyFile << "Mohammed\n";

			MyFile.close();	// To avoid errors
		}

		// To open the file. Go to View dropdown, press Solution explorer, then right mouse click on the project, then open folder in file explorer.
	}

	void AppendModeTest()
	{
		fstream MyFile;

		// MyFile2.open("MyFileInAppenMode.txt", ios::app); : append mode.

		MyFile.open("MyFileInAppenMode.txt", ios::out | ios::app); // Check the file, if it's not existed, open it for Write or append mode, and give priority to append.

		// Every time we make run, the programme will append the Data.

		if (MyFile.is_open())
		{
			MyFile << "Append Test\n";
		}
	}

	void PrintFilesReadModeTest(string FileName)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::in);		// Read Mode: this make us able to read from the file. (can't adjust into it)

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))	// Read first line from "MyFile", and add it to this variable (Line). 
			{
				if (Line == "")
				{
					Line = '\n';
				}
				cout << Line << endl;	// Print the read line.
			}
			MyFile.close();
		}
	}

	void LoadDataFromFiletoVectorTest(string FileName, vector <string>& FileContent)
	{
		fstream MyFile;

		MyFile.open("AFile.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				FileContent.push_back(Line);
			}
			MyFile.close();
		}
	}

	void SaveVectorToFileTest(string FileName, vector <string>& FilledContent)
	{
		fstream VectorFile;

		VectorFile.open(FileName, ios::out);

		if (VectorFile.is_open())
		{
			for (string& C : FilledContent)
			{
				if (C != "")
				{
					VectorFile << C << endl;
				}
			}
			VectorFile.close();
		}
	}

	void DeleteRecordFromFile(string FileName, string Record)
	{
		vector <string> vFileContent;

		LoadDataFromFiletoVectorTest("AFile", vFileContent);

		for (string& Line : vFileContent)
		{
			if (Line == Record)
			{
				Line = "";
			}
		}
		SaveVectorToFileTest(FileName, vFileContent);
	}

	void UpdateRecordInFileTest(string FileName, string Record, string UpdateTo)
	{
		vector <string> vFileContent;
		LoadDataFromFiletoVectorTest(FileName, vFileContent);

		for (string& Line : vFileContent)
		{
			if (Line == Record)
			{
				Line = UpdateTo;
			}
		}
		SaveVectorToFileTest(FileName, vFileContent);

	}

	void DeleterecordFromFileTest()
	{
		WriteDataToFileTest();

		cout << "File Content Before Delete.\n";

		PrintFilesReadModeTest("AFile.txt");

		UpdateRecordInFileTest("AFile.txt", "Ali", "Omar");

		cout << "\n\nFile Content After Delete.\n\n";

		PrintFilesReadModeTest("AFile.txt");
	}

	void LocalGrinitchTimeTest()
	{
		// The library <ctime> is inherited from C language.

		time_t t = time(0);	  //Get time now.

		char* dt = ctime(&t);	// Convert in string form.

		cout << "Local date and time is: " << dt << '\n';

		tm* gmtm = gmtime(&t);		// Converting now to tm struct for UTC date/time. (Grinitch time/Universla time)

		dt = asctime(gmtm);			// Convert in string form.

		cout << "UTC date and time is: " << dt;
	}

	void  DatetiemStructureTest()
	{
		time_t t = time(0);	  //Get time now.

		tm* now = localtime(&t);  //tm is a structure from ctime library.

		cout << "Year: " << now->tm_year + 1900 << endl;	// tm_year is an element of the structure, it gives you how many years after 1900.
		cout << "Month: " << now->tm_mon + 1 << endl;
		cout << "Day: " << now->tm_mday << endl;
		cout << "Hour: " << now->tm_hour << endl;
		cout << "Min: " << now->tm_min << endl;
		cout << "Second: " << now->tm_sec << endl;
		cout << "Week Day (Days since sunday): " << now->tm_wday << endl;
		cout << "Year Day (Days since Jan 1st): " << now->tm_yday << endl;
		cout << "hours of daylight savings time: " << now->tm_isdst << endl;
	}












	int main()
	{
		srand((unsigned)time(NULL));

		return 0;
	}



	// function definition
	short Add(short a, short b)
	{
		return a + b;
	}












}

namespace Course7Test
{
	const string ClientsFileName = "Clients.txt";

	enum enWhatToCount { SmallLetter = 0, CapitalLetter = 1, All = 3 };

	struct stClient
	{
		string AccNumber;
		string PiCode;
		string CName;
		string CNumber;
		double AccBal = 0;
		bool MarkForDelete = false;
	};

	bool isVowl(char C);

	int RandomNumber(short From, short To)
	{
		int RandomNumber = rand() % (To - From + 1) + From;

		return RandomNumber;
	}

	void GenerateRanodmNumbersForMatrix(short arr[3][3])
	{
		for (short i = 0; i < 3; i++)
		{
			for (short C = 0; C < 3; C++)
			{
				arr[C][i] = RandomNumber(1, 10);
			}
		}
	}

	void PrintMatrix(short array[3][3])
	{
		for (short i = 0; i < 3; i++)
		{
			for (short C = 0; C < 3; C++)
			{
				printf(" %0*d ", 2, array[i][C]);
			}
			cout << endl;
		}
	}

	int RowSumTest(short arr[3][3], short RowNumber, short Cols)
	{
		short Sum = 0;

		for (short j = 0; j < Cols; j++)
		{
			Sum += arr[RowNumber][j];
		}
		return Sum;
	}

	void PrintEachRowSumTest(short arr[3][3], short Rows, short Cols)
	{
		cout << "\nThe following are the sum of each row in the matrix:\n";

		for (short i = 0; i < Rows; i++)
		{
			cout << " Row " << i + 1 << " Sum = " << RowSumTest(arr, i, Cols) << endl;
		}
	}

	void SumMatrixRowsInArray(short arr[3][3], short arrSum[3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			arrSum[i] = RowSumTest(arr, i, Cols);
		}
	}

	void PrintTargetSumArray(short arr[3], short Length, string target)
	{
		cout << "\nThe following are the sum of each " << target << " in the matrix : \n";

		for (short i = 0; i < Length; i++)
		{
			cout << target << i + 1 << " Sum = " << arr[i];

			cout << endl;
		}
	}

	short ColSumTest(short arr[3][3], short RowsNumber, short ColsNumber)
	{
		short ColsSum = 0;

		for (short j = 0; j < RowsNumber; j++)
		{
			ColsSum += arr[j][ColsNumber];
		}
		return ColsSum;
	}

	void PrintEachColSum(short arr[3][3], short Rows, short Cols)
	{
		cout << "\nThe following are the sum of each columns in the matrix:\n";

		for (short i = 0; i < Cols; i++)
		{
			cout << " Col " << i + 1 << " Sum = " << ColSumTest(arr, Rows, i) << endl;
		}
	}

	void SumMatrixColsInArray(short arr[3][3], short arrSum[3], short Rows, short Cols)
	{
		for (short i = 0; i < Cols; i++)
		{
			arrSum[i] = ColSumTest(arr, Rows, i);
		}
	}

	void FillArrayWithOrderedNumbs(short arr[3][3], short Rows, short Cols)
	{
		short Counter = 1;

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				arr[i][j] = Counter;
				Counter++;
			}
		}
	}

	void PrintTransposedMatrix(short arr[3][3], short Rows, short Cols)
	{
		cout << "\n\nThe following is the transposed matrix:\n";

		for (short i = 0; i < Cols; i++)
		{
			for (short j = 0; j < Rows; j++)
			{
				cout << setw(3) << arr[j][i] << " ";
			}
			cout << endl;
		}
	}

	void MultiplyMatrix(short arr[3][3], short arrSecond[3][3], short arrSum[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				arrSum[i][j] = arr[i][j] * arrSecond[i][j];
			}

		}
	}

	void PrintMiddleRowofMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MiddleRow = round(Rows / 2);

		for (short i = 0; i < Cols; i++)
		{
			printf(" %0*d ", 2, arr[MiddleRow][i]);

		}
	}

	void PrintMiddleColsofMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MiddleCols = round(Cols / 2);

		for (short i = 0; i < Rows; i++)
		{
			printf(" %0*d ", 2, arr[i][MiddleCols]);
		}
	}

	short SumOfMatrix(short arr[3][3], short Rows, short Cols)
	{
		short Sum = 0;

		for (short i = 0; i < Rows; i++)
		{
			for (short C = 0; C < Cols; C++)
			{
				Sum += arr[i][C];
			}
		}
		return Sum;
	}

	bool CheckTypicalMatrices(short arr[3][3], short arrSecond[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short C = 0; C < Cols; C++)
			{
				if (arr[i][C] != arrSecond[i][C])
				{
					return false;
				}
			}
		}
		return true;
	}

	bool IsIdentityMatrix(short arr[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (i == j && arr[i][j] != 1)
				{
					return false;
				}
				else if (i != j && arr[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool IsScalarMatrix(short arr[3][3], short Rows, short Cols)
	{
		short Scalar = arr[0][0];

		for (short i = 0; i < Rows; i++)
		{
			for (short C = 0; C < Cols; C++)
			{
				if (i == C && arr[i][C] != Scalar)
				{
					return false;
				}
				else if (i != C && arr[i][C] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}

	short HowManyInMatrix(short arr[3][3], short Rows, short Cols, short NumberToCheck)
	{
		short HowMany = 0;
		for (short i = 0; i < Cols; i++)
		{
			for (short j = 0; j < Rows; j++)
			{
				if (arr[j][i] == NumberToCheck)
				{
					HowMany++;
				}
			}
		}
		return HowMany;
	}

	bool IsSparseMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MatrixSize = Rows * Cols;

		return (HowManyInMatrix(arr, Rows, Cols, 0) >= (MatrixSize / 2));
	}

	bool IsNumberInMatrix(short arr[3][3], short Rows, short Cols, short NumberToCheck)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (arr[i][j] == NumberToCheck)
				{
					return true;
				}
			}
		}
		return false;
	}

	void PrintIntersectedNumbersInMatrices(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (IsNumberInMatrix(Matrix1, Rows, Cols, Matrix2[i][j]))
				{
					cout << Matrix2[i][j] << "   ";
				}
			}
		}
	}

	short MinimumNumInMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MinimumNumber = arr[0][0];

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (arr[i][j] < MinimumNumber)
				{
					MinimumNumber = arr[i][j];
				}
			}
		}
		return MinimumNumber;
	}

	short MaxNumberInMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MaxNumber = arr[0][0];

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (arr[i][j] > MaxNumber)
				{
					MaxNumber = arr[i][j];
				}
			}
		}
		return MaxNumber;
	}

	bool IsPalindromeMatrix(short arr[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols / 2; j++)
			{
				if (arr[i][j] != arr[i][Cols - 1 - j]);
				{
					return false;
				}
			}
		}
		return true;
	}

	void PrintFibonacciSeries(short To)
	{
		// I Wrote it on my own;

		short ToPrint = 0, FirstNumber = 1, PrevNumber = 1;

		cout << 1 << "  " << 1;

		for (short i = 2; i < To; i++)
		{
			ToPrint = PrevNumber + FirstNumber;

			cout << "  " << ToPrint;

			PrevNumber = FirstNumber;
			FirstNumber = ToPrint;
		}
	}

	void PrintFibonacciSeriesWithRecursion(short To)
	{
		// Wrote on my own.

		short static ToPrint = 0, FirstNumber = 1, PrevNumber = 0;

		ToPrint = FirstNumber + PrevNumber;

		PrevNumber = FirstNumber;
		FirstNumber = ToPrint;

		cout << ToPrint << "   ";

		if (To > 2)
		{
			PrintFibonacciSeriesWithRecursion(To - 1);
		}
	}

	string ReadString(string Message)
	{
		string String;

		cout << Message;
		getline(cin >> ws, String);	 // This makes ignore to the white spaces, that remains in buffer and cause issues.

		return String;
	}

	void PrintFirstLetterFromEachWord(string Whatever)
	{
		// Doctor's code

		bool isFirstLetter = true;

		cout << "\nFirst letter of this string: \n";

		for (short i = 0; i < Whatever.length(); i++)
		{
			if (Whatever[i] != ' ' && isFirstLetter)
			{
				cout << Whatever[i] << endl;
			}

			isFirstLetter = (Whatever[i] == ' ' ? true : false);
		}
	}

	string PrintFirstLetterInStringInCapital(string Whatever)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < Whatever.length(); i++)
		{
			if (Whatever[i] != ' ' && isFirstLetter)
			{
				Whatever[i] = toupper(Whatever[i]);
			}
			isFirstLetter = (Whatever[i] == ' ' ? true : false);
		}

		return Whatever;
	}

	string PrintFirstLetterInStringInLower(string ss)
	{
		bool isFirst = true;		// Doctor's code

		for (short i = 0; i < ss.length(); i++)
		{
			if (ss[i] != ' ' && isFirst)
			{
				ss[i] = tolower(ss[i]);
			}
			isFirst = (ss[i] == ' ' ? true : false);
		}
		return ss;
	}

	string UpperForString(string ss)
	{
		for (short k = 0; k < ss.length(); k++)
		{
			ss[k] = toupper(ss[k]);
		}
		return ss;
	}

	string LowerForString(string ss)
	{
		for (short i = 0; i < ss.length(); i++)
		{
			ss[i] = tolower(ss[i]);
		}
		return ss;
	}

	char ReadCharacter(string Message)
	{
		char Whatever = ' ';

		cout << Message;
		cin >> Whatever;

		return Whatever;
	}

	char InvertCharacter(char Whatever)
	{
		return isupper(Whatever) ? tolower(Whatever) : toupper(Whatever);
	}

	string InvertCharactersInString(string Whatever)
	{
		for (short i = 0; i < Whatever.length(); i++)
		{
			if (isupper(Whatever[i]) ? Whatever[i] = tolower(Whatever[i]) : Whatever[i] = toupper(Whatever[i]));
		}
		return Whatever;
	}

	short CountLetters(string ss, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return ss.length();
		}
		short Counter = 0;

		for (short i = 0; i < ss.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetter && isupper(ss[i]))
			{
				Counter++;
			}
			if (WhatToCount == enWhatToCount::SmallLetter && islower(ss[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CounterLetter(string ss, char LookingFor, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < ss.length(); i++)
		{
			if (MatchCase)
			{
				if (ss[i] == LookingFor)
				{
					Counter++;
				}
			}
			else
			{
				if (tolower(ss[i]) == tolower(LookingFor))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}

	short CounterVowels(string ss)
	{
		short Counter = 0;

		for (short i = 0; i < ss.length(); i++)
		{
			if (isVowl(ss[i]))
				Counter++;
		}
		return Counter;
	}

	void PrintAllVowls(string SS)
	{
		cout << "\nVowels in string are: ";

		for (short i = 0; i < SS.length(); i++)
		{
			if (isVowl(SS[i]))
			{
				cout << SS[i] << "  ";
			}
		}
	}

	void PrintEachWordInString(string SS, string Seperator = " ")
	{
		// Doctor's code

		string sWord;
		short pos = 0;

		cout << "\nYour string words are: \n\n";

		while ((pos = SS.find(Seperator)) != std::string::npos) // It stores in the variable "pos" the position of the first delimiter, npos() function is for if there is no delimiter, it could be only one word, so it'd exist of the loop.
		{
			sWord = SS.substr(0, pos);
			if (sWord != "")		// For checking if there are so much delimiters EX: "Ahmed     Sayed"
			{
				cout << sWord << endl;
			}

			SS.erase(0, pos + Seperator.length()); // Erase from starting position to start position + the length of the delimiter.
		}
		if (SS != "")
		{
			cout << SS << endl; //In case there is no delimiters in the string & to print last word of the string because there is no delimiter after last word..
		}
	}

	short CountsOfWordsInString(string sits)
	{
		string delimiter = " ", Copy;
		short Counter = 0, pos = 0;

		while ((pos = sits.find(delimiter)) != std::string::npos)
		{
			Copy = sits.substr(0, pos);

			if (Copy != "")
			{
				Counter++;
			}

			sits.erase(0, pos + delimiter.length());
		}
		if (sits != "")
		{
			Counter++;
		}
		return Counter;
	}

	vector <string> mySplit(string ss, string Delim = " ")
	{
		vector <string> Splitted;

		string Copy;
		short pos = 0;

		while ((pos = ss.find(Delim)) != std::string::npos)
		{
			Copy = ss.substr(0, pos);

			if (Copy != "")
			{
				Splitted.push_back(Copy);
			}

			ss.erase(0, pos + Delim.length());
		}
		if (ss != "")
		{
			Splitted.push_back(ss);
		}

		return Splitted;
	}

	string myLeftTrim(string SS)
	{
		for (short i = 0; i < SS.length(); i++)
		{
			if (SS[i] != ' ')
			{
				return SS.substr(i, SS.length() - i);
			}
		}
		return "";
	}

	string myRightTrim(string SS)
	{
		for (short i = SS.length() - 1; i >= 0; i--)
		{
			if (SS[i] != ' ')
			{
				return SS.substr(0, i);
			}
		}
		return " ";
	}

	string myTrim(string SS)
	{
		return (myLeftTrim(myRightTrim(SS)));
	}

	string JoinString(vector<string>Ss, string Delim = " ")
	{
		string T;

		for (string& S : Ss)
		{
			T = T + S + Delim;
		}
		return T.substr(0, T.length() - Delim.length());
	}

	string JoinString(string arrString[3], short arrlength, string Delim = " ")
	{
		string WbW;

		for (short i = 0; i < arrlength; i++)
		{
			WbW = WbW + arrString[i] + Delim;
		}
		return WbW.substr(0, WbW.length() - Delim.length());
	}

	string ReverseWordsInString(string SS)
	{
		vector<string>vString;

		string Reversed = "";

		vString = mySplit(SS);

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			Reversed += *iter + " ";
		}

		return myRightTrim(Reversed);	// We can also return Reversed.substr(0, SS.length()-1)
	}

	string ReplaceWordsWithBuiltInFunction(string SS, string sToReplace, string sReplaceTo)
	{
		short pos = SS.find(sToReplace);

		while (pos != std::string::npos)
		{
			SS = SS.replace(pos, sToReplace.length(), sReplaceTo);

			pos = SS.find(sToReplace);
		}

		return SS;
	}

	string myReplace(string SS, string ToReplace, string ReplaceTo, bool IsSensitive = 1)
	{
		vector <string> MM = mySplit(SS);

		for (string& S : MM)
		{
			if (IsSensitive)
			{
				if (S == ToReplace)
				{
					S = ReplaceTo;
				}
			}
			else
			{
				if (LowerForString(S) == LowerForString(ToReplace))
				{
					S = ReplaceTo;
				}
			}
		}

		SS = JoinString(MM);

		return SS;
	}

	string RemovePunctuations(string SS)
	{
		string Up;

		for (short i = 0; i < SS.length(); i++)
		{
			if (!ispunct(SS[i]))
			{
				Up += SS[i];
			}
		}
		return Up;
	}

	stClient ReadClientData(string AccountNumber = "000")
	{
		stClient Clinet;

		cout << "Please Enter Client Data:\n\n";

		if (AccountNumber == "000")
		{
			Clinet.AccNumber = ReadString("Enter Account Number? ");
		}
		else
			Clinet.AccNumber = AccountNumber;

		Clinet.PiCode = ReadString("Enter Pin Code? ");
		Clinet.CName = ReadString("Enter Name? ");
		Clinet.CNumber = ReadString("Enter Phone? ");
		Clinet.AccBal = Course6Test::ReadNumberTest("Enter Account Balance? ");

		return Clinet;
	}

	string ConvertRecordToLine(stClient Client, string Seperator)
	{
		string RecordClient;

		RecordClient += Client.AccNumber + Seperator;
		RecordClient += Client.PiCode + Seperator;
		RecordClient += Client.CName + Seperator;
		RecordClient += Client.CNumber + Seperator;
		RecordClient += to_string(Client.AccBal);


		return RecordClient;
	}

	stClient ConvertLineToRecord(string SS, string Seperator)
	{
		stClient Client;

		vector <string> vClients = mySplit(SS, Seperator);

		Client.AccNumber = vClients[0];
		Client.PiCode = vClients[1];
		Client.CName = vClients[2];
		Client.CNumber = vClients[3];
		Client.AccBal = stod(vClients[4]); // Cast to double

		return Client;
	}

	stClient MyConvertLineToRecord(string SS, string Seperator)
	{
		stClient Client;

		vector <string> vClients = mySplit(SS, Seperator);

		Client.AccNumber = vClients[0];
		Client.PiCode = vClients[1];



		return Client;
	}

	void AddDataLineToFile(string FileName, string stDataLine)
	{
		fstream myfile;

		myfile.open(FileName, ios::out | ios::app);	//If there is already a file, compiler will append to last item.

		if (myfile.is_open())
		{
			myfile << stDataLine << endl;

			myfile.close();
		}
	}

	void AddNewClient()
	{
		stClient Client = ReadClientData();

		AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client, "/###/"));

	}

	void AddClients()
	{
		string Again;

		do
		{
			system("cls");
			cout << "Adding New Client:\n\n";

			AddNewClient();
			cout << "\nClient Added Successfully, do you want to add more clients? (Yes, No): ";
			cin >> Again;


		} while (Again == LowerForString("Yes"));
	}

	vector <stClient> AddClientsToVector(string FileName)
	{
		vector <stClient> vClients;

		fstream myfile;

		myfile.open(FileName, ios::in);

		if (myfile.is_open())
		{
			stClient Client;
			string Line;

			while (getline(myfile, Line))
			{
				Client = ConvertLineToRecord(Line, "/###/");

				vClients.push_back(Client);

			}
		}
		return vClients;
	}

	void PrintClientCard(stClient Client)
	{
		cout << setw(10) << "\nAccount Number  : " << Client.AccNumber;
		cout << setw(10) << "\nPin Code        : " << Client.PiCode;
		cout << setw(10) << "\nName            : " << Client.CName;
		cout << setw(10) << "\nPhone           : " << Client.CNumber;
		cout << setw(10) << "\nAccount Balance : " << Client.AccBal;
	}

	void PrintAllClientsData(vector <stClient> Clients)
	{
		cout << "\n\t\t\t\t\tClient List (" << Clients.size() << ") Client(s).";
		cout << "\n_________________________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_________________________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		for (stClient Client : Clients)
		{
			PrintClientCard(Client);
			cout << endl;
		}
		cout << "\n_________________________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

	}

	string FirstWord(string SS, string Seperator)
	{
		short pos = SS.find(Seperator);

		while (pos != std::string::npos)
		{
			return SS.substr(0, pos);
		}

		return "Seperator is not found";
	}

	bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vClients)
	{
		for (stClient& Client : vClients)
		{
			if (Client.AccNumber == AccountNumber)
			{
				Client.MarkForDelete = true;
				return true;
			}
		}
		return false;
	}

	bool FindClientByAccountNumber(string AccNuToFind, vector <stClient> vClients, stClient& Client)
	{
		for (stClient C : vClients)
		{
			if (C.AccNumber == AccNuToFind)
			{
				Client = C;
				return true;
			}
		}
		return false;
	}

	vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient>& vClients)
	{
		fstream myfile;
		myfile.open(FileName, ios::out);

		string DataLine;

		if (myfile.is_open())
		{
			for (stClient C : vClients)
			{
				if (C.MarkForDelete == false)
				{
					DataLine = ConvertRecordToLine(C, "/###/");
					myfile << DataLine << endl;
				}
			}
			myfile.close();
		}
		return vClients;
	}

	bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClients, string Seperator)
	{
		stClient Client;
		char Answer = 'n';

		if (FindClientByAccountNumber(AccountNumber, vClients, Client));
		{
			PrintClientCard(Client);

			cout << "\n\nAre you sure you want to delete this client? y/n ? ";
			cin >> Answer;

			if (tolower(Answer) == 'y')
			{
				MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
				SaveClientsDataToFile(ClientsFileName, vClients);

				//refresh Clients
				vClients = AddClientsToVector(ClientsFileName);

				cout << "\n\nClient Deleted Successfully.";

				return true;
			}

		}
		cout << "\n\nClient With Account Number (" << AccountNumber << ") is not found";
	}

	stClient ChangeClientRecord(string AccountNumber)
	{
		stClient Client;

		Client = ReadClientData(AccountNumber);

		return Client;
	}

	bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
	{
		stClient Client;
		char Answer;

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		{
			PrintClientCard(Client);

			cout << "\n\nAre you sure you want to update this client? y/n ? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				for (stClient& C : vClients)	//As long as it's by refrence, the value inside the vector has ajusted.
				{
					if (C.AccNumber == AccountNumber)
					{
						C = ChangeClientRecord(AccountNumber);
						break;		//Break from the loop, not function.
					}
				}

				SaveClientsDataToFile(ClientsFileName, vClients);

				cout << "\n\nClients Updated Successfully.";
				return true;
			}
		}
		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is not found!";
			return 0;
		}


	}




	int main()
	{
		srand((unsigned)time(NULL));

		vector <stClient> vClients = AddClientsToVector(ClientsFileName);
		string AccountNumber = ReadString("Please enter Account Number ? ");

		UpdateClientByAccountNumber(AccountNumber, vClients);

		cout << endl << endl;

		return 0;
	}

	bool isVowl(char C)
	{
		C = tolower(C);

		return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o') || (C == 'u'));
	}

}