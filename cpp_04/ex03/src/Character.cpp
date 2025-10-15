#include "Character.hpp"

Character::Character() : name("no_name")
{
	for (int i = 0; i < 4; i++)
		this->mat[i] = NULL;
	for(int i = 0; i < 100; i++)
		this->floor[i] = NULL;
	// std::cout << "Default Character Constructor called" << std::endl;
}

Character::Character(std::string name): name(name)
{
	for (int i = 0; i < 4; i++)
		this->mat[i] = NULL;
	for(int i = 0; i < 100; i++)
		this->floor[i] = NULL;
	// std::cout << "Character " << name << " cnstructor called" << std::endl;
}

Character::Character(const Character &org): name(org.name)
{
	// std::cout << "Character copy constructor called" << std::endl;
	if (this != &org)
	{
		for (int i = 0; i < 4; i++)
		{
			if (org.mat[i])
			{
				mat[i] = org.mat[i]->clone();
				this->floor[i] = org.floor[i]->clone();
			}
			else
			{
				mat[i] = NULL;
				this->floor[i] = NULL;
			}
		}
	}
}

Character& Character::operator=(const Character& org)
{
	// std::cout << "Character assignment operator called" << std::endl;
	if (this != &org)
	{
		name = org.name;
		for (int i = 0; i< 4; i++)
		{
			delete (mat[i]);
			mat[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (org.mat[i])
				mat[i] = org.mat[i]->clone();
			else
				mat[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete (mat[i]);
	this->cleanFloor();
	// std::cout << "Character destructor called" << std::endl;
}

// Métodos de clase

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Can't equip materia: nonexistent" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (mat[i] == NULL)
		{

			mat[i] = m;
			// std::cout << "Equipped materia " << this->mat[i]->getType() << std::endl;
			return ;
		}
	}
	// std::cout << "Cannot equip materia: " << this->getName() << "'s inventory is full!" << std::endl;
}


void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "Wrong materia index" << std::endl;
		return ;
	}

	if (this->mat[idx])
	{
		this->mat[idx]->use(target);
		return ;
	}
	std::cout << "Wrong index or materia " << std::endl;
}


void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (mat[idx])
	{
		for(int i = 0; i < 100; i++)
		{
			if (!floor[i])
			{
				floor[i] = mat[idx];
				std::cout << this->getName() << " unequipped materia " << mat[idx]->getType() << " and left it on the floor" << std::endl;
				break ;
			}
			if (i == 99)
				std::cout << "Floor is full, if I leave something else I will start loosing things" << std::endl;
		}
		mat[idx] = NULL;
	}
}

void Character::cleanFloor()
{
	int i = 0;
	while (i < 100 && floor[i] != NULL)
	{
		if (floor[i])
			delete (floor[i]);
		i++;
	}
}
