#ifndef _LIST_H_
#define _LIST_H_

using namespace std;
template <class T>
class No{
    private:
    t val;
    No* prox;
    public:
    No(t val){
        this->val=val;
        this->prox=NULL;
    }
    t obterValor(){
        return val;
    }
    No* obterProx(){
        return prox;
    }
    void setProx(No* p){
        prox=p;
    }
};

template <class T>
class Lista{
    private:
    No<T> *cabeca;
    No<T> *cauda;
    public: 
    Lista(){
        cabeca=NULL;
        cauda=NULL;
    }
    Lista(T val){
        cabeca=new No<T>(val);
        cauda=cabeca;
    }
    virtual ~Lista(){
        delete cabeca;
    }
    void mostrar(){
        cout<<"\nImprimindo todos os elementos...\n";
        No<T> *c = cabeca;
        if(vazia()) cout<<"Lista esta vazia\n";
        else{
            while(c){
                cout<<c->obterValor() << endl;
                c=c->obterProx();
            }
            cout<<endl;
        }
    }
    bool vazia(){
        return(cabeca==NULL);
    }
    void inserir_inicio(T val){
        No<T> *novo_no = new No<T>(val);
        novo_no->setProx(cabeca);
        cabeca=novo_no;
    }
    void inserir_final(T val){
        No<T> *novo_no = new No<T>(val);
        if(vazia()){
            cabeca=novo_no;
            cauda=novo_no;
        }
        else{
            cauda->setProx(novo_no);
            cauda=novo_no;
        }
    }
    int tamanho(){
        if(vazia()) return 0;
        No* c = cabeca;
        T tam=0;
        do{
            c=c->obterProx();
            tam++;
        }while(c);
        return tam;
    }
    bool existe(int val){
        No<T> *c = cabeca;
        while(c){
            if(c->obterValor()==val) return true;
            c=c->obterProx();
        }
        return false;
    }
    void remover(){ // remover do final
        if(!vazia()){
            if(cabeca->obterProx()==NULL) //só tem um elemento
            cabeca=NULL;
            else if(cabeca->obterProx()->obterProx()==NULL) //tem 2 elementos
            cabeca->setProx(NULL);
            else{ //mais de 2 elementos
                No<T> *ant_ant = cabeca;
                No<T> *ant = cabeca->obterProx();
                No<T> *corrente=cabeca->obterProx()->obterProx();
                
                while(corrente){
                    No<T> *aux = ant;
                    ant = corrente;
                    ant_ant=aux;
                    corrente=corrente->obterProx();
                }
                delete ant_ant->obterProx();
                ant_ant->setProx(NULL);
                cauda=ant_ant;
            }
        }
    } 
        
};

#endif