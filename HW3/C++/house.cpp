
//........................................//
//Programmed and designed by Kiavash Fathi//
//Student number 9530863..................//
//........................................//


#include <iostream>
#include "house.h"

using namespace std;


double apartment::price()
{
	this->_price = (this->_area)*(this->_basePrice);
	cout << "The total price for this apartment is " << this->_price << endl;

	return this->_price;
}

apartment::apartment(int area, int basePrice, char* address, int level, bool hasElevator, int rentCommision, int sellCommision, int rentingPeriod,char* sellingCondition)
:house(area, basePrice, address, rentCommision, sellCommision, rentingPeriod,sellingCondition)
{
	this->_level = level;
	this->_hasElevator = hasElevator;
	this->_typeOfHouse = "apartment";

	cout << "House created is an apartment" << endl;

	//renting();  //this contains price() and calRahnAndRentingPrice()
	cout << "-----End of record-----" << endl << endl;
}

villa::villa(int area, int basePrice, char* address, int level, int gardenArea, int rentCommision, int sellCommision, int rentingPeriod, char* sellingCondition)
:house(area, basePrice, address, rentCommision, sellCommision,  rentingPeriod,sellingCondition)
{
	this->_levels = level;
	this->_gardenArea = gardenArea;
	this->_typeOfHouse = "villa";

	cout << "House created is a villa" << endl;

	//renting();  //this contains price() and calRahnAndRentingPrice()
	cout << "-----End of record-----" << endl << endl;
}

double villa::price()
{
	this->_price = (0.3)*(this->_gardenArea)*(this->_basePrice) + (this->_area)*(this->_basePrice);
	cout << "The total price for this villa is " << this->_price << endl;



	return this->_price;
}

house::house(int area, int basePrice, char* address, int rentCommision, int sellCommision, int rentingPeriod, char* sellingCondition)
{
	this->_area = area;
	this->_basePrice = basePrice;
	
	this->_address = address;
	this->_rentCommision = rentCommision;
	this->_sellCommision = sellCommision;
	this->_rentingPeriod = rentingPeriod;
	this->_sellingCondition = sellingCondition;

	cout << "---House item created---"<<endl;
	//this->price();    //bug????????
	
}

void house::calRahnAndRentingPrice()
{
	this->price();

	this->_rahn = (0.5)*(_price);
	this->_rentingRate = (0.1)*(_price);
}



double house::renting()
{
	calRahnAndRentingPrice();

	this->_rentingPrice = (this->_rahn)*(this->_rentCommision) + (this->_rahn) + (this->_rentingPeriod)*(this->_rentingRate);
	cout << "This house will be rented by the price of " << this->_rentingPrice << endl;


	cout << endl << endl << "Do you want to see the details? y/n" << " ";
	char response;
	cin >> response;
	if (response == 'y')
	{
		cout << endl << "---Details---" << endl<<
			"This " << this->_typeOfHouse << "`s rahn is " << this->_rahn << endl;
		cout << "And its renting rate is " << this->_rentingRate << endl;
		cout << "It will be rented for a period of " << this->_rentingPeriod << endl;
		cout << "-----------------------" << endl;


	}


	cout << endl << endl << "Would you like to change the details? y/n" << " ";
	cin >> response;
	if (response == 'y')
	{
		while (response != '0')
		{
			cout << endl << "What would you like to change?" << endl;
			cout << "Please enter: " << endl <<
				"1 for Renting Commsion" << endl <<
				"2 for Period of Renting" << endl <<
				"0 for aborting this action" << endl;

			cin >> response;

			if (response == '1')
			{
				cout << "Please enter the new renting commision : ";
				int x;
				cin >> x;
				this->_rentCommision = x;
				cout << "Value changed" << endl;
			}

			if (response == '2')
			{
				cout << "Please enter the new renting period : ";
				int x;
				cin >> x;
				this->_rentingPeriod = x;
				cout << "Value changed" << endl;
			}
			if (response == '0')
			{
				break;
			}
			cout <<endl<<endl<< "Anything else?" << endl;
			cout << "-----------------------" << endl;
		}

	}
	return this->_rentingPrice;
}


