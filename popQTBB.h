#ifndef POPQTBB_H
#define POPQTBB_H
#include "queueTBB.h"

template <class T>
class popQTBB{
	public:
		popQTBB(queueTBB <T> * n){
			q = n;
		}
		void operator()(){
			q->pop();
		}
	private:
		queueTBB <T> * q;
};

#endif
