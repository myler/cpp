#ifndef TV_H
#define TV_H

class Tv
{
private:
	int state;
	int volume;
	int max_channel;
	int channel;
	int mode;
	int input;
public:
	friend class Remote;
	enum {Off, On};
	enum {min_val, max_val = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};

	Tv(int s = Off, int mc = 125) : state(s), volume(5),
		max_channel(mc), channel(2), mode(Cable), input(TV) {}

	void on_off() {state = (state == On) ? Off : On;}
	bool is_on() const {return state == On;}
	bool vol_up();
	bool vol_down();
	void chan_up();
	void chan_down();
	void set_mode() {mode = (mode == Antenna) ? Cable : Antenna;}
	void set_input() {input = (input == TV) ? DVD : TV;}
	void settings() const;
};

class Remote
{
private:
	int mode;
public:
	Remote(int m = Tv::TV) : mode(m) {}
	bool vol_up(Tv &t) {return t.vol_up();}
	bool vol_down(Tv &t) {return t.vol_down();}
	void on_off(Tv &t) {t.on_off();}
	void chan_up(Tv &t) {t.chan_up();}
	void chan_down(Tv &t) {t.chan_down();}
	void set_chan(Tv &t, int c) {t.channel = c;}
	void set_mode(Tv &t) {t.set_mode();}
	void set_input(Tv &t) {t.set_input();}
};

#endif // TV_H
