//
// Created by Toby Dragon on 10/30/18.
//

#include "LinkedList.h"
#include <iostream>

/**
     * Constructor
     */
     //O(1)
LinkedList::LinkedList(){
    end = nullptr;
    front = nullptr;
    currSongCount = 0;
}

//Destructor, O(n)
LinkedList::~LinkedList(){
    while (currSongCount != 0){
        removeValueAtFront();
    }
    front = nullptr;
    end = nullptr;


}

/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
 //O(1)
void LinkedList::insertAtEnd(Song songToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    if (end != nullptr && front != nullptr) {   //if it is not the first item
        end->setNext(newNode);
        end=newNode;
    }
    else{               //it is the first item, init top and front
        end=newNode;
        front=newNode;
    }
    currSongCount++;
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
 //O(n)
int LinkedList::getValueAt(int index){
    if (index > currSongCount-1 || index < 0){// || front == nullptr){
        throw std::out_of_range ("Index is invalid");
    }
    LinkedNode * tempNode = front;

    for (int i = 0; i < index; i++){   //Goes through the linked list [index] amt of times
        tempNode = tempNode->getNext();
    }
    int result = tempNode->getItem();
    return result;
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
//O(n)
std::string LinkedList::toString(){
    if(front == nullptr){
        return "{}";
    }

    std::string result = "{";
    LinkedNode* tempNode = front;
    while (tempNode != nullptr){
        result+=std::to_string(tempNode->getItem());
        if (tempNode->getNext() != nullptr){
            result+=", "; //only add comma if the next one is not the end
        }
        tempNode = tempNode->getNext();

    }
    return result + "}";

}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
 //O(1)
bool LinkedList::isEmpty(){
    return front == nullptr;
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
 //O(1)
int LinkedList::itemCount(){
    return currSongCount;

}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
 //O(n)
void LinkedList::clearList(){
    LinkedNode *tempNode;
    while (!isEmpty()){
        tempNode=front->getNext();
        delete front;
        front=tempNode;
        currSongCount--;
    }
    if (isEmpty()){
        currSongCount=0; //not a great solution, fixed a problem with last test of clearlist
    }


}

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
 //O(n)
int LinkedList::find(int numToFind) {
    LinkedNode *tempNode = front;
    int idx;
    for (idx = 0; idx < currSongCount; idx++) {   //Goes through the entire linked list
        if (tempNode->getItem() == numToFind) {
            return idx; //returns the index
        }
        tempNode = tempNode->getNext();

    }
    return -1;
}

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
 //O(n)
int LinkedList::findLast(int numToFind){
    LinkedNode *tempNode = front;
    int idx = -1;
    for (int i = 0; i < currSongCount; i++) {   //Goes through the entire linked list, can't go backwards
        if (tempNode->getItem() == numToFind) {
            idx = i; //saves each successive index of numToFind
        }
        tempNode = tempNode->getNext();

    }
    return idx;

}

/**
 * finds the largest value in the array
 * @return the first index of the maximum value
 * @throws out_of_range exception if the list is empty
 */
 //O(n)
int LinkedList::findMaxIndex(){
    if (this->isEmpty()){
        throw std::out_of_range ("List is empty");
    }
    LinkedNode *tempNode = front;
    int idx = 0;
    int maxTemp = tempNode->getItem();
    for (int i = 0; i < currSongCount; i++) {   //Goes through the entire linked list
        if (tempNode->getItem() > maxTemp) {    //only > so will not return index of repeated max
            maxTemp = tempNode->getItem();
            idx = i; //saves each successive index of maxTemp
        }
        tempNode = tempNode->getNext();

    }
    return idx;             //if max was the first value it will return 0
}

/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
 //O(1)
void LinkedList::insertAtFront(int itemToAdd){
    if (front != nullptr) {
        LinkedNode *tempNode = front;
        LinkedNode *newNode = new LinkedNode(itemToAdd);
        newNode->setNext(tempNode);
        front = newNode;
    }
    else{   //list was empty
        LinkedNode *newNode = new LinkedNode(itemToAdd);
        front = newNode;
        end = newNode;
    }

    currSongCount++;
}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currSongCount)
 */
 //Big O depends on the index, but it is O(n) most of the time
void LinkedList::insertAt(int itemToAdd, int index){

    if (index < 0 || index > currSongCount){
        throw std::out_of_range ("index is invalid");
    }
    if (isEmpty()){
        LinkedNode* newNode = new LinkedNode(itemToAdd);
        front = newNode;
        end = newNode;
    }
    else {
        if (index == 0){
            insertAtFront(itemToAdd);
            currSongCount--;
        }
        else {
            LinkedNode *newNode = new LinkedNode(itemToAdd);
            LinkedNode *iterateNode = front;    //index 0
            for (int i = 0; i < index; i++) { //stops at index -1

                if (i == index - 1) {                     //node right before the node at index
                    //stop iterating through the list, save the next node
                    LinkedNode *tempNode = iterateNode->getNext();
                    iterateNode->setNext(newNode);
                    newNode->setNext(tempNode);
                } else if (iterateNode != nullptr) {
                    iterateNode = iterateNode->getNext();
                }
            }
        }
    }


    currSongCount++;
}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
 //O(n)
int LinkedList::removeValueAtEnd(){

    if (front == nullptr){
        throw std::out_of_range("In removeValueAtEnd, List must have items");
    }

    int removedItem = end->getItem();
    LinkedNode* iterateNode = front;

    for (int i = 0; i < currSongCount;i++) {    //Goes through the entire linked list
        if (iterateNode->getNext() != end){
        iterateNode=iterateNode->getNext();
        }
        else{   //if iterateNode is second to last node
            delete end; //delete current end
            end = iterateNode;  //set end to previous node
        }
    }

    currSongCount--;
    if (currSongCount == 0){
        front = nullptr;
    }
    return removedItem;
}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
 //O(1)
int LinkedList::removeValueAtFront(){

    if (front == nullptr){
        throw std::out_of_range("In removeValueAtFront, List must have items");
    }

    int removedItem = front->getItem();
    LinkedNode* tempNode = front->getNext();

    delete front;
    front = tempNode;

    currSongCount--;
    if (currSongCount == 0){
        end = nullptr;
        front = nullptr;
    }
    return removedItem;
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
 //Big O depends on index again, but usually O(n)
int LinkedList::removeValueAt(int index){
    if (front == nullptr || index > currSongCount-1 || index < 0){
        throw std::out_of_range("Invalid index given to removeValueAt");
    }
    if (index == 0){
        return removeValueAtFront();
    }

    int removedItem = front->getItem(); //defaults to first index since the for loop wouldn't happen if index = 0
    LinkedNode* iterateNode = front;

    //insert for loop and removal here
    for (int i = 0; i < index; i++){
        if (i != index-1){ //moves thru list until index-1
            iterateNode=iterateNode->getNext();
        }
        else{   //if iterateNode is right before index
            LinkedNode* tempNode = iterateNode->getNext(); //save index
            removedItem = tempNode->getItem();
            iterateNode->setNext(tempNode->getNext());
            delete tempNode;
        }
    }

    currSongCount--;
    if (currSongCount == 0){
        front = nullptr;
        end = nullptr;
    }
    return removedItem;
}