#include "Serializer.hpp"

int main()
{
	Data d1;
	d1.name = "d1";
	d1.id = 1;
	std::cout << "Data: " << d1.name << std::endl;
	std::cout << "Id: " << d1.id << std::endl;

	uintptr_t uintD1 = Serializer::serialize(&d1);				// Convert memory addess of d1 to uintptr_t type
	uintptr_t *ptrUint = reinterpret_cast<uintptr_t *>(uintD1); // Convert uintptr_t memory addess to ptr hold uintptr_t memory addess
	std::cout << "Address: " << ptrUint << std::endl;

	std::cout << "--------------------------------\n";
	std::string *sD1 = reinterpret_cast<std::string *>(ptrUint);
	std::cout << "stringData: " << *sD1 << std::endl;
	*sD1 = "d2";
	std::cout << GREEN << "Update Name of data to d2!!" << DEFAULT << std::endl;
	sD1++;

	int *iD1 = reinterpret_cast<int *>(sD1);
	std::cout << "intId: " << *iD1 << std::endl;
	*iD1 = 2;
	std::cout << GREEN << "Update id of data to 2!!" << DEFAULT << std::endl;
	std::cout << "--------------------------------\n";

	Data *ptrD1 = Serializer::deserialize(uintD1);
	std::cout << "ptrData: " << ptrD1->name << std::endl;
	std::cout << "ptrId: " << ptrD1->id << std::endl;
	std::cout << "Address: " << ptrD1 << std::endl;
}
