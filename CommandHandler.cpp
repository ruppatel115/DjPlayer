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
    PlaylistList = new PlaylistArrayList(20);
    Playlist playlist1;
    numOfSongs = 0;
    numOfPlaylists = 0;
    length = 0;
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
                    addToPlaylist(playlistName.substr(1),song->getTitle(),song->getArtist());
                }


                std::cout << strInput << std::endl;
            }
        }
    }
    else {
        std::cerr <<"save Playlist file  not found." << std::endl;
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
    Song* song = songLibrary->getSong(title,artist);
    if(song != nullptr){
        cout<< song->getTitle()+", by "+song->getArtist()+", "+to_string(song->getLength())+" seconds, came out in "+to_string(song->getYear())+", play count: "+to_string(song->getPlaycount())+"\n";
    }else{
        cout<< "song not found in library\n";

    };
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
                cout<<"song to be removed"<<tempSong.getTitle()<<endl;
                songLibrary->remove( tempSong.getTitle(),tempSong.getArtist());


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

        std::string songList = temp->toString();
        cout<< songList+"\n";

    }else{
        cout<< "playlist not found\n";
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

    //std::cout << "Created new playlist: "+ name << std::endl;
    //std::cout << PlaylistList->playlistCount() << std::endl;

}

void CommandHandler::addToPlaylist(std::string playlist, std::string title, std::string artist) {
    //std::cout <<"at the begining "<<artist<< std::endl;

    int index = PlaylistList->find(playlist);
    if(index>=0) {
        Playlist *temp = PlaylistList->getValueAt(index);
        Song* songToAdd = this->songLibrary->getSong(title, artist);
        //std::cout << this->songLibrary->getSong(title,artist)->getTitle();
        if (songToAdd != nullptr ) {
            //cout<<"song or artist could not be found\n";
            if(temp->findSong(title, artist)==-1) {
                temp->insertAtEnd(songToAdd);
                //cout << "artsit = " << temp->getSong(0)->getArtist() << "\n";
                cout<< "Added song " + title + " to playlist " + playlist + "\n";
            }else{
                cout<< "song already in playlist" <<endl;
            }
        } else {
            cout<< "song or artist could not be found\n";
            //throw std::invalid_argument("Playlist does not exist");
        }
    }else{
        cout<< "palylist does not exist\n";

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
        cout << "Removed playlist (was empty): " + playlist <<endl;
    } else {
        temp->getSong(0)->incrementPlaycount();
        std::string result = "Played song: " + temp->getSong(0)->toString() + " and removed from playlist "+playlist+"\n";
        cout << result << endl;
        temp->removeSong(0);
        //std::cout << "Next song to be played: " + temp->getSong(0) << std::endl;
        if (temp->isEmpty()) {
            PlaylistList->removeAt(playlistIndex);
            cout <<result + "Removed playlist (was now empty): "+playlist <<endl;
        }

    }
}


