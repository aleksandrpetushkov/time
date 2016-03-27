#include <string>
#include <time.h>

class Time {

public:
	Time()
	{
		
	}
	Time(int const hours, int const min, int const sec, int const msec)
	{
		_hours = 0;
		_min = 0;
		_sec = 0;
		_msec = 0;
		addHours(hours);
		addMin(min);
		addSec(sec);
		addMsec(msec);
		
	}
	Time addMSecs(int ms) const // порождает новый объект со сдвигом в миллисекундах
	{
		
	}
	Time addSecs(int s) const // порождает новый объект со сдвигом в секундах
	{
		Time result(_hours, _min, _sec, _msec);
		result.addSecs(s);
		return result;

	}
	int H() const // возвращает кол-во часов
	{
		return _hours;
	}
	int M() const // возвращает кол-во минут
	{
		return _min;
	}
	int S() const // возвращает кол-во секунд
	{
		return _sec;
	}
	int Ms() const // возвращает кол-во миллисекунд
	{
		return _msec;
	}

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
		if (_hours == t.H() && _min == t.M() && _sec == t.S() && _msec == t.Ms())
		{
			return false;
		}
		else 
		{
			return true;
		}
		
	}
	bool operator<(const Time & t) const
	{
		if (_hours < t.H())
		{
			return true;
		}
		else if(_hours==t._hours)
		{
			if(_min<t._min)
			{
				return true;
			}
			else if(_min==t._min)
			{
				if(_sec<t._sec)
				{
					return true;
				}
				else if(_sec==t._sec)
				{
					if(_msec<t._msec)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	bool operator==(const Time & t) const
	{
		if((*this)!=t)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool operator>(const Time & t) const
	{
		if((*this)<t)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool operator>=(const Time & t) const
	{
		if((*this)>t||(*this==t))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const Time & t) const
	{
		if((*this)<t||(*this)==t)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	static Time currentTime() // возвращает текущее время
	{
		int tm = time(NULL);
	}

	Time fromString(const std::string& str, const std::string & format)
	{
		
	}
	void addHours(const int hours)
	{
		if (_hours + hours >= 24)
		{

			_hours = _hours+hours % 24;
		}
		else if (_hours + hours < 0)
		{
			if(_hours + hours % 24==0)
			{
				_hours = 0;
			}
			else
			{
				_hours = 24 + (_hours + hours % 24);

			}
		}
		else
		{
			_hours += hours;
		}
	}
	
	void addMin(const int min)
	{
		if (_min + min >= 60)
		{
			addHours((_min + min) / 60);
			_min = _min + min % 60;
			
		}
		else if (_min + min <0)
		{
			if(_min+min%60==0)
			{
				addHours(_min+min/60);
			}
			else
			{
				addHours((_min + min / 60) - 1);
				_min = 60 + _min + min % 60;
			}
		}
		else
		{
			_min += min;
		}
	}

	void addSec(const int sec)
	{
		if (_sec + sec >= 60)
		{
			addMin(_sec + sec / 60);
			_sec = _sec + sec % 60;
		}
		else if(_sec+sec<0)
		{
			if(_sec+sec%60==0)
			{
				addMin(_sec + sec / 60);
			}
			else
			{
				addMin((_sec + sec / 60) - 1);
				_sec = 60 + _sec + sec % 60;
			}
		}
		else
		{
			_sec = sec;
		}
	}
	void addMsec(const int msec)
	{
		if (_msec + msec >= 1000 )
		{
			addSec(_msec + msec / 1000);
			_msec = _msec + msec % 1000;
		}
		else if(_msec+msec<0)
		{
			if(_msec+msec%1000==0)
			{
				addSec(_msec + msec / 1000);
			}
			else
			{
				addSec((_msec + msec / 1000) - 1);
				_msec = 1000 + _msec + msec % 1000;
			}
		}
		else 
		{
			_msec += msec;
		}
	}
	
	
protected:
	int _hours, _min, _sec, _msec;
	

};

std::ostream & operator<<(std::ostream &output, const Time tm )
{
	if (tm.H()<10)
	{
		output << 0;
	}
	output << tm.H() << ":";
	if (tm.M()<10)
	{
		output << 0;
	}
	output << tm.M() << ":";
	if (tm.S()<10)
	{
		output << 0;
	}
	output << tm.S() << ":";
	if (tm.Ms()<100)
	{	
		if (tm.Ms() < 10)
		{
			output << 0;
		}
		output << 0;
	}
	output << tm.Ms();
	return output;
}
