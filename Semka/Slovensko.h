#pragma once
#include "UzemnaJednotka.h"
#include <string>

class Slovensko : public UzemnaJednotka
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
	Slovensko() {
		nazov_ = "Slovensko";

		sortNumber_ = "1";
		code_ = "SK";
		officialTitle_ = "Slovenská republika";
		mediumTitle_ = "Slovensko";
		shortTitle_ = "SVK";
		note_ = "000000000000001";
	}

	int method() const override { return 25; }
	std::string& getOfficial() override { return nazov_; }
	
	std::string& getSortNumber() override { return sortNumber_; }
	std::string& getCode() override { return code_; }
	std::string& getOfficialTitle() override { return officialTitle_; }
	std::string& getMediumTitle() override { return mediumTitle_; }
	std::string& getShortTitle() override { return shortTitle_; }
	std::string& getNote() override { return note_; }

	int codeLen() override { return 0; }
	int getLevel() override { return -1; }

	virtual ~Slovensko() 
	{
		nazov_ = "";

		sortNumber_ = "";
		code_ = "";
		officialTitle_ = "";
		mediumTitle_ = "";
		shortTitle_ = "";
		note_ = "";
	}
};

