#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* sonraki;
}Node1;
Node1* yeniDugum(int data){
    Node1* yigin=(Node1*) malloc(sizeof(Node1));
    yigin->data=data;
    yigin->sonraki=NULL;
    return yigin;
}
int bosMu(Node1 *kok){
    return !kok;
}
void ekle(Node1** kok,int data){
    Node1* yiginDugum= yeniDugum(data);
    yiginDugum->sonraki=(*kok);
    *kok=yiginDugum;
    printf("%d eklendi\n",data);

}
int cikar(Node1** kok) {
    if(bosMu(kok))
        return INT_MIN;
    Node1* cikar=*kok;
    *kok=(*kok)->sonraki;
    int cikti= cikar->data;
    free(cikar);
    return cikti;
}
int main() {
    Node1* kok=NULL;
    ekle(&kok,10);
    ekle(&kok,20);
    ekle(&kok,30);
    ekle(&kok,50);
    ekle(&kok,40);
    ekle(&kok,60);
    printf("%d cikti", cikar(&kok));
    return 0;
}
