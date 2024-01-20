#define _GNU_SOURCE

enum KeyCodes {
    UP = KEY_UP, DOWN = KEY_DOWN, LEFT = KEY_LEFT, RIGHT = KEY_RIGHT, BACKSPACE = KEY_BACKSPACE, ENTER = '\n', EXIT = 'q'
};

typedef struct {
    const char *label;
    const char *hexString;
} Option;

void drawMenu(WINDOW *win, size_t numRows, Option *options, ssize_t cursorPosition) {
    werase(win);
    box(win, 0, 0);
    wmove(win, numRows / 2, (numRows - strlen(options[cursorPosition].label)) / 2);
    wprintw(win, "[%s]", options[cursorPosition].label);

    for (ssize_t i = 0; i < numRows; ++i) {
        size_t index = (cursorPosition + i + numRows) % numRows;
        if (index > numRows - 2) continue;

        bool highlighted = i == numRows / 2;
        wattron(win, COLOR_PAIR(highlighted ? 1 : 0));
        wmove(win, i+1, (numRows - strlen(options[index].label)) / 2);
        wprintw(win, "%s", options[index].label);
        wattroff(win, COLOR_PAIR(highlighted ? 1 : 0));
    }
    doupdate();
}

void printErrorMessageAndExit(char *message) {
    endwin();
    perror(message);
    exit(-1);
}

int main(void) {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    timeout(0);
    curs_set(FALSE);

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_WHITE);

    WINDOW *menuWin = newwin(LINES, COLS, (LINES - LINES / 2) / 2, (COLS - COLS / 2) / 2);
    if (!menuWin) printErrorMessageAndExit("Cannot initialize window.");

    Option mainMenu[] = {
        {"QCOM Diag Mode", "0x2876B41D"},
        {"Factory Mode (Xiaomi)", "0x28E9EDF2"},
        {"Factory Mode (OnePlus)", "0xB00BB511"},
        {"EDL Mode", "0xFFFFFFFF"}
    };

    enum MainMenuKeys {
        SELECT = ENTER, GO_BACK = BACKSPACE, EXIT = 'q'
    };

    ssize_t cursorPos = 0;
    drawMenu(menuWin, sizeof(mainMenu)/sizeof(*mainMenu), mainMenu, cursorPos);

    int ch = -1;
    while ((ch = wgetch(menuWin)) != EXIT) {
        switch (ch) {
            case UP:
            case DOWN:
                drawMenu(menuWin, sizeof(mainMenu)/sizeof(*mainMenu), mainMenu, (cursorPos += ch == UP ? -1 : 1) % (signed)(sizeof(mainMenu)/sizeof(*mainMenu)));
                break;
            case SELECT:
                clear();
                refresh();
                system(concat("fastboot oem ", mainMenu[cursorPos].hexString));
                drawMenu(menuWin, sizeof(mainMenu)/sizeof(*mainMenu), mainMenu, cursorPos);
                break;
            case GO_BACK:
                delwin(menuWin);
                endwin();
                return 0;
            default:
                break;
        }
    }

    delwin(menuWin);
    endwin();

    return 0;
}