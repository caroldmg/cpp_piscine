#include "../inc/Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		// creacion normal de forms
		Form f0;
		std::cout << "---- \n" << f0 << "\n ---- " << std::endl;

		Form f1("cosa complicada", 100, 42);
		Form f2(f1);
		f0 = f2;

		std::cout << "---- \n" << f1 << " \n ---- " << std::endl;
		std::cout << "---- \n" << f2 << "\n ---- " << std::endl;
		std::cout << "---- \n" << f0 << "\n ---- " << std::endl;
	}
	{
		// errores en la creacion de forms
		std::cout << "---- ERRORES EN LA CREACION DE FORMS ----" << std::endl;
		try
		{
			Form form("form1", 151, 70);
			// Form f1("form1", 100, 0);
			// Form f1("form1", 0, 70);
			// Form f1("form1", 0, 151);

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	{
		std::cout << "---- AHORA VAMOS LAS FIRMAS DE FORMULARIOS ----" << std::endl;
		try
		{
			// Form toSign("aprobar a Carol", 42, 42);
			Form toSign("aprobar a Carol", 150, 42);
			
			Bureaucrat bur("Corrector majísimo", 100);

			bur.signForm(toSign);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
