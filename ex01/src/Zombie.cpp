#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
	std::cout << "A new zombie is born" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "A new zombie named " << this->_name << " is born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::setName(const std::string& name)
{
	this->_name = name;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
