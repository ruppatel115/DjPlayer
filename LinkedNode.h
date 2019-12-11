/**@file LinkedNode.h
 * Interface for LinkedNodes with Songs for a linked list
 * @authors Forrest Wargo, Rup Patel, Elias Platt, Toby Dragon
 * Originally made by Toby, then converted to use Songs instead of an integer
 */

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
