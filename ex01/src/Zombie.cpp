#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "A new zombie is born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::setName(const std::string& name)
{
	this->_name = name;
}

void Zombie::announce() const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
