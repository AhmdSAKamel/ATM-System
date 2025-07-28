#include "MyFirstLibrary.h";

void Screen(string Message)
{
	system("cls");

	cout << "----------------------------------------\n";
	cout << setw(30) << Message;
	cout << "\n----------------------------------------";
}

Course7Test::stClient CurrentClient;

string ClientsFile = "ClientsInfo";

Course7Test::stClient ReadAccount()
{
	Course7Test::stClient Client;

	cout << "\nEnter Username? ";
	getline(cin >> ws, Client.AccNumber);

	cout << "Enter Password? ";
	getline(cin, Client.PiCode);

	return Client;
}

void ReshowMenueScreen();

vector <Course7Test::stClient> LoadFileDataToVector(string Seperator = "/###/")
{
	Course7Test::stClient Client;
	vector <Course7Test::stClient> vClients;

	fstream myFile;
	string Line;

	myFile.open(ClientsFile, ios::in);

	if (myFile.is_open())
	{
		while (getline(myFile, Line))
		{
			Client = Course7Test::ConvertLineToRecord(Line, Seperator);

			vClients.push_back(Client);

		}
		myFile.close();
	}
	return vClients;
}

int ReadNumberInRange(string Message, int From, int To)
{
	short Number;
	string pp = "";
	do
	{
		cout << Message;
		cin >> Number;

		if (cin.fail())
		{
			cin.clear(); // clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
			cout << "\nInvalid input. Please enter a valid number.\n\n";
			continue;
		}


	} while (Number < From || Number > To || (cin.fail()));

	return Number;
}

bool IsClientExtent(Course7Test::stClient &Client, vector < Course7Test::stClient> vClients)
{
	for (Course7Test::stClient C : vClients)
	{
		if (C.AccNumber == Client.AccNumber && C.PiCode == Client.PiCode)
		{
			Client.AccBal = C.AccBal, Client.CName = C.CName, Client.CNumber = C.CNumber;

			return true;
		}
	}

	return false;
}

void ATMScreen()
{
	system("cls");
	cout << "=================================================\n";
	cout <<  setw(40) << "ATM Main Menue Screen\n";
	cout << "=================================================\n";
	cout << setw(20) << "[1] Quick Withdraw. \n";
	cout << setw(20) << "[2] Normal Withdraw.\n";
	cout << setw(20) << "[3] Deposite.       \n";
	cout << setw(20) << "[4] Check Balance.  \n";
	cout << setw(20) << "[5] Logout.         \n";
	cout << "=================================================\n";
}

void ShowBalance()
{
	Screen("Check Balance Screen");

	cout << "\nYour Balance is " << CurrentClient.AccBal;
}

void Again(vector <Course7Test::stClient> vClients); 

void RefreshClientsBalance(vector <Course7Test::stClient>& vClients)
{
	for (Course7Test::stClient &C : vClients)
	{
		if (C.AccNumber == CurrentClient.AccNumber)
		{
			C.AccBal = CurrentClient.AccBal;
			break;
		}
	}
}

void LoadNewClientInfoToFile(vector <Course7Test::stClient> vClients)
{
	fstream myfile;
	string DataLine;

	myfile.open(ClientsFile, ios::out);


	if (myfile.is_open())
	{
		for (Course7Test::stClient &C : vClients)
		{
			DataLine = Course7Test::ConvertRecordToLine(C, "/###/");

			myfile << DataLine << endl;
		}
	}
	myfile.close();
}

bool IsAnswerYes(char Answer, short Choice, vector <Course7Test::stClient> &vClients)
{
	if (tolower(Answer) != 'y')
		return false;

	short DepositMoney[9] = { 20,50,100,200,400,600,800,1000 };

	if (CurrentClient.AccBal < DepositMoney[Choice - 1])
	{
		cout << "\nYour balance is not enough!";
		return false;
	}
	else
		CurrentClient.AccBal -= DepositMoney[Choice - 1];
		RefreshClientsBalance(vClients);
		LoadNewClientInfoToFile(vClients);
		return true;
}

