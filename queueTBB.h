#ifndef QUEUETBB_H
#define QUEUETBB_H
#include <iostream>
#include <queue>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <tbb/tick_count.h>
#include <tbb/spin_mutex.h>
#include <tbb/tbb_thread.h>


using namespace std;
using namespace tbb;

template <class T>
class queueTBB
{
	public:
        ///\brief Constructor de la clase. Recibira por parametro el tamano maximo de la cola.
		queueTBB();
		bool push(T d); ///Insertara un nuevo elemento en la cola, caso el tamano de esta sea menor al tamano predefinido.
		T pop();
		int getMax(); ///Retorna el tamano maximo de la cola.
		void setMax(int M); ///Modificar el tamano maximo de la cola, recibe un entero.
		void print(); ///Funcion que imprimira la cola en pantalla.
	private:
		queue <T> cola; ///Cola STL
		spin_mutex mQuitar; /// Mutex para bloquear, caso no se pueda eliminar.
		spin_mutex mInsertar; /// Mutex para bloquear, caso no se pueda insertar.
		int MAX;		/// Tamano maximo de la cola.
		bool actInsert;		/// Booleano para controlar el push.
		bool actQuitar;		/// Booleano para controlar el pop.
};

#include "queueTBB.cpp"
#endif
