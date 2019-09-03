#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a = 3.1415926534;
	double b = 2006.0;
	double c = 1.0e-10;



	std::cout << std::setfill('x') << std::setw(10);
	std::cout << 77 << std::endl;

	std::cout << std::hex;
	std::cout << std::setiosflags(std::ios::showbase | std::ios::uppercase);
	//std::cout << std::ios::showbase << std::ios::uppercase;
	std::cout << 100 << std::endl;

	// oX64

	int x = std::cout.precision();

	std::cout << "default:\n";
	std::cout << a << '\n' << b << '\n' << c << '\n';

	std::cout.precision(5);

	std::cout << "precision 5:\n";
	std::cout << a << '\n' << b << '\n' << c << '\n';

	std::cout << '\n';

	std::cout << "fixed:\n" << std::fixed;
	std::cout << a << '\n' << b << '\n' << c << '\n';

	std::cout << '\n';

	std::cout << "scientific:\n" << std::scientific;
	std::cout << a << '\n' << b << '\n' << c << '\n';



	std::cout.precision(x);
	cout<<endl<<std::defaultfloat<< 100.32;
}
