#include <string>
#include <time.h>
#include <iostream>
#include <sstream>

class Time {

public:
	Time()
	{
		_hours = 0;
		_min = 0;
		_sec = 0;
		_msec = 0;
	}
	Time(int const &hours, int const &min, int const &sec, int const &msec)
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
		Time result(_hours, _min, _sec, _msec);
		result.addSecs(ms);
		return result;
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

	
	int  msecsTo(const Time & t) const // возвращает кол-во мсек до события
	{
		Time ctm;
		ctm = ctm.currentTime();
		int ms = 0;
		ms += (t.H() - ctm.H())*3600000;
		ms += (t.M() - ctm.M()) * 60000;
		ms += (t.S() - ctm.S()) * 1000;
		ms += (t.Ms() - ctm.Ms());
		return ms;
	}
	int secsTo(const Time & t) const // возвращает кол-во сек до события 
	{
		Time ctm;
		ctm = ctm.currentTime();
		int s = 0;
		s += (t.H() - ctm.H()) * 3600;
		s += (t.M() - ctm.M()) * 60;
		s += (t.S() - ctm.S());
		return s;

	}
	bool setHMS(int h, int m, int s, int ms = 0) // установить новую дату
	{
		_hours = h;
		_min = m;
		_sec = s;
		_msec = ms;
	}
	std::string toString(const std::string & format) const // преобразует в строку, согласно заданному формату
	{
		std::stringstream  st;
		for (int i = 0; i < 4;++i)
		{
			switch(format[i])
			{
			case'h':
				st << _hours;
				break;
			case'm':
				st << _min;
				break;
			case's':
				st << _sec;
				break;
			case'u':
				st << _msec;
				break;
			}
			if(i!=3)
			{
				st << ":";
			}

		}
		//st << _hours << ":" << _min << ":" << _sec << ":" << _msec;
		return st.str();
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
		
		if(this->getMs()<t.getMs())
		{
			return true;
		}

		else
		{
			return false;
		}
		/*
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
		//*/

	}
	unsigned int getMs() const
	{
		unsigned int ms = 0;
		ms += _hours * 3600000;
		ms += _min * 60000;
		ms += _sec * 1000;
		ms += _msec;
		return ms;
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
		Time result;
		char buffer[9];
		char* format = "%H %M %S";
		time_t seconds = time(NULL);
		std::tm* timeinfo = localtime(&seconds);
		strftime(buffer, 9, format, timeinfo);
		std::string s = buffer;
		char  pos(0), pos1(0);
		pos = s.find_first_of("123456789", 0);
		pos1 = s.find_first_not_of("1234567890", pos);
		result._hours = atoi(s.substr(pos, pos1 - pos).c_str());


		pos = pos = s.find_first_of("123456789", pos1);
		pos1 = s.find_first_not_of("1234567890", pos);
		result._min= atoi(s.substr(pos, pos1 - pos).c_str());

		pos = pos = s.find_first_of("123456789", pos1);
		pos1 = s.find_first_not_of("1234567890", pos);
		result._sec = atoi(s.substr(pos, pos1 - pos).c_str());

		return result;

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

	void addSec(const int &sec)
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
			_sec += sec;
		}
	}
	void addMsec(const int &msec)
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
