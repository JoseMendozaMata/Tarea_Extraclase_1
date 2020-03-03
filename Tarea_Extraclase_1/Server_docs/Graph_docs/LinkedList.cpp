//
// Created by jose on 29/2/20.
//

//
// Created by jose on 28/2/20.}
//Clases en C++
//

#include <stdio.h>;
#include <iostream>

using namespace std;

//============================= Clases de los vertices ==================================================

//Clase que sera el nodo componente de la clase vertexList
class VertexNode {

private:
    string value;
    VertexNode *next;

public:

    VertexNode(string _value){
        value = _value;
        next = NULL;
    };

    string getValue(){     // Devuelvo el valor del nodo
        return value;
    }

    VertexNode* getNext(){        //Devuelvo la direccion de memoria del nodo siguiente
        return next;
    }

    void setNext(VertexNode* _next){      // Le paso la direccion de memoria del nodo siguiente
        next = _next;
    }

};  // Ojo el punto y coma al final de la llave


//Clase que será la lista enlazada que representa los vectores
class VertexLinkedList {

private:
    VertexNode *first;
    VertexNode *last;

public:
    VertexLinkedList(){
        first = NULL;
        last = NULL;
    }
    void Add(string valor){

        VertexNode *newNode = new VertexNode(valor);   // Asigno un puntero que me lleve al nuevo nodo

        cout << "creo nodo nuevo de valor: " << newNode->getValue() << endl;

        if(first == nullptr){      // Si la cabeza es nula, asigno el nuevo nodo como cabeza
            cout << "guardo como cabeza a: " << newNode->getValue() << endl;
            first = newNode;
            last = newNode;

        } else {        // Sino, recoro los nodos hasta encontrar uno que sea nulo
            VertexNode *temp = first;

            while(temp->getNext()){     // OJO: El next no puede ser nulo
                cout <<"Temp es: " << temp->getValue() << " y su next es: "<< temp->getNext()->getValue() << endl;
                temp = temp->getNext();     // Obtengo la dir de mem del siguiente nodo
            }

            cout << temp->getValue() << " tiene como next nulo, lo junto con: " << newNode->getValue() << endl;

            temp->setNext(newNode);

            last = newNode;

        }
    }

    //Me encuentra la direccion de memoria de un vertice por su contenido

    VertexNode* findVertexByValue(string _value){

        VertexNode *temp = first;

        while(temp->getValue() != _value){
            temp = temp->getNext();
        }

        return temp;
    }

    string getFirst(){

        return first->getValue();

    }

    string getLast(){
        return last->getValue();
    }

};

//============================= Clases de las aristas ==================================================

//Clase que sera el nodo componente de la clase edgeList
class EdgeNode {

private:
    VertexNode *startVertex;
    VertexNode *endVertex;
    EdgeNode *nextEdgeNode;
    int weight;

public:

    EdgeNode(VertexNode*  _start, VertexNode* _end, int _weight){
        startVertex = _start;
        endVertex = _end;
        weight = _weight;
        nextEdgeNode = NULL;
    };

    EdgeNode* getNextEdgeNode(){
        return nextEdgeNode;
    }

    void setNextEdgeNode(EdgeNode* next){
        nextEdgeNode = next;
    }

    //Retorna el peso de la arista
    int getWeight(){     // Devuelvo el valor del nodo
        return weight;
    }

    VertexNode* getStartVertex(){        //Devuelvo la direccion de memoria del vertice inicial
        return startVertex;
    }

    VertexNode* getEndVertex(){        //Devuelvo la direccion de memoria del vertice final
        return endVertex;
    }

};  // Ojo el punto y coma al final de la llave


//Clase que será la lista enlazada que representa los vectores

class EdgeLinkedList {

private:
    EdgeNode *first;
    EdgeNode *last;

public:
    EdgeLinkedList(){
        first = NULL;
        last = NULL;
    }

    //Funcion que se encarga de unir dos vertices por medio de una arista
    void Add(VertexNode* startptr, VertexNode* endptr, int _weight){

        EdgeNode *newNode = new EdgeNode(startptr, endptr, _weight);   // Asigno un puntero que me lleve al nuevo nodo

        cout << "creo nodo nuevo de valor: " << newNode->getStartVertex()->getValue() << "->" << newNode->getEndVertex()->getValue() << endl;

        if(first == nullptr){      // Si la cabeza es nula, asigno el nuevo nodo como cabeza
            cout << "guardo como cabeza a: " << newNode->getStartVertex()->getValue() << "->" << newNode->getEndVertex()->getValue()
            << " de peso " << newNode->getWeight() << endl;
            first = newNode;
            last = newNode;

        } else {        // Sino, recoro los nodos hasta encontrar uno que sea nulo
            EdgeNode *temp = first;

            while(temp->getNextEdgeNode()){     // OJO: El next no puede ser nulo
                cout <<"Temp es: " << temp->getStartVertex()->getValue() << "->" << temp->getEndVertex()->getValue() << endl;
                temp = temp->getNextEdgeNode();     // Obtengo la dir de mem del siguiente nodo
            }

            cout << temp->getStartVertex()->getValue() << "->" << temp->getEndVertex()->getValue() << " tiene como next nulo, lo junto con: "
            << newNode->getStartVertex()->getValue() << "->" << newNode->getEndVertex()->getValue() << endl;

            temp->setNextEdgeNode(newNode);

            last = newNode;

        }
    }

};
