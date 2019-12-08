//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Song.h"

class LinkedNode {

private:
    Song* song;
    LinkedNode* next;

public:
    LinkedNode(Song& song);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    Song getSong();
    LinkedNode* getNext();
    void setSong(Song newSong);
    void setNext(LinkedNode* newNext);
};


#endif //LINKEDNODE_H
