#include <iostream>

class Subscriptions
{
private:
	int ID;
	std::string Name;
	int Months_left;
public:
	Subscriptions();
	Subscriptions(int ID, std::string Name, int Months_left);

	int getID() { return ID; }
	int getMonths_left() { return Months_left; }

	void SetMonths_left(int Months_left) { this->Months_left = Months_left; }
	void PrintStatus();
};

Subscriptions::Subscriptions()
{
	this->ID = 0;
	this->Name = " ";
	this->Months_left = 0;
}

Subscriptions::Subscriptions(int ID , std::string Name, int Months_left)
{
	this->ID = ID;
	this->Name = Name;
	this->Months_left = Months_left;
}

void Subscriptions::PrintStatus()
{
	if (ID == 0) { return; }
	std::cout << "User " << ID << " of the name: " << Name << ", has " << Months_left << " months of subscription left." << std::endl;
}

int main() 
{
	const int Max_members = 10;
	Subscriptions Members[Max_members];
	std::string Input = " ";

	while (1)
	{
		int ID = 0;
		std::string Name = " ";
		int Months = 0;
		bool Command_worked = false;

		Input = " ";

		std::cout << "\n--- Current Subscriptions ---\n";
		for (int idx = 0; idx < Max_members; idx++) {
			Members[idx].PrintStatus();
		}
		std::cout << "----------------------------\n";

		std::cout << "Welcome to the system, what do you want to do?" << std::endl;
		std::cin >> Input;

		if (Input == "quit") { break;}

		if (Input == "create")
		{
			bool Repeat = false;

			while (ID == 0) //Flight cant be 0
			{
				std::cout << "Provide a user ID (cannot be 0): ";
				std::cin >> ID;
				if (ID == 0) { std::cout << "ID cant be 0"; }
			}

			std::cout << "Provide the user's name: ";
			std::cin >> Name;


			for (int idx = 0; idx < Max_members;idx++) //Checking for repeat IDs
			{
				if (Members[idx].getID() == ID)
				{
					Repeat = true;
					break;
				}
			}
			if (Repeat)
			{
				std::cout << "IDs can't repeat...";
				continue;
			}

			for (int idx = 0; idx < Max_members;idx++) //Creating the member object
			{
				if (Members[idx].getID() == 0)
				{
					Members[idx] = Subscriptions(ID, Name, 0);
					Command_worked = true;
					break;
				}
			}
		}
		else if (Input == "delete")
		{
			std::cout << "Provide a user ID: ";
			std::cin >> ID;

			for (int idx = 0; idx < Max_members;idx++) //Deleting the member object
			{
				if (Members[idx].getID() == ID)
				{
					Members[idx] = Subscriptions();
					Command_worked = true;
					break;
				}
			}
			//std::cout << "ID not found" << std::endl;
		}
		else if (Input == "extend")
		{
			std::cout << "Provide a user ID: ";
			std::cin >> ID;
			std::cout << "How many months do you wish to add to their subscription?: ";
			std::cin >> Months;

			for (int idx = 0; idx < Max_members;idx++) //Deleting the member object
			{
				if (Members[idx].getID() == ID)
				{
					Members[idx].SetMonths_left(Months + Members[idx].getMonths_left());
					Command_worked = true;
					break;
				}
			}
			//std::cout << "ID not found" << std::endl;
		}
		else if (Input == "Cancel") 
		{
			std::cout << "Provide a user ID: ";
			std::cin >> ID;

			for (int idx = 0; idx < Max_members;idx++) //Setting remaining months to 0
			{
				if (Members[idx].getID() == ID)
				{
					Members[idx].SetMonths_left(0);
					Command_worked = true;
					break;
				}
			}
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
			continue;
		}

		if (!Command_worked)
		{
			std::cout << "Invalid operation" << std::endl;
		}
	}
}