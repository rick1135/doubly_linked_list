#include <iostream>
#include "list.h"

int main(int argc, char *argv[])
{
    Lista<int> l;
    
    if(l.vazia()) cout<<"Lista vazia!\n";
    else cout<<"Lista NAO vazia!\n";
    
    l.mostrar();
    
    if(l.existe(10)) cout<<"\nO elemento existe na lista!";
    else cout<<"\nO elemento NAO existe na lista!";
    
    l.inserir_final(10);
    l.inserir_final(20);
    l.inserir_final(30);
    l.inserir_final(40);
    l.inserir_inicio(0);
    
    l.mostrar();
    
    if(l.vazia()) cout<<"Lista vazia!\n";
    else cout<<"Lista NAO vazia!\n";
    
    if(l.existe(10)) cout<<"\nO elemento existe na lista!";
    else cout<<"\nO elemento NAO existe na lista!";
    
    l.remover();
    
    l.mostrar();
    
    cout<<"Tamanho da lista:" << l.tamanho()<<endl;

    return 0;
}