void QuickWithdraw(vector <Course7Test::stClient> &vClients)
{
	Screen("Quick Withdraw");
	cout << setw(20) << "\n[1] 20 " << setw(20) << "[2] 50  ";
	cout << setw(20) << "\n[3] 100" << setw(20) << "[4] 200 ";
	cout << setw(20) << "\n[5] 400" << setw(20) << "[6] 600 ";
	cout << setw(20) << "\n[7] 800" << setw(20) << "[8] 1000";
	cout << setw(20) << "\n[9] Exit";
	cout << "\n----------------------------------------";

	cout << "\nYour Balance is " << CurrentClient.AccBal;

	short Choose = ReadNumberInRange("\nChoose what to do from [1] to [8]? ", 1, 9);
	char Answer;

	if (Choose == 9)
		Again(vClients);
	else
		cout << "\n\nAre you sure you want to perform this transaction y/n? ";
		cin >> Answer;
		if (IsAnswerYes(Answer, Choose, vClients))
		{
			cout << "\n\nDone Successfully. New balance is: " << CurrentClient.AccBal;
		}
		
    Again(vClients);
}

bool ConfirmRequest(string Message)
{
	char Answer = 'n';


	cout << Message;
	cin >> Answer;

	return (tolower(Answer) == 'y');
}

void NormalWithdraw(vector <Course7Test::stClient> vClients)
{
	Screen("Normal Withdraw Screen");

	int MoneyToWithdraw = 0;

	do
	{
		MoneyToWithdraw = ReadNumberInRange("\nPlease Enter an amount multiple of 5's ? ", 5, 100000);

	} while ((MoneyToWithdraw % 5) != 0);

	if (CurrentClient.AccBal < MoneyToWithdraw)
	{
		cout << "\nYour balance is not enough!";
		Again(vClients);
	}

	if (ConfirmRequest("\nAre you sure you want to perform this transaction[y / n] ? "))
	{
		CurrentClient.AccBal -= MoneyToWithdraw;
		RefreshClientsBalance(vClients);
		LoadNewClientInfoToFile(vClients);

		cout << "\n\nDone Successfully, New Balance is: " << CurrentClient.AccBal;
	}

	Again(vClients);
}

void Deposit(vector <Course7Test::stClient>& vClients)
{
	Screen("Deposit Screen");

	int MoneyToDeposit = ReadNumberInRange("\nEnter a positive Deposit Amount [From 100 to 10000] ? ", 100, 10000);

	if (ConfirmRequest("\nAre you sure you want to perform this transaction? y/n ? "))
	{
		CurrentClient.AccBal += MoneyToDeposit;
		RefreshClientsBalance(vClients);
		LoadNewClientInfoToFile(vClients);
	}
	Again(vClients);
}

void ManageClientRequest(vector <Course7Test::stClient> vClients, short Choice)
{
	switch (Choice)
	{
	case 1:
	{
		QuickWithdraw(vClients);
		Again(vClients);
		break;
	}
	case 2:
	{
		NormalWithdraw(vClients);
		Again(vClients);
		break;
	}
	case 3:
	{
		Deposit(vClients);
		Again(vClients);
		break;

	}
	case 4:
	{
		ShowBalance();
		Again(vClients);
		break;
	}
	case 5:
	{
		ReshowMenueScreen();
	}
	}
}

void MainMenue()
{

	Screen("Login Screen");

	vector < Course7Test::stClient> vClientsInfo = LoadFileDataToVector();

	short Choice = 0;

	CurrentClient = ReadAccount();
	
	while (!IsClientExtent(CurrentClient, vClientsInfo))
	{
		Screen("Login Screen");
		cout << "\nInvalaid Account Number/PinCode!";

		CurrentClient = ReadAccount();
	}

	ATMScreen();

	Choice = ReadNumberInRange("Choose what do you want to do? [1 to 5]? ", 1, 5);

	ManageClientRequest(vClientsInfo, Choice);
}




int  main()
{
    MainMenue();


	return 0;
}

void ReshowMenueScreen()
{
	MainMenue();
}

void Again(vector <Course7Test::stClient> vClients)
{
	cout << "\nPress any key to go back to Main Menue...";

	system("pause>0");

	ATMScreen();

	short Choice = ReadNumberInRange("Choose what do you want to do? [1 to 5]? ", 1, 5);

	ManageClientRequest(vClients, Choice);
}