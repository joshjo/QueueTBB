#include <iostream>
#include <stdlib.h>
#include "pushQTBB.h"
#include "popQTBB.h"

/**
 * \mainpage TBB Queue
 * \author Josue Ttito
 * \date September-2011
 */

using namespace std;

typedef int my_type;

int main(){
	tbb_thread ** ths = new tbb_thread * ();
	queueTBB <my_type> * q  = new queueTBB <my_type> ();
	int i = 0;
	bool b = 0;
	while (true){
		pushQTBB <my_type> pushQueue (q,rand()%1000);
		popQTBB <my_type> popQueue (q);
		sleep(1);
		ths[i] = new tbb_thread (pushQueue);
		(*ths[i]).join();
		i++;
		ths[i] = new tbb_thread (popQueue);
		(*ths[i]).join();
		i++;
		ths[i] = new tbb_thread (pushQueue);
		(*ths[i]).join();
		i++;
	}
	return 1;
}
