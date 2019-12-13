/**@file CommandHandler.cpp
 * Implementation of CommandHandler.h, list of commands for a user interface for a DJ Music Player
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */
#include "CommandHandler.h"
#include <iostream>
#include <fstream>
#include "ArtistMap.h"


CommandHandler::CommandHandler() {
    songLibrary = new ArtistMap();
    PlaylistList = new PlaylistArrayList(2);
    Playlist playlist1;
    numOfSongs = 0;
    numOfPlaylists = 0;
    length = 0;
    //promptUser();
    readSaveFiles();
}


void CommandHandler::readSaveFiles(){
    import("../Save.txt");
    ifstream infile("../savedPlaylists.txt");
    string playlistName;
    if (infile) {
        while (infile) {
            std::string strInput;
            getline(infile, strInput);
            if(strInput != "") {
                if(strInput[0] == '*'){
                    playlistName = strInput;
                    newPlaylist(playlistName.substr(1));
                }else {
                    Song* song = new  Song(strInput);
                    addToPlaylist(playlistName,song->getTitle(),song->getArtist());
                }


                std::cout << strInput << std::endl;
            }
        }
    }
    else {
        std::cerr <<"save Playlsit file  not found." << std::endl;
    }

}
ArtistMap* CommandHandler::getSongLibrary(){
    return songLibrary;
}

void CommandHandler::help(){
    std::cout << "*** ALL AVAILABLE COMMANDS ***" << std::endl;
    std::cout << "help: displays this" << std::endl;
    std::cout << "library: displays all songs in the library" << std::endl;
    std::cout << "artist: input an artist after prompt to display all songs by that artist" << std::endl;
    std::cout << "song: input artist and title after respective prompts to display all info for that song" << std::endl;
    std::cout << "import: input a filename after prompt to import all songs from the file into library" << std::endl;
    std::cout << "discontinue: input a filename after prompt to remove all songs from the file from the library " << std::endl;
    std::cout << "list playlists: displays all available playlists" << std::endl;
    std::cout << "playlist: input a playlist name after prompt to display all songs in that playlist and its total duration" << std::endl;
    std::cout << "new: input a name after prompt to make a new empty playlist with that name" << std::endl;
    std::cout << "add: input name, artist, title, duration after respective prompts to add a new song to library with that info" << std::endl;
    std::cout << "remove: input name, artist, title after respective prompts to remove the song from the library with that info" << std::endl;
    std::cout << "playnext: input a playlist name after prompt to display all info about the next song to be played from it, \n"
                 "\t and removes that song and the playlist if it is now empty" << std::endl;
    std::cout << "newrandom: input a playlist name and duration after respective prompts to create a shuffled playlist with random songs\n"
                 "\t from the library until given duration is reached" << std::endl;
    std::cout << "quit: Save all playlists and library to file and end program" << std::endl;
    std::cout << "*** END OF HELP ***" << std::endl;
}




void CommandHandler::library(){
    std::cout << songLibrary->toString() << std::endl;
}

void CommandHandler::displayArtist(std::string artist){
    //std::cout << mainLibrary->getArtistSongs(artist) << std::endl;
    if(songLibrary->getArtist(artist) == nullptr){
        std::cout<<"artist not found\n";
    }else {
        std::cout << songLibrary->getArtist(artist)->toString() << std::endl;
    }
}

void CommandHandler::song(std::string artist, std::string title){
    ArtistMapNode* artistNode = songLibrary->getArtist(artist);
    if(artistNode != nullptr){
       int songIndex = artistNode->getSongList()->find(artist);
       if(songIndex >-1){
           Song* song = artistNode->getSongList()->getValueAt(songIndex);
           std::cout<<song->getTitle()<<", "<<song->getArtist()<<", "<<song->getLength()<<", "<<song->getLength()<<std::endl;
       }else{
           std::cout<< title<<" not found for"<<artist<<"\n";
       }

    }else{
        std::cout<<artist<<" not found in library\n";

    }
}

void CommandHandler::import(std::string fileName){
    std::ifstream infile(fileName);
    if (infile) {
        while (infile) {
            std::string strInput;
            getline(infile, strInput);
            if(strInput != "") {
                songLibrary->put(*new Song(strInput));
                //std::cout << strInput << std::endl;
            }
        }
    }
    else {
        std::cerr << fileName<< " not found." << std::endl;
    }
}

void CommandHandler::discontinue(std::string fileName){
    std::ifstream infile(fileName);
    if (infile) {

        while (infile) {
            std::string strInput;
            getline(infile, strInput);
            if(strInput != "") {
                Song tempSong(strInput);

                for(int i=0; i<PlaylistList->playlistCount();i++){
                    int index = PlaylistList->getValueAt(i)->findSong(tempSong.getTitle(),tempSong.getArtist());
                    if(index>-1){
                        PlaylistList->getValueAt(i)->removeSong(index);
                    }
                }

                songLibrary->remove(tempSong.getArtist(), tempSong.getTitle());

            }
        }
    }
    else {
        std::cerr << fileName<< " not found." << std::endl;
    }
}

