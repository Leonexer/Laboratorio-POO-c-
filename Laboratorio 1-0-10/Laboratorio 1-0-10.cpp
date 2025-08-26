#include <iostream>

class ShopItemOrder
{
	// Write your code here
private:
std::string item_name;
double item_price;
int items_ordered;

public:
	//Constructor
	ShopItemOrder(std::string item_name, double item_price, int items_ordered); 

	//Getters y setters
	void set_item_name(std::string item_name) { this->item_name = item_name; } 
	std::string get_item_name() { return item_name; }

	void set_item_price(double item_price) { this->item_price = item_price; }
	double get_item_price() { return item_price; }

	//Métodos
	double get_total_order() {return item_price * items_ordered;}
	
	void print_order();
};

ShopItemOrder::ShopItemOrder(std::string item_name, double item_price, int items_ordered) 
{
	this->item_name = item_name;
	this->item_price = item_price;
	this->items_ordered = items_ordered;
}

void ShopItemOrder::print_order() 
{
	std::cout << items_ordered << " " << item_name << " // $" << get_total_order() << std::endl;
}

int main()
{
	ShopItemOrder Pozol("Pozol bien frío", 35, 2);
	ShopItemOrder Hotcakes("Pancakes", 30, 5);

	Pozol.print_order();
	Hotcakes.print_order();

}