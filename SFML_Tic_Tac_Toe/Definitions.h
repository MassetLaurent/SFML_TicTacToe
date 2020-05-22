#ifndef DEF_DEFINITIONS
#define DEF_DEFINITIONS


//Screen size
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1136


//Splash state
#define SPLASH_SCREEN_DURATION .5f
#define SPLASH_STATE_BACKGROUND_FILEPATH "Resources/images/Splash Background.png"


//main menu
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/images/Main Menu Background.png"
#define MAIN_MENU_TITLE_FILEPATH "Resources/images/Game Title.png"
#define PLAY_BUTTON_FILEPATH "Resources/images/Play Button.png"
#define PLAY_BUTTON_OUTER_FILEPATH "Resources/images/Play Button Outer.png"


//Play State
#define PLAY_BACKGROUND_FILEPATH "Resources/images/Main Menu Background.png"
#define PAUSE_BUTTON_FILEPATH "Resources/images/Pause Button.png"

#define X_PIECE_FILEPATH "Resources/images/X.png"
#define O_PIECE_FILEPATH "Resources/images/O.png"

#define X_WIN_FILEPATH "Resources/images/X Win.png"
#define O_WIN_FILEPATH "Resources/images/O Win.png"

#define GRID_SPRITE_FILEPATH "Resources/images/Grid.png"

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define IA_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSE 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_IA_PLAYING 93
#define STATE_DRAW 92


//Pause State
#define PAUSE_BACKGROUND_FILEPATH "Resources/images/Pause Background.png"
#define RESUME_BUTTON_FILEPATH "Resources/images/Resume Button.png"
#define HOME_BUTTON_FILEPATH "Resources/images/Home Button.png"


//Game Over State
#define RETRY_BUTTON_FILEPATH "Resources/images/Retry Button.png"
#define TIME_BEFORE_SHOW_GAME_OVER 3

#endif // !DEF_DEFINITIONS