void CommandHandler::listPlaylists(){
    std::cout << PlaylistList->toString() <<std::endl;

}


//print out things in playlist
void CommandHandler::playlist(std::string name){
    int index = PlaylistList->find(name);
    if(index >=0) {
        Playlist* temp = PlaylistList->getValueAt(index);
        //TODO something wrong in here

        std::string songList="";
        std::cout <<"item count = "<<temp->getNumSongs() << std::endl;

        for(int i=0; i<temp->getNumSongs();i++){

            std::string title=temp->getSong(i)->getTitle();
            std::string artist=temp->getSong(i)->getArtist();
            int duration =temp->getSong(i)->getLength();
            songList +=  title + ", " + artist + ", "+ std::to_string(duration); ;

        }
        std::cout <<songList << std::endl;


//        std::cout << "Playlist" + name + ": \nDuration: " + std::to_string(temp.calcDuration()) << std::endl;
//        std::cout << "Songs: " + temp.toString();
    }else{
        std::cout << "playlist not found\n";
    }
}

/**
 * Creates a new empty playlist with name and adds it to the list of playlists
 * @param name of the new playlist
 */
void CommandHandler::newPlaylist(std::string name){
    for(int i=0;i<numOfPlaylists;i++){
        if(name==PlaylistList->getValueAt(i)->getTitle()){
            throw std::invalid_argument("Playlist already exists");
        }
    }
    Playlist *newPlaylist = new Playlist(name);
    PlaylistList->insertAtEnd(newPlaylist);

    std::cout << "Created new playlist: "+ name << std::endl;
    std::cout << PlaylistList->playlistCount() << std::endl;

}

void CommandHandler::addToPlaylist(std::string playlist, std::string title, std::string artist) {
    //std::cout <<"at the begining "<<artist<< std::endl;

    int index = PlaylistList->find(playlist);
    Playlist* temp = PlaylistList->getValueAt(index);
    Song *songToAdd = this->songLibrary->getSong(title, artist);
        //std::cout << this->songLibrary->getSong(title,artist)->getTitle();
        if (temp != nullptr) {
            cout<<"song or artist could not be found\n";
            temp->insertAtEnd(songToAdd);
            cout<<"artsit = "<<temp->getSong(0)->getArtist()<<"\n";
            std::cout << "Added new song " + title  + "." << std::endl;
        }
        else{
            throw std::invalid_argument("Playlist does not exist");
        }

}



void CommandHandler::removeFromPlaylist(std::string playlist, std::string title, std::string artist){
    int playlistIndex = PlaylistList->find(playlist);
    Playlist* temp = PlaylistList->getValueAt(playlistIndex);
    int songIndex = temp->findSong(title, artist);
    if (songIndex != -1) {
        temp->removeSong(songIndex);
        std::cout << "Removed song "+title+"." << std::endl;

    }
    else{
        cout << "No such song "+title+" in playlist or playlist is empty" <<endl;
    }


}


void CommandHandler::playNext(std::string playlist) {
    int playlistIndex = PlaylistList->find(playlist);
    Playlist *temp = PlaylistList->getValueAt(playlistIndex);
    if (temp->isEmpty()) {
        PlaylistList->removeAt(playlistIndex);
    } else {
        temp->getSong(0)->incrementPlaycount();
        std::cout << "Next song to be played: " + temp->removeSong(0) << std::endl;
        if (temp->isEmpty()) {
            PlaylistList->removeAt(playlistIndex);
        }

    }
}


void CommandHandler::quit(){
    Song* song;
    std::string fileName = "../DjPlayer/Save.txt";
    std::ofstream outf(fileName);
    if (outf){
        ArtistMapNode* holder = songLibrary->getFront();
        while(holder != nullptr){
            for(int i=0; i<holder->getSongList()->itemCount();i++) {
                song = holder->getSongList()->getValueAt(i);
                outf << song->getTitle()+", "+song->getArtist()+", "+std::to_string(song->getLength())+", "+std::to_string(song->getYear())+'\n';
            }
            holder = holder->getNext();
        }
        outf.close();
    }
    else {// Print an error and exit
        std::cerr << "Can't write to save file" << std::endl;
    }
    string playlistFile = "../savedPlaylists.txt";
    //writing playlists to file
    std::ofstream outf2(playlistFile);
    if (outf2){
        for(int i=0; i<PlaylistList->playlistCount();i++){
            Playlist* holder = PlaylistList->getValueAt(i);
            outf2<<"*"<<holder->getTitle()+"\n";
            for(int j=0; j<holder->getNumSongs();j++){
                song = holder->getSong(j);
                outf2 << song->getTitle()+", "+song->getArtist()+", "+std::to_string(song->getLength())+", "+std::to_string(song->getYear())+'\n';
            }
        }
        outf2.close();
    }
    else {// Print an error and exit
        std::cerr << "Can't write to playlist file" << std::endl;
    }


    //TODO this needs to call destructor
    //delete [] songLibrary;
    //songLibrary = nullptr;
}
/*
 * Get random songs from the library in the while loop and add that song to
 * the playlist
 */

