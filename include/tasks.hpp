#pragma once
#include "global.hpp"
#include <string>
#include <vector>

struct tasks{
	std::string task_list;
	std::string delim = ";";
	int count = 0;
};

void add_task(prog_state& ps, tasks& tk);
void del_task(prog_state& ps, tasks& tk, int traverse);
void get_list(tasks& tk);
void write_list(tasks& tk);
