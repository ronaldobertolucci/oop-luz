#include "queue.hpp"
#include "stack.hpp"
#include "linked.hpp"

#include <cstdio>

void clearBuffer() {
    while (getchar() != '\n');    
}

void queueMenu()
{
    Queue queue = Queue();
    int option, i;

    // for (i = 1000000; i > 0; i--)
    // {
    //     queue.add(i);
    // }

    do {
        cout << "\nEscolha: ";
        cout << "\n1 - Adicionar elemento";
        cout << "\n2 - Excluir elemento";
        cout << "\n3 - Mostrar fila";
        cout << "\n4 - Tamanho da fila";
        cout << "\n5 - Apagar elementos da fila";
        cout << "\n0 - Voltar para o menu anterior\n\n";
        cin >> option;
        clearBuffer();

        switch (option)
        {   
            case 1:
                cout << "\nInsira o valor do elemento: ";
                cin >> i;
                clearBuffer();
                queue.add(i);
                break;
            case 2:
                queue.remove();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "\nA lista possui "<< queue.getSize() << " elemento(s)\n";
                break;
            case 5: 
            case 0:
                queue.empty();
                break;
            default:
                cout << "\nIncorreto. Tente novamente.\n";
                break;
        }
    } while(option != 0);
}

void stackMenu()
{
    Stack stack = Stack();
    int option, i;

    // for (i = 1000000; i > 0; i--)
    // {
    //     stack.add(i);
    // }

    do {
        cout << "\nEscolha: ";
        cout << "\n1 - Adicionar elemento";
        cout << "\n2 - Excluir elemento";
        cout << "\n3 - Mostrar pilha";
        cout << "\n4 - Tamanho da pilha";
        cout << "\n5 - Apagar elementos da pilha";
        cout << "\n0 - Voltar para o menu anterior\n\n";
        cin >> option;
        clearBuffer();

        switch (option)
        {   
            case 1:
                cout << "\nInsira o valor do elemento: ";
                cin >> i;
                clearBuffer();
                stack.add(i);
                break;
            case 2:
                stack.remove();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "\nA lista possui " << stack.getSize() << " elemento(s)\n";
                break;
            case 5: 
            case 0:
                stack.empty();
                break;
            default:
                cout << "\nIncorreto. Tente novamente.\n";
                break;
        }
    } while(option != 0);
}

void linkedlistMenu()
{
    LinkedList list = LinkedList();
    int option, i;

    // for (i = 50000; i > 0; i--)
    // {
    //     list.add(i);
    //     list.addHead(i);
    // }
    // for (i = 50000; i > 0; i--)
    // {
    //     list.remove();
    //     list.removeTail();
    // }

    do {
        cout << "\nEscolha: ";
        cout << "\n1 - Adicionar elemento no inicio";
        cout << "\n2 - Adicionar elemento no fim";
        cout << "\n3 - Excluir elemento no inicio";
        cout << "\n4 - Excluir elemento no fim";
        cout << "\n5 - Mostrar lista";
        cout << "\n6 - Tamanho da lista";
        cout << "\n7 - Apagar elementos da lista";
        cout << "\n0 - Voltar para o menu anterior\n\n";
        cin >> option;
        clearBuffer();

        switch (option)
        {   
            case 1:
                cout << "\nInsira o valor do elemento: ";
                cin >> i;
                clearBuffer();
                list.addHead(i);
                break;
            case 2:
                cout << "\nInsira o valor do elemento: ";
                cin >> i;
                clearBuffer();
                list.add(i);
                break;
            case 3:
                list.remove();
                break;
            case 4:
                list.removeTail();
                break;
            case 5: 
                list.display();
                break;
            case 6: 
                cout << "\nA lista possui " << list.getSize() << " elemento(s)\n";
                break;
            case 7:
            case 0:
                list.empty();
                break;
            default:
                cout << "\nIncorreto. Tente novamente.\n";
                break;
        }
    } while(option != 0);
}

void menu() 
{
    int option;
    do 
    {
        cout << "\nEscolha o tipo de estrutura: ";
        cout << "\n1 - Fila";
        cout << "\n2 - Pilha";
        cout << "\n3 - Lista encadeada";
        cout << "\n0 - Sair\n\n";
        cin >> option;
        clearBuffer();

        switch (option)
        {   
            case 1:
                queueMenu();
                break;
            case 2:
                stackMenu();
                break;
            case 3:
                linkedlistMenu();
                break;
            case 0:
                break;
            default:
                cout << "\nIncorreto. Tente novamente.\n";
                break;
        }
    } while(option != 0);
}

int main() {
    menu();
    return 0;
}