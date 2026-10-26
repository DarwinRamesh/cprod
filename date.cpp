#include <iostream>
#include <cstdint>
#include <ctime>
#include <string>

std::string get_time(){
	std::time_t cur_time;
	std::time(&cur_time);
	std::string time_string = std::ctime(&cur_time);
	if(time_string[time_string.length() - 1] == '\n'){
		time_string[time_string.length() - 1] = ';';
	}
	return time_string;
}
