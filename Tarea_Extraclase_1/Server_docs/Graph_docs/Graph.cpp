//
// Created by jose on 29/2/20.
//

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "./LinkedList.cpp"

using namespace std;

class Graph{

    public:

    VertexLinkedList VertexList;
    EdgeLinkedList EdgeList;

    /*Carga el grafo, la primera linea tiene todos los vertices separados por guiones, las demas lineas tienen dos vertices
     enlazados por un arista, de peso indicado, separado por guiones*/

    void chargeGraph(){

        ifstream archive;
        string text;

        archive.open("/home/jose/QtProjects/Tarea_Extraclase_1/Server_docs/Graph_docs/Graph", ios::in);   //Abrir el archivo en modo lectura

        if(archive.fail()){     //Si ocurre un error
            perror("Error: ");
            cout << "No se pudo abrir el archivo" << endl;
        }else{

            //========== Primera Linea: obtengo los vertices del grafo ===================

            getline(archive,text);         // copia texto de la linea en variable texto
            cout << text << endl;

            //Ocupo agregar todos los vertices indicados en la primera linea, separados por guiones

            int pos = 0;

            while(pos != -1) {      // Da -1 cuando no puede encontrar el delimitador

                pos = text.find("-");
                string Vertex = text.substr(0, pos);   // Obtengo el nombre del vertice

                cout << "Vertice: " << Vertex << endl;
                VertexList.Add(Vertex);     // Añade el vertice a la lista de vertices

                text = text.substr(pos + 1, text.length());     // Corto el string que tengo
                cout << "Lo que sobra del string: " << text << endl;
            }

            //========== Demás Lineas: obtengo los vertices a unir con una arista con peso  ===================

            while(!archive.eof()){      // Mientras no sea end of file

                string start,end;       // Nombres de los vertices
                int weight;     // Peso del arista

                getline(archive, text);         //Leo linea entera
                int pos = text.find("-");

                if(pos == -1){      // No encuentra delimitador
                    break;
                }

                start = text.substr(0, pos);       //Corto el string desde 0 hasta pos
                cout << "start es: " << start << endl;
                text = text.substr(pos + 1, text.length());     // Reasigno text con lo que queda del texto

                pos = text.find("-");

                end = text.substr(0, pos);
                cout << "end es: " << end << endl;
                text = text.substr(pos + 1, text.length());     // Reasigno text con lo que queda del texto

                pos = text.find("-");

                weight = stoi(text.substr(0, pos));     // Convierto el string a integer
                cout << "weight es: " << weight << endl;
                text = text.substr(pos + 1, text.length());     // Reasigno text con lo que queda del texto

                linkVertex(start, end, weight);

            }


        }

        archive.close();        // Cerrar el archivo

    }

    //Funcion que une dos vertices
    void linkVertex(string start, string end, int _weight){

        //Busco el valor start y lo asigno a un puntero startptr
        VertexNode* startptr = VertexList.findVertexByValue(start);
        VertexNode startNode = *startptr;

        //Busco el valor end y lo asigno a un puntero endptr
        VertexNode* endptr = VertexList.findVertexByValue(end);
        VertexNode endNode = *endptr;

        // Coloco el aritsta en EdgeLinkedList
        EdgeList.Add(startptr, endptr, _weight);

    }

};
