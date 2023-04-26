#pragma once
#include <string>

class UzemnaJednotka
{
protected:
	//std::string nazov_;
public:
	virtual int method() const = 0;
	virtual std::string& getOfficial() = 0;

	virtual std::string& getSortNumber() = 0;
	virtual std::string& getCode() = 0;
	virtual std::string& getOfficialTitle() = 0;
	virtual std::string& getMediumTitle() = 0;
	virtual std::string& getShortTitle() = 0;
	virtual std::string& getNote() = 0;

	virtual int codeLen() = 0;
	virtual int getLevel() = 0;


	//UzemnaJednotka();

	//UzemnaJednotka(std::string nazov) : nazov_(nazov) {}
	//sortNumber;code;officialTitle;mediumTitle;shortTitle;note

	virtual ~UzemnaJednotka() {	}
};

