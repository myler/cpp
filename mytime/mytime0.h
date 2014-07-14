#ifndef MYTIME0_H_
#define MYTIME0_H_

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
    void reset(int h = 0, int m = 0);
    Time sum(const Time &t) const;
    void show() const;
};

#endif
