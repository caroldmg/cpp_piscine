#pragma once
#include <iostream>
#include <stdint.h>

struct Data
{
	int i;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& org);
		~Serializer();
		Serializer& operator=(const Serializer& org);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};