
//........................................//
//Programmed and designed by Kiavash Fathi//
//Student number 9530863..................//
//........................................//

#include <iostream>
#include "house.h"

using namespace std;
//using namespace housingSystem;

int main()
{
	int numOfApartments = 0;
	int numOfVillas = 0;

	apartment* rootApartment = NULL;
	villa* rootVilla = NULL;


	cout << "Housing system initialized" << endl;
	cout << "Programmed and designed by Kiavash Fathi and Mahdi Alikhasti" << endl;
	cout << "-----------------------" << endl << endl;

	char ch;
	records:do
	{
		cout << "Please enter :" << endl <<
			"1 for creating an apartment record" << endl <<
			"2 for creating a villa record" << endl;

		int choice;
		cin >> choice;

		///////////
		if (choice == 1)
		{
			int area, basePrice, level;
			char address[100];
			bool hasElevator;
			
			cout << "Please enter the follwong information of the house" << endl;
			cout << "Area of the house: ";
			cin >> area;
			cout << "The base price: ";
			cin >> basePrice;
			cout << "On which level is it? ";
			cin >> level;
			cout << "Address: ";
			cin >> address;
			cout << "Does it have an elevator? y/n ";
			char x;
			cin >> x;
			if (x == 'y')
				hasElevator = true;
			else
				hasElevator = false;


			apartment ap(area, basePrice, address, level, hasElevator);

			if (numOfApartments == 0)
			{
				apartment firstap(area, basePrice, address, level, hasElevator);
				rootApartment = &firstap;
				numOfApartments++;
			}

			apartment* helper;
			helper = rootApartment;
			while (helper->getNext() != NULL)
			{
				helper = (apartment*)helper->getNext();
			}
			helper->setNext(&ap);
			ap.setNext(NULL);


			cout << "Do you want to sell it or rent it? s/r " << endl;
			char rOrs;
			cin >> rOrs;
			if (rOrs == 's')
			{
				int sellCommision;
				char sellingCondition[100];

				cout << "Please enter the selling commision: ";
				cin >> sellCommision;
				cout << "What is the selling condition? ";
				cin >> sellingCondition;

				ap.setSellCommision(sellCommision);
				ap.setSellingCondition(sellingCondition);

				cout << endl << endl;

				ap.selling();
			}

			if (rOrs == 'r')
			{

				int rentCommision;
				int rentingPeriod;

				cout << "Please enter the renting commision: ";
				cin >> rentCommision;
				cout << "For how long? ";
				cin >> rentingPeriod;

				ap.setRentPeriod(rentingPeriod);
				ap.setRentPeriod(rentingPeriod);


				cout << endl << endl;
				ap.renting();
			}

			
		}
		///////////
		else if (choice == 2)
		{
			int area, basePrice, levels,gardenArea;
			char address[100];

			cout << "Please enter the follwong information of the house" << endl;
			cout << "Area of the house: ";
			cin >> area;
			cout << "The base price: ";
			cin >> basePrice;
			cout << "How many levels does it have? ";
			cin >> levels;
			cout << "Address: ";
			cin >> address;
			cout << "How big is the garden? ";
			cin >> gardenArea;


			villa vl(area, basePrice, address,levels,gardenArea);

			if (numOfVillas == 0)
			{
				villa firstvl(area, basePrice, address, levels, gardenArea);
				rootVilla = &firstvl;
				numOfVillas++;
			}

			villa* helper;
			helper = rootVilla;
			while (helper->getNext() != NULL)
			{
				helper = (villa*)helper->getNext();
			}
			helper->setNext(&vl);
			vl.setNext(NULL);

			cout << "Do you want to sell it or rent it? s/r " << endl;
			char rOrs;
			cin >> rOrs;
			if (rOrs == 's')
			{
				int sellCommision;
				char sellingCondition[100];

				cout << "Please enter the selling commision: ";
				cin >> sellCommision;
				cout << "What is the selling condition? ";
				cin >> sellingCondition;

				vl.setSellCommision(sellCommision);
				vl.setSellingCondition(sellingCondition);

				cout << endl << endl;

				vl.selling();
			}

			if (rOrs == 'r')
			{

				int rentCommision;
				int rentingPeriod;

				cout << "Please enter the renting commision: ";
				cin >> rentCommision;
				cout << "For how long? ";
				cin >> rentingPeriod;

				vl.setRentPeriod(rentingPeriod);
				vl.setRentPeriod(rentingPeriod);


				cout << endl << endl;
				vl.renting();
			}


		}
		else
		{
			cout << "Wrong input" << endl;
		}
		//////////////


		cout << endl << endl << "Do you want to creat any other record? y/n ";
		cin >> ch;

	}while(ch == 'y');


	cout << endl << endl << "Do you want to search through the records? y/n ";
	char response;
	cin >> response;
	if (response == 'y')
	searching: {
		
		do{
			cout << "How do you want to search?" << endl <<
				"1.Via base price and area" << endl <<
				"2.Via Address" << endl << endl << endl;
			int x;
			cin >> x;

			char* method;
			if (x == 1)
				method= "priceAndArea";
			if (x == 2)
				method = "Address";

			if (rootApartment != NULL){
				cout << "Searching through apartments: " << endl;

				apartment* helpRooterApartment = rootApartment;
				search(helpRooterApartment, method);
				cout << "-----------------------" << endl << endl;
			}

			if (rootVilla != NULL){
				villa* helpRooterVilla = rootVilla;
				cout << "Searching through villas" << endl;
				search(helpRooterVilla, method);
				cout << "-----------------------" << endl << endl;
			}
			
			cout << "Do you want to run any other search? y/n ";
			cin >> ch;
		} while (ch == 'y');

		

	}


	char exitOrNot;

	do{
		cout << endl << endl << "Do you want to creat any other new records? y/s " << endl;
		char ch;
		cin >> ch;
		if (ch == 'y')
			goto records;

		cout << endl << endl << "Do you want to run any search? y/s" << endl;
		cin >> ch;
		if (ch == 'y')
			goto searching;

		cout << endl << endl << "Do you want to get the list of the houses? y/n " << endl;
		cin >> ch;
		if (ch == 'y'){
			cout << "1 for apartments" << endl <<
				"2 for villas" << endl;

			int xx;
			cin >> xx;
			if (xx == 1)
			{
				cout << endl << endl << "Listing the apartemets" << endl;
				//////////////////////////////////////
				apartment* helpRooterApartment = rootApartment;
				while (helpRooterApartment != NULL)
				{
					//cout << "entered" << endl;
					helpRooterApartment->getHouseInformation();
					cout << "-----------------------" << endl << endl;

					helpRooterApartment = (apartment*)(helpRooterApartment->getNext());
				}




			}
			else if (xx == 2)
			{
				cout << endl << endl << "Listing the villas" << endl;
				//////////////////////////////////////
				villa* helpRooterVilla = rootVilla;
				while (helpRooterVilla != NULL)
				{
					helpRooterVilla->getHouseInformation();
					cout << "-----------------------" << endl << endl;

					helpRooterVilla = (villa*)(helpRooterVilla->getNext());
				}




			}
		}
		cout << "Do you want to exit? y/n " << endl;
		
		cin >> exitOrNot;
	} while (exitOrNot != 'y');


	/*
	apartment a(5, 6, 1.3, "mir", 7,8, 3, false,8);
	
	villa v(4, 3, 1, "kish", 9, 4,9, 23,7);

	a.selling();

	v.selling();

	a.getHouseInformation();

	v.getHouseInformation();

	//search(a);
	*/


	system("pause");
	return 0;
}