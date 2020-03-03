#include "mainwindow.h"

#include <QApplication>
#include "./Server_docs/Graph_docs/Graph.cpp"

int main(int argc, char *argv[])
{

    /*
    Parte del proyeco en clion, donde pruebo el grafo
    */

    Graph g1;

    g1.chargeGraph();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
