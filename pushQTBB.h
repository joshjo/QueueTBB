#ifndef PUSHQTBB_H
#define PUSHQTBB_H
#include "queueTBB.h"

template <class T>
class pushQTBB{
	public:
		pushQTBB(queueTBB <T> * n, T _d){
			q = n;
			d = _d;
		}
		void operator()(){
			q->push(d);
		}
	private:
		queueTBB <T> * q;
		T d;
};

#endif
