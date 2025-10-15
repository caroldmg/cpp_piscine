#pragma once
#include "AMateria.hpp"

class AMateria;
class ICharacter
{
	public:

		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

// una interfaz se puede ver como una clase cuyos metodos son todos virtuale sy ninguno está definido. Así, no se puede instanciar esta clase más ue por medio de una clase que herede de esta y que tenga estos métodos sobreescritos e implementados.