#include "global.hpp"
#include "tasks.hpp"
#include "date.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void add_task(prog_state& ps, tasks& tk){
	std::string new_task = ps.txtinput_buffer;
	if(new_task == ""){
		return;
	}
	tk.task_list.append(new_task);
	tk.task_list.append("-");
	tk.task_list.append(get_time());
	//tk.task_list.append(tk.delim);
	write_list(tk);
	ps.txtinput_state = -1;
}

void del_task(prog_state& ps, tasks& tk, int index){
	std::string token;
	std::string task;
	std::vector<std::string> tokens;
	std::stringstream string_stream(tk.task_list);
	while(std::getline(string_stream, token, ';')){
		tokens.push_back(token);
	}
	for(int i = 0; i < tokens.size(); i++){
		if(i == index){
			continue;
		}
		task.append(tokens[i]);
		task.append(tk.delim);
		TraceLog(1, "Appened token to stream");
	}
	tk.task_list = task;
	write_list(tk);
	get_list(tk);
	ps.txtinput_state = -1;
}

void get_list(tasks& tk){
	std::ifstream cur_list("tasklist.txt");
	std::getline(cur_list, tk.task_list);
	cur_list.close();
}

void write_list(tasks& tk){
	std::ofstream cur_file("tasklist.txt");
	cur_file << tk.task_list;
	cur_file.close();
	return;
}
