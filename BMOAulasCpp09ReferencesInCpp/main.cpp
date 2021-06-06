//
//  main.cpp
//  BMOAulasCpp09ReferencesInCpp
//
//  Created by Breno Medeiros on 28/06/20.
//  Copyright © 2020 ProgramasBMO. All rights reserved.
//

#include <iostream>

#define Log(x) std::cout << x << std::endl

void incrementarNoValor(int valor) {        //RECEBE A COPIA DO VALOR.
    valor++;    //Essa variavel local é independente(diferente) da passado, pois so se copiou o valor.
}

void incrementarComEndereco(int* valor) {    //RECEBE O ENDEREÇO.
    (*valor)++; //Re-referenciar antes, e depois incrementar.
}

void incrementarComReferencia(int& valor) {  //RECEBE A REFERENCIA.
    valor++;    //Não precisa Re-referenciar antes, pois ja veio referenciado.
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //Decorar: Escrever 'int*' é "a mesma coisa" que escrever '&a'   -->  Ambos são o ENDERECO da variavel.
    //Decorar: Escrever 'int' é "a mesma coisa" que escrever 'int&'  -->  Ambos são o VALOR da variavel.
    
    //Ponteiro: É o que armazena o endereço de uma outra variavel(a principio).
    //Referencia(Alias): Artificio do compilador, que na pratica, é a própria variavel(para todos os fins).
    
    Log("-------- incrementarNoValor --------");
    
    int a=5;
    incrementarNoValor(a);
    Log(a);
    
    Log("-------      REFERENCIA    ---------");
    
    int* ptrA = &a;     //o PONTEIRO 'ptrA' armazena o ENDEREÇO de 'a'.
    int& refA = a;      //'refA' é a REFERENCIA da VARIAVEL 'a'.
    
    //Por conta do referenciamento 'a'=='refA' sempre, e um pode ser usado no lugar do outro:
    refA = 2;
    Log(a);
    
    Log("--------  ENDERECO e VALOR  --------");
    
    incrementarNoValor(a);              //Não resolve: So incrementara a variavel local da funcao.
    Log(refA);
    incrementarComEndereco(&a);         //Resolve: Porem exige conversao dentro da função.
    Log(refA);
    incrementarComReferencia(a);        //Resolve: Perfeito, sem precisar converter dentro da funcao.
    Log(refA);
    
    Log("--------    IMUTABILIDADE   --------");
    
    //Obs: Uma vez que se inicializa a referencia, não se pode mais mudar:
    int b = 8;
    int& refB = b;
    refB = a;       //Esta copiando o valor de 'a' para 'b'/'refB', em vez de virar a referencia de 'a'.
    Log(refB);
    
    Log("----- Unica Vantagem PONTEIRO ------");
    
    //Obs: So se pode declarar uma referencia se já houver uma outra variavel que a permita inicializar...
    // int& refC;  //Essa linha dará erro por falta de inicializacao.
    // ... no entanto, ponteiro tem esse poder, por isso utilizamos as duas coisas:
    int* ptr = &a;
    *ptr = 1;       //Podemos manipular o valor da variavel ao qual temos o endereço a vontade
    ptr = &b;       //e depois apontar para outra variavel,
    *ptr = 2;       //e assim mudar também valor de b, tudo com o mesmo ponteiro.
    Log(a);
    Log(b);
    
    //Nota: A referencia faz 'tudo' que o ponteiro faz, porém com mais coisas, e mais sofisticado.
    
    
    return 0;
}
