#include  "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	// std::cout << "Default MateriaSource Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->mats[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& org)
{
	// std::cout << "Copy MateriaSource Constructor called" << std::endl;
	if (this != &org)
	{
		for (int i = 0; i < 4; i++)
		{
			if (org.mats[i])
				mats[i] = org.mats[i]->clone();
			else
				mats[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& org)
{
	// std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &org)
	{
		for (int i = 0; i< 4; i++)
		{
			delete (mats[i]);
			mats[i] = NULL;
		}

		for (int i = 0; i < 4; i++)
		{
			if (org.mats[i])
				mats[i] = org.mats[i]->clone();
			else
				mats[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->mats[i])
			delete mats[i];
	}
	// std::cout << "Default MateriaSource Destructor called" << std::endl;
}

// Métodos de clase

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << "nonexistent materia cannot be learned" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->mats[i])
		{
			this->mats[i] = materia;
			// std::cout << "The materia " << materia->getType() << " has been learned" << std::endl;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type == this->mats[i]->getType())
		{
			// std::cout << "Created the materia " << type << std::endl;
			return (this->mats[i]->clone());
		}
	}
	std::cout << "Can't create materias form unknown types" << std::endl;
	return (NULL);
}
