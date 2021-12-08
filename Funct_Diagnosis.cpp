#include "Diagnosis.h"
#include <iostream>
#include <iomanip>



void Diagnosis::SetDiadnosis(Talon* talon, Disease* disease) {
	this->talon = talon;
	this->disease = disease;
}
void Diagnosis::PrintInfo() {
	Date date = this->talon->GetDate();
	Time time = this->talon->GetTime();
	std::array <std::string, 4> name = this->GetTalon().GetDoctor().GetFIO().GetInfo();

	std::cout << " ������: " << name[FIO::full_name] << std::endl;
	std::cout << " ���� �����: ";
	date.PrintInfo();
	std::cout << std::endl;
	std::cout << " ����� �����: ";
	time.PrintInfo();
	std::cout << std::endl;
	std::cout << " ����� ��������: ";
	std::cout << std::setfill('0') << std::setw(3) << this->GetTalon().GetKabinet() << std::endl;
	std::cout.fill(' ');
	this->GetDisease().PrintInfo();
}

bool Diagnosis::Empty() {
	bool Empty_Diagnosis = true;
	if (this->talon || this->disease)
		Empty_Diagnosis = false;
	return Empty_Diagnosis;
}

Talon Diagnosis::GetTalon() {
	return *this->talon;
}

Disease Diagnosis::GetDisease() {
	return *this->disease;
}

Disease* Diagnosis::GetAddressDisease() {
	return disease;
}

Disease& Diagnosis::GetLinkDisease() {
	return *disease;
}

Diagnosis::Diagnosis() {
	this->talon = nullptr;
	this->disease = nullptr;
}