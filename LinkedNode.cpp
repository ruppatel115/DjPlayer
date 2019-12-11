/**@file LinkedNode.cpp
 * Implementation of LinkedNode.h for LinkedNodes with Songs for a linked list
 * @authors Forrest Wargo, Rup Patel, Elias Platt, Toby Dragon
 * Originally made by Toby, then converted to use Songs instead of an integer
 */
#include "LinkedNode.h"

LinkedNode::LinkedNode(Song& song){
    this->song = &song;
    next = nullptr;
}

LinkedNode::LinkedNode(const LinkedNode& nodeToCopy){
    song = nodeToCopy.song;
    next = nullptr;
}

Song LinkedNode::getSong(){
    return *song;
}

LinkedNode* LinkedNode::getNext(){
    return next;
}

void LinkedNode::setSong(Song newSong){
    song = &newSong;
}

void LinkedNode::setNext(LinkedNode* newNext){
    next = newNext;
}