void CommandHandler::createRandomPlaylist(int playDuration, std::string playlistName) {
    for(int i=0;i<numOfPlaylists;i++){
        if(playlistName==PlaylistList->getValueAt(i)->getTitle()){
            throw std::invalid_argument("Playlist already exists");
        }
    }
    srand(time(NULL));

    Playlist *newRandPlaylist = new Playlist(playlistName);
    PlaylistList->insertAtEnd(newRandPlaylist);

    int artistCount = songLibrary->getArtistCount();
    if (artistCount <= 0){
        throw std::out_of_range("Library is empty");
    }

    //int songCount = songLibrary->getSongCount();
    int randArtistIndex;
    if (artistCount-1 > 0) {
        randArtistIndex =rand() % (artistCount - 1);
    }
    else{
        randArtistIndex = 0;
    }

    int randSongIndex; // = rand() % (songCount-1); //do this after getting the artist node
    int randPlaylistDuration = 0;
    while (randPlaylistDuration <= playDuration){

        //Goes to the random artist then picks one of their songs with rand song index
       ArtistMapNode* artistHolder = songLibrary->getArtistAt(randArtistIndex);
       SongArrayList* songListHolder = artistHolder->getSongList();

       if (songListHolder->getSongCount()-1 > 0) {
           randSongIndex = rand() % (songListHolder->getSongCount() - 1);
       }
       else{
           randSongIndex=0;
       }

       Song* songHolder = songListHolder->getValueAt(randSongIndex);
       //TODO getValueAt in songArrayList returns a copy not a pointer
       for(int i=0; i<songListHolder->itemCount();i++){
        int comparison = songHolder->getTitle().compare(songListHolder->getValueAt(i)->getTitle());
           if(comparison < 0){
               //cout<<song.getTitle()<<" orgininal: "<<songList->getValueAt(i).getTitle()<<endl;
               songListHolder->insertAt(*songHolder,i);
           }else if (comparison == 0){
               //cout<<"in duplicate "<<song.getTitle()<<" orgininal: "<<songList->getValueAt(i).getTitle()<<endl;

               cout<<"duplicate song: "<< songHolder->getTitle()<<endl;
               break;
           }
       }
        newRandPlaylist->insertAtEnd(songHolder);

        if (artistCount-1 > 0) {
            randArtistIndex =rand() % (artistCount - 1);
        }
        else{ //this happens if the artist has no more songs and  there was only one  artist to begin with
            break;
        }
       randPlaylistDuration = newRandPlaylist->getDuration();
    }
}
////TEST VERSION =====================================================
string CommandHandler::library(bool test){
    std::cout << songLibrary->toString() << std::endl;
}

string CommandHandler::displayArtist(std::string artist, bool test){
    //std::cout << mainLibrary->getArtistSongs(artist) << std::endl;
    if(songLibrary->getArtist(artist) == nullptr){
        std::cout<<"artist not found\n";
    }else {
        std::cout << songLibrary->getArtist(artist)->toString() << std::endl;
    }
}

string CommandHandler::song(std::string artist, std::string title, bool test){
    Song* song = songLibrary->getSong(title,artist);
    if(song != nullptr){
        std::cout<<song->getTitle()<<", by "<<song->getArtist()<<", "<<song->getLength()<<" seconds, came out in "<<song->getYear()<<std::endl;
    }else{
        std::cout<<"song not found in library\n";

    };
    /*
    ArtistMapNode* artistNode = songLibrary->getArtist(artist);
    if(artistNode != nullptr){
       int songIndex = artistNode->getSongList()->find(artist);
       if(songIndex >-1){
           Song* song = artistNode->getSongList()->getValueAt(songIndex);
           std::cout<<song->getTitle()<<", by  "<<song->getArtist()<<", "<<song->getLength()<<" seconds, year "<<song->getYear()<<std::endl;
       }else{
           std::cout<< title<<" not found for "<<artist<<"\n";
       }

    }else{
        std::cout<<artist<<" not found in library\n";

    }
     */
}
