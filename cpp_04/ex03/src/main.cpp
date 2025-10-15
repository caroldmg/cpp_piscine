#include <AMateria.hpp>
#include <Character.hpp>
#include <MateriaSource.hpp>
#include <IMateriaSource.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define RESET   "\033[0m"

/* int main() {
    IMateriaSource* source = new MateriaSource();
    AMateria* new_ice = new Ice();
    AMateria* new_cure = new Cure();
    ICharacter* kevin = new Character("Kevin");
    ICharacter* dummy = new Character("Dummy");

    std::cout<<std::endl;

    source->learnMateria(new_ice);
    source->learnMateria(new_cure);
    
    AMateria* buffer0;
    AMateria* buffer1;

    buffer0 = source->createMateria("ice");
    std::cout<<"Materia type is: "<<buffer0->getType()<<std::endl;
    buffer1 = source->createMateria("cure");
    std::cout<<"Materia type is: "<<buffer1->getType()<<std::endl;
    kevin->equip(buffer0);

    std::cout<<std::endl;

    kevin->use(0, *dummy);
    kevin->use(1, *dummy);

    kevin->equip(buffer1);
    kevin->use(1, *dummy);

    kevin->use(5, *dummy);

    std::cout<<std::endl;

    kevin->unequip(1);
    kevin->unequip(0);
	

    std::cout<<std::endl;

    delete source;
    delete kevin;
    delete dummy;

    return 0;
} */

	int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;

}

/*
	✅ Extras que podrías agregar para probar más

Intentar aprender más de 4 materias (debe ser ignorado).

Intentar crear una materia desconocida (createMateria("fire")).

Probar unequip() y luego verificar que no se llame doble delete.

Usar herramientas como valgrind para comprobar fugas.z
*/