/*Rio de Janeiro - Federal University of Rio de Janeiro*/

/********** Includes *********/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "main.h"
#include <string>
#include <unistd.h>

#include <Python.h>

#define OK  0


/********* Statics functions declarations */
static int plotarPolinomio_(const int, const int);
static int convercaoPolar_(const int, int);
static void initPythonModule(void);

/********* Variable declarations */
int escolhaMenu = 10;


int main(void)
{
    initPythonModule();

    while (escolhaMenu =! 0) {
        cout << "1 - Plotar polinomio\n";0,
        cout << "2 - Conversao Polar\n";
        cout << "3 - a definir 3 \n";
        cout << "4 - a definir 4\n";
        cout << "5 - a definir 5\n" << endl;
        cout << "0 - Sair do Programa.\nEntre com uma OPCAO : ";
        cin >> escolhaMenu;
        cout << "\n";

        switch (escolhaMenu)
        {
        case EscolhaMenu::sair:
            cout << "Saindo do Programa !!!\n\n" << endl;
            return OK;
        case EscolhaMenu::plotarPolinomio:
            cout << "Entre com o numero : ";
            int polinomio, coeficiente;
            cin >> polinomio;
            cout << "Entre com o coeficiente: ";
            cout << "\n";
            cin >> coeficiente;

            plotarPolinomio_(polinomio, coeficiente);
            break;

        case EscolhaMenu::convercaoPolar:
            break;

        case 3:
            break;
        
        case 4:
            break;

        case 5:
            break;

        default:
            cout << "Saindo do Programa !!!\n\n" << endl;
            return OK;
        }
    }
    return OK;
}

static int plotarPolinomio_(const int x , const int y){

    Py_Initialize();

    // Importe o módulo Python
    PyObject *pName = PyUnicode_DecodeFSDefault("src/python/main");
    PyObject *pModule = PyImport_Import(pName);
    Py_XDECREF(pName);

    if (pModule != NULL) {
        // Obtenha a função Python do módulo
        PyObject *plotarPolinomioPython = PyObject_GetAttrString(pModule, "polinomio");

        if (plotarPolinomioPython && PyCallable_Check(plotarPolinomioPython)) {
            PyObject args;
            // Chame a função Python
            PyObject_CallObject(plotarPolinomioPython, NULL);
            Py_XDECREF(plotarPolinomioPython);
        } else {
            PyErr_Print();
        }

        Py_XDECREF(pModule);
    } else {
        PyErr_Print();
    }

    // Finalize o interpretador Python
    Py_Finalize();

    return OK;
}

static int convercaoPolar_(const int x, int y){
    return OK;
}

static void initPythonModule(void){
    cout << "START MODULE PYTHON." << endl;

    return;
}