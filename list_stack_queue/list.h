/*
 * @Author: your name
 * @Date: 2021-01-16 14:29:09
 * @LastEditTime: 2021-01-16 16:01:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \DataStruct\listADT\list.h
 */
#ifndef _LIST_H
#define _LIST_H

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List makeEmpty(List l);
int isEmpty(List l);
int isLast(Position p, List l);
Position find(ElementType e, List l);
void insertElem(ElementType e, List l, Position p);
void deleteElem(ElementType e, List l);
Position header(List l);
Position first(List l);
Position advance(Position p);
ElementType retrieve(Position p);

#endif /*_LIST_H*/
