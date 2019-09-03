
//........................................//
//Programmed and designed by Kiavash Fathi//
//Student number 9530863..................//
//........................................//



#ifndef HOUSE_H
#define HOUSE_H


//namespace housingSystem
//{

	class house
	{
	protected:

		//General info
		int _area;
		int _basePrice;
		double _price;

		char* _address;
		char* _typeOfHouse;


		//Renting info
		double _rentingPrice;
		int _rentCommision;
		double _rahn;
		double _rentingRate;
		int _rentingPeriod;


		//Selling info
		char* _sellingCondition;
		int _sellCommision;
		double _sellPrice;

		house* next;



	public:
		house(int area, int basePrice, char* address,
			int rentCommision = 0, int sellCommision = 0, int rentingPeriod = 0, char* sellingCondition = "Cash");

		virtual double price() = 0;

		double renting();
		void calRahnAndRentingPrice();

		double selling();

		virtual	void getHouseInformation() = 0;

		friend bool search(house*, char* searchingMethod);

		house* getNext();
		

		void setNext(house* hs);
		

		void setSellCommision(int x);
		

		void setSellingCondition(char* x);
		

		void setRentCommision(int x);
		

		void setRentPeriod(int x);
		

	};


	class apartment : public house
	{
	private:
		int _level;
		bool _hasElevator;

		apartment* _next;

	public:
		apartment(int area, int basePrice, char* address, int level, bool hasElevator,
			int rentCommision = 0, int sellCommision = 0, int rentingPeriod = 0, char* sellingCondition = "cash");
		double price();

		void getHouseInformation();
	};


	class villa : public house
	{
	private:

		int _levels;
		int _gardenArea;


		villa* _next;

	public:
		villa(int area, int basePrice, char* address, int level, int gardenArea,
			int rentCommision = 0, int sellCommision = 0, int rentingPeriod = 0, char* sellingCondition = "cash");
		double price();

		void getHouseInformation();
	};


//}

#endif // !1
