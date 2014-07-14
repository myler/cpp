#ifndef MYTIME2_H
#define MYTIME2_H

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	~Time();

	void add_min(int m);
	void add_hour(int h);
	void reset(int h =0, int m = 0);
	Time operator+(const Time &t) const;
	Time operator-(const Time &t) const;
	Time operator*(double n) const;
	void show() const;
};

#endif // MYTIME2_H