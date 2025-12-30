#include "Serializer.hpp"

int main()
{
	{
		Data *d = new Data;
		Data *d2;
		uintptr_t p;
		
		std::cout << "puntero Data original --> " << d << std::endl;
		p = Serializer::serialize(d);
		std::cout << "resultado de serialize --> " << p << std::endl;
		d2 = Serializer::deserialize(p);
		std::cout << "resultado de deserialize (back to data) --> " << d2 << std::endl;
	}
	{
		std::cout << "--------------" << std::endl;
		uintptr_t p = 57;
		std::cout << "p ---> " << p << std::endl;
		Data *d = Serializer::deserialize(p);
		std::cout << "p deserialized --> " << d << std::endl;
		std::cout << "p serialized again --> " << Serializer::serialize(d) << std::endl;
	}
}