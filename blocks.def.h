//Modify this file to change what commands output to your statusbar, and recompile using the make command.
#define ECHO(text) "echo \"" text "\"" 
#define EVAL(cmd) "$(" cmd ")"

#define BG(col) "^b" col "^"
#define FG(col) "^c" col "^"

#define SP(str) " " str " "

#define RED "#f7768e"
#define DARK_RED "#de6a7f"
#define GREEN "#9ece6a"
#define DARK_GREEN "#8eb95f"
#define YELLOW "#e0af68"
#define DARK_YELLOW "#c99d5d"
#define BLUE "#7aa2f7"
#define PURPLE "#bb9af7"
#define BLACK "#1a1b26"

#define ICON_WIDGET(icon_cmd, icon_col, text_cmd, text_col) ECHO(BG(icon_col) SP(EVAL(icon_cmd)) BG(text_col) SP(EVAL(text_cmd)))
#define BG_WIDGET(cmd, color) ECHO(BG(color) SP(EVAL(cmd)))
#define WIDGET(cmd) ECHO(SP(EVAL(cmd)))

#define BATTERY_ICON "~/.local/bin/statusbar/battery-icon.sh"
#define BATTERY_PERCENTAGE "~/.local/bin/statusbar/battery-percentage.sh"
#define AUDIO_MUTED "~/.local/bin/statusbar/audio-muted.sh"
#define AUDIO_VOLUME "~/.local/bin/statusbar/audio-volume.sh"
#define KEYBOARD_LAYOUT "cat ~/.cache/status/layout.txt"
#define DATE "date '+%b %d'"
#define TIME "date '+%H:%M'"

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	//{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
  {"", WIDGET("~/.local/bin/statusbar/network-status.sh"), 1,     0},
  {FG(BLACK), BG_WIDGET(KEYBOARD_LAYOUT, BLUE),           60,    11},
  {FG(BLACK), ICON_WIDGET(AUDIO_MUTED, DARK_YELLOW, AUDIO_VOLUME, YELLOW),   60,    10},
  {FG(BLACK), ICON_WIDGET(BATTERY_ICON, DARK_GREEN, BATTERY_PERCENTAGE, GREEN), 1,     0},
	{FG(BLACK), ICON_WIDGET(DATE, DARK_RED, TIME, RED),					       5,		  0},
  {"", "echo ''", 0, 0},
};
//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "^d^ ";
static unsigned int delimLen = 5;
