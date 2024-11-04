

#include "Bureaucrat.hpp"

int main(void)
{
 
	try
	{

		Bureaucrat khalid;
    	Bureaucrat yassin("yassin", 50);
    	Bureaucrat hmida("hmida", 150);
		
		std::cout << khalid << std::endl;
		std::cout << yassin << std::endl;
		std::cout << hmida << std::endl;
		// khalid.add();
		// hmida.sub();
		// for (int i = 0; i < 10; i++)
		// {
		// 	yassin.add();
		// 	std::cout << yassin << std::endl;
		// }
		// for (int i = 0; i < 10; i++)
		// {
		// 	yassin.sub();
		// 	std::cout << yassin << std::endl;
		// }
		// while (1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}