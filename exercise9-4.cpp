/*Instructions
Write a program to help a local restaurant automate its breakfast billing system. The program should do the following:

Show the customer the different breakfast items offered by the restaurant.
Allow the customer to select more than one item from the menu.
Calculate and print the bill.
Assume that the restaurant offers the following breakfast items (the price of each item is shown to the right of the item):

food	Price
Plain Egg	$1.45
Bacon and Egg	$2.45
Muffin	$0.99
French Toast	$1.99
Fruit Basket	$2.49
Cereal	$0.69
Coffee	$0.50
Tea	$0.75
Use an array menuList of type menuItemType, as defined in Programming Exercise 3. Your program must contain at least the following functions:

Function getData: This function loads the data into the array menuList.
Function showMenu: This function shows the different items offered by the restaurant and tells the user how to select the items.
Function printCheck: This function calculates and prints the check. (Note that the billing amount should include a 5% tax.)*/

// Solution 

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;
	 
//struct for menuItemType
	struct menuItemType
	{
	    string menuItem;
	    double menuPrice;
	};
	void getData(menuItemType menuList[]);
	void showMenu(menuItemType menuList[], int x);
	void printCheck(menuItemType menuList[], int menuOrder[], int x);
	 
	int main()
	{
	 
	    // Declare functions and variables
	    const int menuItems = 8;
	    menuItemType menuList[menuItems];
		  int menuOrder[menuItems] = {0};
	    int orderChoice = 0;
	    bool ordering = true;
      char selection = ' ';

	    // Set the menu
	    getData(menuList);

	    // Order
	    showMenu(menuList, menuItems);
	    while(ordering)
	    {
	        cout << "Do you want to make selection Y/y (Yes), N/n (No): ";
          cin >> selection;
          if (selection == 'Y' || selection == 'y')
          {
            cout << "Enter item number: ";
            cin >> orderChoice;
          }
          else ordering = false;
	        if (orderChoice > 0 && orderChoice <= menuItems)
	        {
	            menuOrder[orderChoice - 1] += 1;
	        }
	        else
	            ordering = false;
	    }
      // Print check
	    printCheck(menuList, menuOrder, menuItems);
		cin.ignore(2);
	    return 0;
	}
	 
	void getData(menuItemType menuList[])
	{
	    // Declare menuItemTypes
	    menuItemType plainEgg;
	    menuItemType baconEgg;
	    menuItemType muffin;
	    menuItemType frenchToast;
	    menuItemType fruitBasket;
	    menuItemType cereal;
	    menuItemType coffee;
	    menuItemType tea;
	 
	    // Initialize menuItemTypes variables
	    plainEgg.menuItem = "Plain Egg";
	    plainEgg.menuPrice = 1.45;
	    baconEgg.menuItem = "Bacon and Egg";
	    baconEgg.menuPrice = 2.45;
	    muffin.menuItem = "Muffin";
	    muffin.menuPrice = 0.99;
	    frenchToast.menuItem = "French Toast";
	    frenchToast.menuPrice = 1.99;
	    fruitBasket.menuItem = "Fruit Basket";
	    fruitBasket.menuPrice = 2.49;
	    cereal.menuItem = "Cereal";
	    cereal.menuPrice = 0.69;
	    coffee.menuItem = "Coffee";
	    coffee.menuPrice = 0.50;
	    tea.menuItem = "Tea";
	    tea.menuPrice = 0.75;
	 
	    menuList[0] = plainEgg;
	    menuList[1] = baconEgg;
	    menuList[2] = muffin;
	    menuList[3] = frenchToast;
	    menuList[4] = fruitBasket;
	    menuList[5] = cereal;
	    menuList[6] = coffee;
	    menuList[7] = tea;
	}
	 
	void showMenu(menuItemType menuList[], int x)
	{
	    // Function variables
	    int count;
	 
	    cout << "Welcome to Johnny's Resturant" << endl;
      cout << "----Today's Menu----" << endl;
	    for(count = 0; count < x; count++)
	    {
          cout << fixed << showpoint << setprecision(2);
	        cout << left << count + 1 << ": "<< setw(14) << left
	             << menuList[count].menuItem << '$' 
	             << menuList[count].menuPrice << endl;
	    }
      cout << "You can make up to 8 single order selections" << endl;
	}
	 
	void printCheck(menuItemType menuList[], int menuOrder[], int menuItems)
	{
	    double checkTotal = 0;
	    double checkTax = 0;
	    const double TAX = .05;
	  
	    for(int i = 0; i < menuItems; i++)
	    {
			if(menuOrder[i] > 0) {
				cout << setprecision(2) << setw(14) << left << menuList[i].menuItem
					 << '$' << (menuList[i].menuPrice) << endl;
				checkTotal += (menuList[i].menuPrice);
			}
	    }
	    checkTax = checkTotal * TAX;
	    checkTotal += checkTax;
	    cout << fixed << showpoint << setprecision(2) << setw(14) << left << "Tax" << 
        '$' << checkTax << endl << setw(14) << left << "Amount Due" << '$' << checkTotal << endl;
	}
