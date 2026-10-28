#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

struct scr_dim{
	int init_sw = 250;
	int init_sh = 150;
	int sw = 0;
	int sh = 0;
};

struct ui_layout{
	Rectangle windowbox_bnds = {0, 0, 0, 0};
};

void update(scr_dim& sd, ui_layout& ui);
void render(scr_dim& sd, ui_layout& ui);

int main(){
	scr_dim sd;
	ui_layout ui;
	
	InitWindow(sd.init_sw, sd.init_sh, "Popup!");
	GuiLoadStyle("style_genesis.rgs");
	SetTargetFPS(144);

	while(!WindowShouldClose()){
		update(sd, ui);
		BeginDrawing();
			ClearBackground(WHITE);
			render(sd, ui);
		EndDrawing();
	}
}

void update(scr_dim& sd, ui_layout& ui){
	sd.sw = GetScreenWidth();
	sd.sh = GetScreenHeight();
	ui.windowbox_bnds = {0, 0, (float)sd.sw, (float)sd.sh};
}

void render(scr_dim& sd, ui_layout& ui){
	GuiWindowBox(ui.windowbox_bnds, "Popup");
}
