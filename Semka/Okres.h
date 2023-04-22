#pragma once
#include "UzemnaJednotka.h"
#include <iostream>

class Okres : public UzemnaJednotka
{
private:
	std::string nazov_;

	std::string sortNumber_;
	std::string code_;
	std::string officialTitle_;
	std::string mediumTitle_;
	std::string shortTitle_;
	std::string note_;
public:
	Okres();
	Okres(std::string& paNazov) : nazov_(paNazov) {}
	Okres(std::string& paSortNumber, std::string paCode, std::string& paOffcicialTitle, std::string& paMediumTitle, std::string& paShortTitle, std::string& paNote) : sortNumber_(paSortNumber), code_(paCode), officialTitle_(paOffcicialTitle), mediumTitle_(paMediumTitle), shortTitle_(paShortTitle), note_(paNote) {}

	// kopírovací konštruktor
	Okres(const Okres& other) : sortNumber_(other.sortNumber_), code_(other.code_), officialTitle_(other.officialTitle_), mediumTitle_(other.mediumTitle_), shortTitle_(other.shortTitle_), note_(other.note_) {}

	// presunovací konštruktor
	Okres(Okres&& other) noexcept : sortNumber_(std::move(other.sortNumber_)), code_(std::move(other.code_)), officialTitle_(std::move(other.officialTitle_)), mediumTitle_(std::move(other.mediumTitle_)), shortTitle_(std::move(other.shortTitle_)), note_(std::move(other.note_)) {}

	// operátor kopírovania
	Okres& operator=(const Okres& other) {
		sortNumber_ = other.sortNumber_;
		code_ = other.code_;
		officialTitle_ = other.officialTitle_;
		mediumTitle_ = other.mediumTitle_;
		shortTitle_ = other.shortTitle_;
		note_ = other.note_;
		return *this;
	}

	// operátor presúvania
	Okres& operator=(Okres&& other) noexcept {
		sortNumber_ = std::move(other.sortNumber_);
		code_ = std::move(other.code_);
		officialTitle_ = std::move(other.officialTitle_);
		mediumTitle_ = std::move(other.mediumTitle_);
		shortTitle_ = std::move(other.shortTitle_);
		note_ = std::move(other.note_);
		return *this;
	}

	int method() const override { return 35; }
	std::string& getOfficial() override { return nazov_; }

	std::string& getSortNumber() override { return sortNumber_; }
	std::string& getCode() override { return code_; }
	std::string& getOfficialTitle() override { return officialTitle_; }
	std::string& getMediumTitle() override { return mediumTitle_; }
	std::string& getShortTitle() override { return shortTitle_; }
	std::string& getNote() override { return note_; }

	int codeLen() override { return 6; }
	int getLevel() override { return 1; }

	virtual ~Okres() 
	{
		nazov_ = "";

		//std::cout << "mazem okres" << std::endl;

		sortNumber_ = "";
		code_ = "";
		officialTitle_ = "";
		mediumTitle_ = "";
		shortTitle_ = "";
		note_ = "";
	}
};

