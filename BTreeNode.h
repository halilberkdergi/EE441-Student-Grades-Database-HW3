#ifndef BTREENODE_H
#define BTREENODE_H
#include "Student.h"

template <class T>
class BTreeNode
{
    public:
        BTreeNode<T> * Children[3];
        T data[2];
        /* constructor initializes all children pointers to
        null, inserts the items in the data field of the BTreeNode in
        the correct order*/
        BTreeNode (T* items, BTreeNode<T> ** C=NULL);
};

template <class T>
BTreeNode<T>::BTreeNode(T* items, BTreeNode<T> ** C)
{
   *data     = ( *items < *(items+1) ) ?    *items     : *(items+1) ; //B�y�k olan itemi sa�a yerle�tir
   *(data+1) = ( *items < *(items+1) ) ?    *(items+1) : *items   ;   // K���k olan itemi sola yerle�tir

   for ( int i = 0 ; i < 3 ; i++ )
   {
       *(Children + i) = *(C + i) ;
       *(Children + i) = NULL;

   }


}


#endif // BTREENODE_H
