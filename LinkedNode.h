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
    Song* song; //pointer to a Song object
    LinkedNode* next; //points to the next node if there is one

public:
    /**
     * Constructor
     * @param pointer to a song object in heap
     */
    explicit LinkedNode(Song* song);

    /**
     * Copy constructor, allows us to make a deep copy of the given node
     * It only copies the song, next is set to nullptr.
     * @param nodeToCopy
     */
    LinkedNode(const LinkedNode& nodeToCopy);
    /**
     * Gets the song in the node
     * @return a pointer to the song object
     */
    Song* getSong();
    /**
     * Gets the next node
     * @return a pointer to the next node
     */
    LinkedNode* getNext();
    /**
     * sets the song in the node to given song
     * @param newSong pointer
     */
    void setSong(Song* newSong);
    /**
     * sets the next pointer of this node to point to the given node
     * @param newNext node pointer
     */
    void setNext(LinkedNode* newNext);
};


#endif //LINKEDNODE_H
