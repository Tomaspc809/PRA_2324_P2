#include <iostream>
#include <vector>

template <typename T> int BusquedaBinaria(T x, std::vector<T>& v, int ini, int fin){
	if (ini > fin){
		std::cout<<"No se encuentra en el array\n";

		return -1;
	}
	int medio = (ini + fin) / 2;

	if (v[medio] == x){
		return medio;
	}
	if (v[medio] > x){
		return BusquedaBinaria(x, v, ini, medio - 1);
	}

	return BusquedaBinaria(x, v, medio + 1, fin);
}

template <typename T> int BusquedaBinariaINV(T x, std::vector<T>& v, int ini, int fin){
	if (ini > fin){
		std::cout<<"No se encuentra en el array\n";

		return -1;
	}
	int medio = (ini + fin) / 2;

	if (v[medio] == x){
		return medio;
	}
	if (v[medio] < x){
		return BusquedaBinariaINV(x, v, ini, medio - 1);
	}

	return BusquedaBinariaINV(x, v, medio + 1, fin);
}

template <typename T> int Particion(std::vector<T>& v, int ini, int fin){
	T x = v[fin];
	T aux;
	int i = ini;

	for (int j = ini; j < fin; j++){
		if (v[j] <= x){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;

			i++;
		}
	}
	aux = v[i];
	v[i] = v[fin];
	v[fin] = aux;
	
	return i;
}

template <typename T> void QuickSort(std::vector<T>& v, int ini, int fin){
	if (ini < fin){
		int pivote = Particion(v, ini, fin);
		QuickSort(v, ini, pivote - 1);
		QuickSort(v, pivote + 1, fin);
	}
}
