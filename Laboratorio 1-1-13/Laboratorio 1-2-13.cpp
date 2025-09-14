#include <iostream>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
private:
    int id;
    int capacity;
    int reserved;
};

void FlightBooking::printStatus()
{
    // print report here
    std::cout << "Flight [" << id << "] : " << reserved << "/" << capacity << " (" << 100 / capacity * reserved << " %) seats taken" << std::endl;

}

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

bool FlightBooking::reserveSeats(int number_of_seats)
{
    // try to add reservations and return 'true' on success
    // keep the limits in mind
    if (number_of_seats + reserved > capacity*.05)
    { 
        std::cout << "The reserved seats can not be higher than 105% the plane capacity"<<std::endl;
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
         std::cout << "The canceled seats can not be higher than the reserved seats."<< std::endl;
         return false; 
     }

     reserved -= number_of_seats;
     return true;
}

int main() {
    int reserved = 0,
        capacity = 0;
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;

    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;

    FlightBooking booking(1, capacity, reserved);


    std::string input = " ";
    while (1)
    {
        int seats = 0;
        bool command_worked = false;
        input = " ";
        
        booking.printStatus();
        std::cout << "What do you want to do?" << std::endl;
        std::cin >> input;

        if (input == "add")
        {
            std::cout << "Enter the amount of reservations you wish to add: ";
            std::cin >> seats;
            command_worked = booking.reserveSeats(seats);
        }
        else if (input == "cancel")
        {
            std::cout << "Enter the amount of reservations you wish to cancel: ";
            std::cin >> seats;
            command_worked = booking.cancelReservations(seats);
        }
        else if (input == "exit")
        {
            std::cout << "Goodbye!";
            break;
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