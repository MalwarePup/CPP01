#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main()
{
	std::cout << "Creating a heap allocated Zombie named Foo" << std::endl;
	Zombie* z = newZombie("Foo");
	z->announce();
	delete z;
	std::cout << "\nCreating a stack allocated Zombie named Bar" << std::endl;
	randomChump("Bar");
	return 0;
}
