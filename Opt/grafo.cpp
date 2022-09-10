 /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"
#include <stack>

void GRAFO::destroy()
{
	for (unsigned i=0; i< n; i++)
    {
		LS[i].clear();
		A[i].clear();
		if (dirigido == 1)
        {
            LP[i].clear();
        };
	}
	LS.clear();
	LP.clear();
	A.clear();

}

void GRAFO::build(char nombrefichero[85], int &errorapertura)
{
    ElementoLista dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if(textfile.is_open()) 
    {
		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.resize(n);
        A.resize(n);
        if(dirigido == 1)
            LP.resize(n); // Si tenemos n nodos, la primera dimensión de LS y LP debe tener n espacios
	        // leemos los m arcos
		for (k=0;k<m;k++)
        	{
			    textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
			    //damos los valores a dummy.j y dummy.c
			    //situamos en la posicion del nodo i a dummy mediante push_backM
			    //pendiente de hacer un segundo push_back si es no dirigido. O no.
			    //pendiente la construccion de LP, si es dirigido
			    //pendiente del valor a devolver en errorapertura
                dummy.j = j - 1; // resto a j una unidad, para tener el nodo 1, en la posición cero, el 2 en la 1, etc...
			    if(dirigido == 0) // Si es no dirigido, solo tenemos que trabajar con LS
                {
                    LS[i-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo al que apunta, y el coste del camino
                    dummy.j = i - 1; // Asignamos el valor del nodo predecesor
                    if((i-1) != (j-1)) {
                        LS[j-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo que le precede, y el coste del camino
                        // Como es un grafo no dirigido, se ponen todos los datos en LS pero reflejados con la diagonal principal
                    }
                }
                if(dirigido == 1) // No pongo un else, por si hay acaso, dirigido != 0 y dirigido !=1
                {
                    LS[i-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo al que apunta, y el coste del camino
                    dummy.j = i - 1; // Asignamos el valor del nodo predecesor
                    LP[j-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LP, el nodo que le precede, y el coste del camino
                    // Como es un grafo dirigido, usamos LP para colocar este dato
                    
                }
            }
    }
    textfile.close();
}

void GRAFO::ListaPredecesores()
{
    
}

GRAFO::~GRAFO()
{
	destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
	build (nombrefichero, errorapertura);
}

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura)
{
    //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
    destroy();
    //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
    build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido() { return dirigido; }

void GRAFO::Info_Grafo()
{
    cout << endl << "El Grafo cargado actualmente tiene las siguiente características:" << endl;
    cout << "Nº de Nodos: " << n << endl;
    cout << "Nº de Arcos: " << m << endl;
    cout << "¿Grafo Dirigido? " << (dirigido == 1 ? " Si" : " No");
    cout << endl << endl;
}

void Mostrar_Lista(const vector<LA_nodo>& L, unsigned& nodos)
{
    for(int i{0}; i < nodos; ++i)
    {
        cout << "[" << i + 1 << "]";
        if(L[i].size() == 0) 
            cout << " : NULL";
        for(int k{0}; k < L[i].size(); ++k)
        {
            cout << " :  " << L[i][k].j + 1 << "(" << L[i][k].c << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void GRAFO::Mostrar_Listas(int l)
{
    if(l == 1 || l == 0)
        Mostrar_Lista(LS, n); // Para Grafos Dirigidos y No Dirigidos   
    if(l == -1)
        Mostrar_Lista(LP, n); // Para Grafos Dirigidos
}

void GRAFO::Mostrar_Matriz() //Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes
{

}

void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
{
	visitado[i] = true;
    prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
    for (unsigned j=0;j<L[i].size();j++)
             if (!visitado[L[i][j].j])
                {
                dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
                };
    postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad()
{

}

void GRAFO::bfs_num(	unsigned i, //nodo desde el que realizamos el recorrido en amplitud
				vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
				vector<unsigned> &pred, //vector de predecesores en el recorrido
				vector<unsigned> &d) //vector de distancias a nodo i+1
//Recorrido en amplitud con la construccion de pred y d: usamos la cola
{
    vector<bool> visitado; //creamos e iniciamos el vector visitado
    visitado.resize(n, false);  
    visitado[i] = true;
 
    pred.resize(n, 0); //creamos e inicializamos pred y d
    d.resize(n, 0);
    pred[i] = i;
    d[i] = 0;

    queue<unsigned> cola; //creamos e inicializamos la cola
    cola.push(i);//iniciamos el recorrido desde el nodo i+1
 
    while (!cola.empty()) //al menos entra una vez al visitar el nodo i+1 y continua hasta que la cola se vacie
    { 
        unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        for (unsigned j{0}; j < L[k].size(); ++j)
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no esta visitado
            {
                if(visitado[L[k][j].j] == false) 
                {
                    visitado[L[k][j].j] = true;      //Lo visitamos
                    cola.push(visitado[L[k][j].j]);  //Lo metemos en la cola
                    pred[L[k][j].j] = k;             //le asignamos el predecesor
                    d[L[k][j].j] = d[k] + 1;         //le calculamos su etiqueta distancia
                }
            };
        //Hemos terminado pues la cola esta vacia
    };
}

void GRAFO::RecorridoAmplitud() //Construye un recorrido en amplitud desde un nodo inicial
{
    std::vector<unsigned> pred;     // Declaramos el vector de nodos predecesores, la posición es el vector actual, y el número que contiene es su predecesor
    std::vector<unsigned> d;        // Declaramos el vector de etiquetas distancia, la posición es el nodo, y el número que contenga, es la distancia del nodo elegido por el usuario
    int nodo_inicial{0};
    int d_maxima{0};                // Distancia máxima entre el nodo elegido y los nodos más alejados a él

    cout << "\nElige el nodo inicial en el rango [1 - " << n << "]: ";
    cin >> nodo_inicial;
    cout << "Nodo inicial elegido [" << nodo_inicial << "]" << endl << endl;
    nodo_inicial -= 1;
    bfs_num(nodo_inicial, LS, pred, d);
    cout << "Distancia entre el nodo inicial y el resto, " 
         << "expresado en el número de arcos" << endl << endl;

    for(int i{0}; i < d.size(); ++i) // Recorremos el vector d, para darle un valor a d_maxima
        if(d[i] > d_maxima)
            d_maxima = d[i];
    ++d_maxima; // le sumamos 1, porque siempre dará una menos

    for(int i{0}; i < d_maxima; ++i) // este for nos itera todas las distancias
    {
        cout << "Nodos a distancia " << i << " arcos";
        if(i == 0) 
        {
            cout << " : " << nodo_inicial + 1;
            nodo_inicial = 0;
        }
        else
        {
            for(int j{0}; j < n; ++j) // por cada distancia, recorremos todos los nodos
            {
                if(d[j] == i) {// si la posición d[j] en el vector de distancias == i, entoces se muestra
                    cout << " : " << nodo_inicial + 1;
                }
                ++nodo_inicial; // lo aumentamos para la siguiente iteración
            }
            nodo_inicial = 0; // reiniciamos el valor para la siguiente distancia
        }
        cout << endl;
    }
/*
    cout << endl << "Ramas de conexión en el recorrido" << endl << endl;
*/
}

void GRAFO::PredecesoresRecursivos(int s,int i,LA_nodo pred)
{
  if(i != s) // nodo inicial != nodo predecesor?
  { 
    PredecesoresRecursivos(s, pred[i].j, pred);
    std::cout << " => " <<  i + 1;
  }
  else {std::cout << s + 1;}
}

void GRAFO::FloydWarshall() //Algoritmo de FW para caminos mínimos entre cualquier par de nodos;
{
    std::vector<LA_nodo> P; //Usaremos la misma estructura de datos de LS para guardar P y D

    //Inicializamos P y D en P
    //Creamos P
    P.resize(n); //Ya tenemos las posiciones P[0] a P[n-1]
    for (unsigned i{0}; i < n; ++i) P[i].resize(n); //Ya tenemos la matriz cuadrada
    for (unsigned i{0}; i < n; ++i)
    {
        for (unsigned j{0}; j < n; ++j)
        {
            if (i != j) // Inicialización base
            {
                P[i][j].j = -1; //en el campo .j ponemos el predecesor
                P[i][j].c = maxint; //en el campo .c ponemos el coste
            }
            else // Inicializamos los bucles
            {
                P[i][j].c = 0; //El coste en el caso de un bucle
                P[i][j].j = i; //El predecesor en el caso de un bucle
            }
        }
    }
        //Recorremos LS para inicializar P, su predecesor en .j y su distancia en .c
        for (unsigned i{0}; i < n; ++i)
            for (unsigned j{0}; j < LS[i].size(); ++j)
            {
                P[i][LS[i][j].j].j = i;
                P[i][LS[i][j].j].c = LS[i][j].c;
            }
        //Con las matrices ya inicializadas, vamos ahora a realizar las k comparativas...
        //Bien, ya tenemos D y P, mostremos las matrices y los caminos mínimos...

       for (int i{0}; i < n; ++i) {
            std::cout << "(";
            for (int j{0}; j < n; ++j)
            {
                if(P[i][j].c == maxint)
                {
                    std::cout << "  inf";
                }
                else 
                    std::cout << "  " << P[i][j].c;
            }
            std::cout << "  )\n";
        }
        std::cout << "   Costes" << std::endl << std::endl;

        for (int i{0}; i < n; ++i) {
            std::cout << "(";
            for (int j{0}; j < n; ++j)
                std::cout << "  " << P[i][j].j + 1;
            std::cout << "  )\n";
        }
        std::cout << "   Predecesores" << std::endl;
        std::cout << " Matrices inicializadas\n\n\n";
        
        // Bucle de n fases
        for (unsigned k{0}; k < n; ++k)
        {
            for (unsigned i{0}; i < n; ++i)
            {
                if (i != k)
                {
                    for (unsigned j{0}; j < n; ++j)
                    {
                        if (j != k)
                        {
                            if ((P[i][k].c != maxint) && (P[k][j].c != maxint)) 
                            {
                                if (P[i][j].c > (P[i][k].c + P[k][j].c))
                                {
                                    P[i][j].c = P[i][k].c + P[k][j].c;
                                    P[i][j].j = P[k][j].j;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i{0}; i < n; ++i) {
            std::cout << "(";
            for (int j{0}; j < n; ++j)
            {
                if(P[i][j].c == maxint)
                {
                    std::cout << "  inf";
                }
                else 
                    std::cout << "  " << P[i][j].c;
            }
            std::cout << "  )\n";
        }
        std::cout << "   Costes" << std::endl << std::endl;

        for (int i{0}; i < n; ++i) {
            std::cout << "(";
            for (int j{0}; j < n; ++j)
                std::cout << "  " << P[i][j].j + 1;
            std::cout << "  )\n";
        }
        std::cout << "   Predecesores\n";
        std::cout << "Matrices tras usar el método FW\n\n";


        std::cout << "Ahora se mostrarán todos los caminos posibles para\n";
        std::cout << "cada par de nodos 'i' y 'j', así como su coste:\n\n";

        
        for (int i{0}; i < n; ++i) // i == filas
        {
            for (int j{0}; j < n; ++j) // j == columnas
            {
                if ((i == j) && (P[i][j].c != 0)) // si fila == columna y además el coste de la posición es != 0
                {
                    std::cout << "El nodo " << i + 1 << " está dentro de un ciclo de coste negativo | Coste Total: " << P[i][j].c << std::endl;
                    continue;
                }
                
                std::cout << "Camino mínimo del nodo " << i + 1 << " al " << j + 1 << ": ";
                if (P[i][j].c != maxint) // Si coste != infinito, es un camino válido
                {
                    PredecesoresRecursivos(i,j,P[i]); // llamamos a la función recursiva
                    std::cout << "  | Coste Total: " << P[i][j].c << std::endl;
                }
                else {std::cout << "NULL" << "\n";}
            }
            std::cout << "\n\n";
        }
        std::cout << "\n";
}