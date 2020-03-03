#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./Client_docs/Client.cpp"
#include "./Server_docs/Graph_docs/Graph.cpp"


#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    /*
    Graph graph;        // Creo el grafo a probar
    graph.chargeGraph();        // Cargo el grafo del txt
    */

    QString inicio = ui->lineEdit->text();  // Devuelve el texto dado por el usuario
    QString end = ui->lineEdit_2->text();  // Devuelve el texto dado por el usuario


    /*
    int result = testDijkstra(inicio.toStdString(), end.toStdString());     // Solicito al server que pruebe el algoritmo de Dijkstra entre 2 vertices
    */

    string response = sendToServer(inicio.toStdString().c_str(), end.toStdString().c_str());
    QString qstrResponse = QString::fromStdString(response);

    cout << "Recibi del server: " << response << endl;

    ui->label->setText("Camino mas corto: " + qstrResponse);

}
