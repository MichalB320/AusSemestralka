#pragma once
#include "UzemnaJednotka.h"

class Kraj : public UzemnaJednotka
{
private:
	std::string nazov_;

	std::string sortNumber_;
	std::string code_;
	std::string officialTitle_;
	std::string mediumTitle_;
	std::string shortTitle_;
	std::string note_ = 0;
public:
	Kraj() {}
	Kraj(std::string paNazov) : nazov_(paNazov) {}
	Kraj(std::string paSortNumber, std::string paCode, std::string paOffcicialTitle, std::string paMediumTitle, std::string paShortTitle, std::string paNote) : sortNumber_(paSortNumber), code_(paCode), officialTitle_(paOffcicialTitle), mediumTitle_(paMediumTitle), shortTitle_(paShortTitle), note_(paNote) {}

	int method() const override { return 30; }
	std::string& getOfficial() override { return nazov_; }

	std::string& getSortNumber() override { return sortNumber_; }
	std::string& getCode() override { return code_; }
	std::string& getOfficialTitle() override { return officialTitle_; }
	std::string& getMediumTitle() override { return mediumTitle_; }
	std::string& getShortTitle() override { return shortTitle_; }
	std::string& getNote() override { return note_; }

	int codeLen() override { return 1; }
	int getLevel() override { return 0; }

	virtual ~Kraj() 
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

