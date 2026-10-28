#include "raylib.h"
#include <bits/stdc++.h>
#include <string.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>
#include "include/tasks.hpp"
#include "include/global.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void update(scr_dim& sd, ui_layout& ui, prog_state& ps, tasks& tk);
void render(scr_dim sd, ui_layout& ui, prog_state& ps, tasks& tk);

int main(){
	scr_dim sd;
	ui_layout ui;
	prog_state ps;
	tasks tk;

	SetTraceLogLevel(1);
	SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_MSAA_4X_HINT);
	InitWindow(sd.init_sw, sd.init_sh, "Prod");
	SetTargetFPS(144);

	ui.button_bnds = {(float)(sd.sw / 3.0f), 0, (float)(sd.sw) - ui.txtinput_bnds.width, 35};
	
	GuiLoadStyle("style_genesis.rgs");
	get_list(tk);
	while(!WindowShouldClose()){
		update(sd, ui, ps, tk);
		BeginDrawing();
			ClearBackground(GRAY);
			render(sd, ui, ps, tk);
		EndDrawing();
	}
	return 0;
}

void update(scr_dim& sd, ui_layout& ui, prog_state& ps, tasks& tk){
	sd.sw = GetScreenWidth();
	sd.sh = GetScreenHeight();
	if(ps.txtinput_state == 0){
		write_list(tk);
		CloseWindow();
	}
	if(ps.txtinput_state == 1){
		add_task(ps, tk);
		TraceLog(1, TextFormat("Updated : %d", ps.txtinput_state));
		memset(ps.txtinput_buffer, 0, sizeof(ps.txtinput_buffer));
		return;
	}
	if(ps.txtinput_state == 2){
		del_task(ps, tk, ps.active);
		memset(ps.txtinput_buffer, 0, sizeof(ps.txtinput_buffer));
		return;
	}
	if(ps.txtinput_state == 3){
		std::system("./popup &"); 
		ps.txtinput_state = -1;
	}
}

void render(scr_dim sd, ui_layout& ui, prog_state& ps, tasks& tk){
	ui.txtinput_bnds = {0, 0, (float)(sd.sw / 3.0f), (float)(sd.sh)};
	ui.listview_bnds = {(float)(ui.txtinput_bnds.width), 0, (float)(sd.sw) - (ui.txtinput_bnds.width), (float)(sd.sh)};
	GuiTextInputBox(ui.txtinput_bnds, "CProd - A task management program", "Please enter or delete a task", ps.txtinput_buffer, 255, "Ok;Delete Selected Entry;Edit", &ps.txtinput_state , 0);
	GuiListView(ui.listview_bnds, tk.task_list.c_str(), &ps.scroll_index, &ps.active);
}
