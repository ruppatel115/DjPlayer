//
// Created by Toby Dragon on 10/17/17.
//
#include "LinkedNode.h"

LinkedNode::LinkedNode(Song song){
    this->song = song;
    next = nullptr;
}

LinkedNode::LinkedNode(const LinkedNode& nodeToCopy){
    song = nodeToCopy.song;
    next = nullptr;
}

Song LinkedNode::getSong(){
    return song;
}

LinkedNode* LinkedNode::getNext(){
    return next;
}

void LinkedNode::setSong(Song newSong){
    song = newSong;
}

void LinkedNode::setNext(LinkedNode* newNext){
    next = newNext;
}
