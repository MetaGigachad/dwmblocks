//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	//{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
  {"", "~/.local/bin/statusbar/network-status.sh", 1,     0},
  {"", "cat ~/.cache/status/layout.txt",           60,    11},
  {"", "~/.local/bin/statusbar/audio-status.sh",   60,    10},
  {"", "~/.local/bin/statusbar/battery-status.sh", 1,     0},
	{"", "date '+%b %d (%a) %H:%M'",					       5,		  0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