double house::selling()
{
	price();
	this->_sellPrice = (this->_sellCommision)*(this->_price) + this->_price;
	cout << "This house will be sold with the value of " << this->_sellPrice << endl;


	cout << "Do you want to see the details? y/n" << " ";
	char response;
	cin >> response;
	if (response == 'y')
	{
		cout <<endl<< "---Details---" << endl;
		cout << "This " << this->_typeOfHouse << " will be bought via " << this->_sellingCondition << endl;
		cout << "Its commision is " << this->_sellCommision << endl;
		cout << "-----------------------" << endl;

	}

	cout << "Would you like to change the details? y/n" << " ";
	cin >> response;
	if (response == 'y')
	{
		while (response != '0')
		{
			cout << endl << "What would you like to change?" << endl;
			cout << "Please enter: " << endl <<
				"1 for Selling Commsion" << endl <<
				"2 for Condition of selling (Cash or Check)" << endl <<
				"0 for aborting this action" << endl;

			cin >> response;

			if (response == '1')
			{
				cout << "Please enter the new selling commision : ";
				int x;
				cin >> x;
				this->_sellCommision = x;
				cout << "Value changed" << endl;
			}

			if (response == '2')
			{
				cout << "Please enter the new condition : ";
				char ch[100];
				cin >> ch;
				this->_sellingCondition = ch;
				cout << "Value changed" << endl;
			}
			if (response == '0')
			{
				break;
			}
			cout << endl << endl << "Anything else?" << endl;
			cout << "-----------------------" << endl;
		}
	}

	return this->_sellPrice;
}

void apartment::getHouseInformation()
{
	cout <<endl<< "-- Printing house info --"<<endl;

	cout << "This " << this->_typeOfHouse << " has the area of " <<
		this->_area << endl <<
		"And its base price is " << this->_basePrice << endl <<
		"And its price is " << this->_price << endl <<
		"and it is located in the following address : " << this->_address << endl;

	
	cout << "This apartment is located on the " << this->_level << "s level" << endl;
	
	if (this->_hasElevator == true)
		cout << "This apartment has an elevator" << endl;
	else
		cout << "This apartment doesn`t have an elevator" << endl;

	cout << "-----------------------" << endl<<endl;

}

void villa::getHouseInformation()
{
	cout <<endl<< "-- Printing house info --" << endl;

	cout << "This " << this->_typeOfHouse << " has the area of " <<
		this->_area << endl <<
		"And its base price is " << this->_basePrice << endl <<
		"And its price is " << this->_price << endl <<
		"and it is located in the following address : " << this->_address << endl;


	cout << "This villa has " << this->_levels << " floors" << endl;

	cout << "This villa has a gardon with the are of " << this->_gardenArea << endl;

	cout << "-----------------------" << endl<<endl;

}

bool search(house* hs, char* searchMethod)
{
	cout << endl << "-------Searching-------" << endl;
	
	if (searchMethod == "priceAndArea")
	{
		cout << "Please enter the minimum area and maximum base price" << endl;
		int ma, mbp;
		cin >> ma >> mbp;

		int found = 0;

		while (hs != NULL)
		{
			/*
			cout << "here" << endl;
			cout << hs->_area;
			cout << hs->_basePrice;
			*/
			
			if ((hs->_area > ma) && (hs->_basePrice < mbp))
			{
				cout << endl << "-----Match found-----" << endl;
				hs->getHouseInformation();
				cout << "-----------------------" << endl << endl;
				found = 1;
			}

			hs = hs->next;
		}
		if (hs == NULL && found==0)
		{
			cout << endl << "No match found" << endl;
		}

	}
	
	if (searchMethod == "Address")
	{
		cout << "Please enter the address" << endl;
		char ad[100];   //bug??
		//char* ad = "thisWillBeTheAddress";
		cin >> ad;

		/*
		cout << "here2" << endl;
		cout << hs->_address << "    " << ad << endl;
		*/

		int found = 0;

		while (hs != NULL)
		{
			cout << "Working" << endl;

			char* temp = hs->_address;
			if (strcmp(temp,ad)==0)
			{
				found = 1;
				cout << endl << "-----Match found-----" << endl;
				hs->getHouseInformation();
				cout << "-----------------------" << endl << endl;
			}

			hs = hs->next;
		}

		if (hs == NULL&&found == 0)
		{
			cout << endl << "No match found" << endl;
		}

	}


		return true;
}




house* house::getNext()
{
	return this->next;
}

void house::setNext(house* hs)
{
	this->next = hs;
}

void house::setSellCommision(int x)
{
	this->_sellCommision = x;
}

void house::setSellingCondition(char* x)
{
	this->_sellingCondition = x;
}

void house::setRentCommision(int x)
{
	this->_rentCommision = x;
}

void house::setRentPeriod(int x)
{
	this->_rentingPeriod = x;
}