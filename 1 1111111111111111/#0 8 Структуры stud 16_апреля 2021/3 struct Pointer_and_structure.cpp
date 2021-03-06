// Пример 3.Указатели в структуре. Указатель на структуру.
// Динамические структуры и массивы структур.
/*
   Перед использованием переменной st в программе её 
   поля-указатели необходимо проинициализировать.
   Для доступа к содержимому  памяти, адрес которой находится
   в поле x переменной st, используется операция разыменования (*).
*/
#include <iostream>
using namespace std;
struct Rab {						// тип Rab
   int* px;
   int y;
};
int main() {
	// Указатели в структуре.
	Rab st;
	int z;		st.px = &z;
	*st.px = 5;
	int u = *st.px;					 // символ * относится к полю px
	st.y = 77;
	cout << *st.px << ' ' << st.y << ' ' << u << ' ' << z << endl;		// 5 77 5 5
	z = 6;
	cout << *st.px << ' ' << st.y << ' ' << u << ' ' << z << endl;		// 6 77 5 6
	//----------------------------------------------------------------------------------------------
	st.px = new int(4);			// st.px = адрес динамической переменной
	cout << *st.px << ' ' << u << ' ' << z << endl;				// 4 5 6
	delete st.px;
	//----------------------------------------------------------------------------------------------
	const int k = 4;
	st.px = new int[k];			// st.px = адрес динамического массива
	for (int i = 0; i < k; i++)
		st.px[i] = i + 1;
	for (int i = 0; i < k; i++)
		cout << st.px[i] << ' ' << endl;				// 1 2 3 4
	cout << endl;
		cout << st.px << ' ' << *st.px << endl;		// 014E4A90 (адрес) 1
	delete [] st.px;
	// Указатель на структуру
	// Использование операции  стрелка (->) для доступа к полям структуры
	Rab* ptr = &st;
	ptr->y = 777;
	ptr->px = &z;
	*ptr->px = 555;				// символ * относ. к полю x
	cout << ptr->y << ' ' << *ptr->px << ' ' << z << endl;		// 777 5555 555
	// Использование разыменование указателя операции точки (.)
	// для доступа к полям структуры
	(*ptr).y = 888;			// символ * относится к указателю uk
	(*ptr).px = &z;
	*((*ptr).px) = 666;
	cout << (*ptr).y << ' ' << *(*ptr).px << ' ' << z << endl;		// 888 666 666 
}
