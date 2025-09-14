#include <iostream>

class FlightBooking {
private:
    int id;
    int capacity;
    int reserved;

public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    int getID();
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    // Save data to members
    this->id = id;
    this->capacity = capacity;
    if (reserved <= capacity + capacity * .05)
    {
        this->reserved = reserved;
    }
    else
    {
        std::cout << "The reserved seats can not be higher than 105% the plane capacity";
        this->reserved = 0;
    }
}

FlightBooking::FlightBooking()
{
    // Initialize atributes
    this->id = 0;
    this->capacity = 0;
    this->reserved = 0;
}
int FlightBooking::getID()
{
    return this->id;
}

void FlightBooking::printStatus()
{
    // print report here
    if (id == 0) { return; }
    std::cout << "Flight [" << id << "] : " << reserved << "/" << capacity << " (" << 100 / capacity * reserved << " %) seats taken" << std::endl;

}

bool FlightBooking::reserveSeats(int number_of_seats)
{
    // try to add reservations and return 'true' on success
    // keep the limits in mind
    if (number_of_seats + reserved > capacity * 1.05)
    {
        std::cout << "The reserved seats can not be higher than 105% the plane capacity" << std::endl;
        return false;
    }

    reserved += number_of_seats;
    return true;
}

bool FlightBooking::cancelReservations(int number_of_seats)
{
    // try to cancel reservations and return 'true' on success
    // keep the limits in mind

    if (number_of_seats > reserved)
    {
        std::cout << "The canceled seats can not be higher than the reserved seats." << std::endl;
        return false;
    }

    reserved -= number_of_seats;
    return true;
}

int main() {
    const int Max_booking = 10;
    FlightBooking booking[Max_booking];


    //std::cout << "Provide flight capacity: ";

   // std::cout << "Provide number of reserved seats: ";

    std::string input = " ";
    while (1)
    {
        int reserved = 0;
        int capacity = 0;
        int seats = 0;
        int ID = 0;
        bool command_worked = false;
        input = " ";

        for (int idx = 0; idx < Max_booking;idx++)
        {
            booking[idx].printStatus();
        }

        std::cout << "What do you want to do?" << std::endl;
        std::cin >> input;

        if (input == "exit") { break; }
        if (input == "add")
        {
            std::cout << "Provide a flight ID: ";
            std::cin >> ID;
            std::cout << "Enter the amount of reservations you wish to add: ";
            std::cin >> seats;
            for (int idx = 0; idx < Max_booking;idx++)
            {
                if (booking[idx].getID() == ID)
                    command_worked = booking[idx].reserveSeats(seats);
            }
        }
        else if (input == "cancel")
        {
            std::cout << "Provide a flight ID: ";
            std::cin >> ID;
            std::cout << "Enter the amount of reservations you wish to cancel: ";
            std::cin >> seats;
            for (int idx = 0; idx < Max_booking;idx++)
            {
                if (booking[idx].getID() == ID)
                {
                    command_worked = booking[idx].cancelReservations(seats);
                }
            }
        }
        else if (input == "create")
        {
            bool Repeat = false;

            while (ID == 0) //Flight cant be 0
            {
                std::cout << "Provide a flight ID (cannot be 0): ";
                std::cin >> ID;
                if (ID == 0) {std::cout << "ID cant be 0";}
            }

            std::cout << "Provide flight capacity: ";
            std::cin >> capacity;
            std::cout << "Provide number of reserved seats: ";
            std::cin >> reserved;



            for (int idx = 0; idx < Max_booking;idx++) //Checking for repeat IDs
            {
                if (booking[idx].getID() == ID)
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
            
            for (int idx = 0; idx < Max_booking;idx++) //Creating the flight
            {
                if (booking[idx].getID() == 0)
                {
                    booking[idx] = FlightBooking(ID, capacity, reserved);
                    command_worked = true;
                    break;
                }
            }
        }
        else if (input == "delete")
        {
            std::cout << "Provide a flight ID: ";
            std::cin >> ID;


            for (int idx = 0; idx < Max_booking;idx++)
            {
                if (booking[idx].getID() == ID)
                {
                    booking[idx] = FlightBooking();
                    command_worked = true;
                    break;
                }
            }
        }
        else
        {
            std::cout << "Command not found";
        }

        if (!command_worked)
        {
            std::cout << "Cannot perform this operation";
        }
    }
    return 0;
}