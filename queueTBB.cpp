#include "queueTBB.h"

template <class T>
queueTBB<T>::queueTBB(){
	MAX = 7;
	actInsert = false;
	actQuitar = false;
}

template <class T>
bool queueTBB<T>::push(T d){
	if (cola.size() > MAX) {
		actInsert = false;
		cout << "No puedo insertar esperando 1 ... \n";
		actQuitar = true;
		if (!actInsert) {
			spin_mutex::scoped_lock lock(mInsertar);
			lock.acquire(mInsertar);
		}
		return false;
	}
	else{
		cout << "insertando: " << d << endl;
		cola.push(d);
		if (!actQuitar){
			actQuitar = true;
			spin_mutex::scoped_lock unlock(mQuitar);
		}
		return true;
	}
}

template <class T>
T queueTBB<T>::pop(){
	if (cola.size() <= 0){
		actQuitar = false;
		actInsert = true;
		cout << "No puedo quitar esperando ...\n";
		if (!actQuitar) mQuitar.lock();
		return -1;
	}
	else{
		if (!actQuitar){
			actQuitar = true;
			mQuitar.unlock();
		}
		T d = cola.front();
		cout << "quitando: " << d << endl;
		cola.pop();
		if (!actInsert){
			cout << "desbloqueando insertar: " << endl;
			actInsert = true;
			mInsertar.unlock();
		}
		return d;
	}
}

template <class T>
int queueTBB<T>::getMax(){
	return MAX;
}

template <class T>
void queueTBB<T>::setMax(int M){
	MAX = M;
}

template <class T>
void queueTBB<T>::print(){
	queue <T> tmp = cola;
	while (!tmp.empty()){
		cout << tmp.front() << " ";
		tmp.pop();
	}
	cout << endl;
}
