// STL
#include <bits/stdc++.h>

using namespace std;

void print(multiset<int> S){
	for(int i : S){
		cout << i << ' ';
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Last in first out (LIFO)
	stack<int> pila;

	pila.push(3);
	pila.push(2);
	pila.push(1);

	// cout << pila.top() << '\n';
	pila.pop();
	// cout << pila.top() << '\n';
	pila.pop();
	// pila.size();

	// First in First out (FIFO)
	queue<int> cola;

	cola.push(3);
	cola.push(2);
	cola.push(1);

	// cout << cola.front() << '\n';
	// cola.pop();
	// cout << cola.front() << '\n';

	queue<string> QS;

	QS.push("Eric");
	QS.push("Ernesto");

	// while(!QS.empty()){ // QS.empty() == false
	// 	cout << QS.front() << '\n';
	// 	QS.pop();
	// }

	// Doble queue (doble cola)
	deque<int> DQ;

	DQ.push_back(1);
	DQ.push_back(2);
	DQ.push_front(3);
	DQ.push_back(4);
	DQ.push_front(5);

	// cout << DQ.front() << '\n';
	// cout << DQ.back() << '\n';
	// DQ.pop_front();
	// cout << DQ.back() << '\n';
	// cout << DQ.front() << '\n';

	// Cola con prioridad (Montículo -> Heap)
	priority_queue<int> CP;

	CP.push(10);
	CP.push(1);
	CP.push(20);

	// cout << CP.top() << '\n';
	// CP.pop();
	// CP.pop();
	// cout << CP.top() << '\n'; // 1

	// sacar el menor
	priority_queue<int, vector<int>, greater<int>> CP_less; 

	CP_less.push(10);
	CP_less.push(1);
	CP_less.push(20);

	// cout << CP_less.top() << '\n';
	// CP_less.pop();
	// CP_less.pop();
	// cout << CP_less.top() << '\n'; // 20

	/////////////////

	// conjuntos
	set<char> C;

	C.insert('c');
	C.insert('c');
	C.insert('z');
	C.insert('z');
	C.insert('a');

	// cout << C.size() << '\n';

	// C.erase('z');

	// cout << C.size() << '\n';

	C.begin(); C.end();
	// [1,3) [inclusivo, exclusivo)

	// if(C.find('a') != C.end()){
	// 	cout << "a está en el conjunto\n";
	// }

	// if(C.find('z') != C.end()){
	// 	cout << "z está en el conjunto\n";
	// }
	// else{
	// 	cout << "z no está en el conjunto\n";
	// }

	// cout << C.count('a') << '\n'; // 1
	// cout << C.count('z') << '\n'; // 0
	// cout << C.count('c') << '\n'; // 1

	C.insert('k');
	C.insert('b');

	set<char>::iterator a = C.begin(); 
	// for(; a != C.end();a ++){
	// 	cout << (*a) << '\n';
	// }

	// for(auto a = C.begin();a != C.end();a++){
	// 	cout << (*a) << '\n';
	// }

	// for(auto a : C){
	// 	cout << a << '\n';
	// }

	//////
	multiset<int> MC;

	MC.insert(3);
	MC.insert(3);
	MC.insert(1);
	MC.insert(2);
	MC.insert(2);

	cout << MC.size() << '\n';

	MC.erase(3); // elimina todos los elementos 3
	cout << MC.size() << '\n';

	MC.insert(5);
	MC.insert(5);

	MC.erase(MC.find(5));

	cout << MC.size() << '\n';

	print(MC);
	cout << MC.count(2) << '\n'; // costo es la cantidad de elementos iguales a 2

	//////////
	map<string,int> mapa;

	mapa["Jose"] = 10;
	mapa["Roger"] = 11;
	mapa["Guillermo"] = 12;

	cout << mapa["Guillermo"] << '\n';

	if(mapa.find("roger") != mapa.end())
		cout << mapa["Roger"] << '\n';

	mapa["roger"];

	mapa.count("a");
	mapa.erase("b");

	cout << mapa["roger"] << '\n';

	string aa = "Roger";
	int b = 10;

	mapa[aa] = b;

	for(auto i : mapa){
		cout << i.first << ' ' << i.second << '\n';
	}

	map<int,int> M2;
	map<int,vector<int>> M3;

	multimap<string,int> Mmapa;

	map<int,map<int,int>> MM;

	MM[1][2] = 3;

	tuple<int,int,int> T; // pending tarea
	pair<pair<int,int>,int> trio;

	return 0;
}