void CommandHandler::quit(){
    Song* song;
    std::string fileName = "../Save.txt";
    std::ofstream outf(fileName);
    if (outf){
        ArtistMapNode* holder = songLibrary->getFront();
        while(holder != nullptr){
            for(int i=0; i<holder->getSongList()->itemCount();i++) {
                song = holder->getSongList()->getValueAt(i);
                outf << song->getTitle()+", "+song->getArtist()+", "+std::to_string(song->getLength())+", "+std::to_string(song->getYear())+"*"+std::to_string(song->getPlaycount())+'\n';
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

}
/*
 * Get random songs from the library in the while loop and add that song to
 * the playlist
 */

void CommandHandler::createRandomPlaylist(int playDuration, std::string playlistName) {
    for (int i = 0; i < numOfPlaylists; i++) {
        if (playlistName == PlaylistList->getValueAt(i)->getTitle()) {
            throw std::invalid_argument("Playlist already exists");
        }
    }
    if (playDuration <= 0) {
        throw std::invalid_argument("playDuration must be greater than 0");
    }
    int artistCount = songLibrary->getArtistCount();
    if (artistCount <= 0) {
        throw std::out_of_range("Library is empty");
    }

    srand(time(NULL));

    Playlist *newRandPlaylist = new Playlist(playlistName);
    PlaylistList->insertAtEnd(newRandPlaylist);
    int duplicateCounter = 0;

    int randArtistIndex;
    if (artistCount - 1 > 0) {
        randArtistIndex = rand() % (artistCount - 1);
    } else {
        randArtistIndex = 0;
    }

    int randSongIndex; // = rand() % (songCount-1); //do this after getting the artist node
    int randPlaylistDuration = 0;
    while (randPlaylistDuration <= playDuration) {
        if (duplicateCounter > 100) {
            cout << "Unable to add another song, done making playlists" << endl;
            break;
        }

        //Goes to the random artist then picks one of their songs with rand song index
        ArtistMapNode *artistHolder = songLibrary->getArtistAt(randArtistIndex);
        SongList *songListHolder = artistHolder->getSongList();

        if (songListHolder->getSongCount() - 1 > 0) {
            randSongIndex = rand() % (songListHolder->getSongCount() - 1);
        } else {
            randSongIndex = 0;
        }

        Song *songHolder = songListHolder->getValueAt(randSongIndex);
        for (int i = 0; i <=songListHolder->itemCount(); i++){
            int comparison = songHolder->getTitle().compare(songListHolder->getValueAt(i)->getTitle());
            if (comparison >0) {
                songListHolder->insertAt(*songHolder, i);
            } else if (comparison == 0) {

                cout << "duplicate song: " << songHolder->getTitle() << endl;
                duplicateCounter++;
                break;
            }
        }
        if (songHolder->getLength() + randPlaylistDuration >=playDuration) { //if song being added will cause playlist to go over playDuration
            break; //leave the while loop, which ends the function, but this might end a smaller song
        } else {
            if (newRandPlaylist->findSong(songHolder->getTitle(), songHolder->getArtist()) ==-1) { //another check for duplicate songs
                newRandPlaylist->insertAtEnd(songHolder); //finally add the song
            } else {

                cout << "duplicate song: " << songHolder->getTitle() << endl;
                duplicateCounter++;
            }
        }


        if (artistCount - 1 > 0) {
            randArtistIndex = rand() % (artistCount - 1);
        } else { //this happens if the artist has no more songs and  there was only one  artist to begin with
            break;
        }
        randPlaylistDuration = newRandPlaylist->getDuration();
    }
}

////TEST VERSION =====================================================
string CommandHandler::library(bool test){
   return songLibrary->toString();
}

string CommandHandler::displayArtist(std::string artist, bool test){
    if(songLibrary->getArtist(artist) == nullptr){
        return "artist not found\n";
    }else {
        return songLibrary->getArtist(artist)->toString()+"\n";
    }
}

string CommandHandler::song(std::string artist, std::string title, bool test){
    Song* song = songLibrary->getSong(title,artist);
    if(song != nullptr){
        return song->getTitle()+", by "+song->getArtist()+", "+to_string(song->getLength())+" seconds, came out in "+to_string(song->getYear())+", play count: "+to_string(song->getPlaycount())+"\n";
    }else{
        return "song not found in library\n";

    }
}
string CommandHandler::listPlaylists(bool test){
    return PlaylistList->toString();

}
string CommandHandler::playlist(std::string name, bool test) {
    int index = PlaylistList->find(name);
    if(index >=0) {
        Playlist* temp = PlaylistList->getValueAt(index);

        std::string songList = temp->toString();
        return songList+"\n";
    }else{
        return "playlist not found\n";
    }
}
string CommandHandler::addToPlaylist(std::string playlist, std::string title, std::string artist, bool test) {

    int index = PlaylistList->find(playlist);
    if(index>=0) {
        Playlist *temp = PlaylistList->getValueAt(index);
        Song* songToAdd = this->songLibrary->getSong(title, artist);
        if (songToAdd != nullptr ) {
            if(temp->findSong(title, artist)==-1) {
                temp->insertAtEnd(songToAdd);
                return "Added song " + title + " to playlist " + playlist + "\n";
            }else{
                return "song already in playlist\n";
            }
        } else {
            return "song or artist could not be found\n";
        }
    }else{
        return "palylist does not exist\n";

    }

}
string CommandHandler::removeFromPlaylist(std::string playlist, std::string title, std::string artist, bool test){
    int playlistIndex = PlaylistList->find(playlist);
    Playlist* temp = PlaylistList->getValueAt(playlistIndex);
    int songIndex = temp->findSong(title, artist);
    if (songIndex != -1) {

        temp->removeSong(songIndex);
        return "Removed song "+title+".";

    }
    else{
        return "No such song "+title+" in playlist or playlist is empty";
    }


}
std::string CommandHandler::playNext(std::string playlist, bool test) {
    int playlistIndex = PlaylistList->find(playlist);
    Playlist *temp = PlaylistList->getValueAt(playlistIndex);
    if (temp->isEmpty()) {
        PlaylistList->removeAt(playlistIndex);
        return "Removed playlist (was empty): " + playlist;
    } else {
        temp->getSong(0)->incrementPlaycount();
        std::string result = "Played song: " + temp->getSong(0)->toString() + " and removed from playlist "+playlist+"\n";
        temp->removeSong(0);
        if (temp->isEmpty()) {
            PlaylistList->removeAt(playlistIndex);
            return result + "Removed playlist (was now empty)";


        }
        return result;

    }

}



