#pragma once
#include <raylib.h>

struct scr_dim{
	int init_sw = 1080;
	int init_sh = 270;
	int sw = 0;
	int sh = 0;
};

struct ui_layout{
	Rectangle txtinput_bnds = {0, 0, 0, 0};
	Rectangle listview_bnds = {0, 0, 0, 0};
	Rectangle button_bnds = {0, 0, 0 ,0};
	int stack_index = 0;
};

struct prog_state{
	int txtinput_state = -1;
	char txtinput_buffer [255] = {0};
	int scroll_index = 0;
	int active = 0;
	int focused = 0;
	struct str_list_t* cur_list = nullptr;
};
