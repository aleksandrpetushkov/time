#include <string>
#include <time.h>

class Time {

public:
	Time();
	Time(int hours, int min, int sec, int msec);
	Time addMSecs(int ms) const // ��������� ����� ������ �� ������� � �������������
	{
		
	}
	Time addSecs(int s) const; // ��������� ����� ������ �� ������� � ��������
	int hour() const; // ���������� ���-�� �����
	int minute() const; // ���������� ���-�� �����
	int second() const; // ���������� ���-�� ������
	int msec() const; // ���������� ���-�� �����������
	bool isValid() const; // ������� �� ����
	int msecsTo(const Time & t) const // ���������� ���-�� ���� �� �������
	{
		
	}
	int secsTo(const Time & t) const // ���������� ���-�� ��� �� ������� 
	{
		
	}
	bool setHMS(int h, int m, int s, int ms = 0) // ���������� ����� ����
	{
		
	}
	std::string toString(const std::string & format) const // ����������� � ������, �������� ��������� �������
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
	static currentTime(); // ���������� ������� �����
	Time fromString(const std::string& str, const std::string & format)
	{
		
	}
protected:

}