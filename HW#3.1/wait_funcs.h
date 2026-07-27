#ifndef WAIT_FUNCS_H
#define WAIT_FUNCS_H

#include <thread> // for wait function
#include <chrono> // for wait function	

inline void waitS(int time) {
	std::this_thread::sleep_for(std::chrono::seconds(time));

}

#endif