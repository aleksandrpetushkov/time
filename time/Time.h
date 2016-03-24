#include <string>
#include <time.h>

class Time {

public:
	Time();
	Time(int hours, int min, int sec, int msec);
	Time addMSecs(int ms) const // порождает новый объект со сдвигом в миллисекундах
	{
		
	}
	Time addSecs(int s) const; // порождает новый объект со сдвигом в секундах
	int hour() const; // возвращает кол-во часов
	int minute() const; // возвращает кол-во минут
	int second() const; // возвращает кол-во секунд
	int msec() const; // возвращает кол-во миллисекунд
	bool isValid() const; // валидна ли дата
	int msecsTo(const Time & t) const // возвращает кол-во мсек до события
	{
		
	}
	int secsTo(const Time & t) const // возвращает кол-во сек до события 
	{
		
	}
	bool setHMS(int h, int m, int s, int ms = 0) // установить новую дату
	{
		
	}
	std::string toString(const std::string & format) const // преобразует в строку, согласно заданному формату
	{
		
	}
	bool operator!=(const Time & t) const
	{

	}
	bool operator<(const Time & t) const
	bool operator<=(const Time & t) const
	bool operator==(const Time & t) const
	bool operator>(const Time & t) const
	bool operator>=(const Time & t) const
	static currentTime(); // возвращает текущее время
	Time fromString(const std::string& str, const std::string & format)
	{
		
	}
protected:

}