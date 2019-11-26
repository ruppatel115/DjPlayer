cmake_minimum_required(VERSION 3.14)
project(DjPlayer)

set(CMAKE_CXX_STANDARD 14)

add_executable(DjPlayer main.cpp ArtistMapNode.h ArtistMapNode.cpp ArtistMap.h ArtistMap.cpp CommandHandler.cpp CommandHandler.h Library.h LinkedList.h LinkedNode.cpp LinkedNode.h List.h Library.cpp Playlist.cpp Playlist.h SongArrayList.h SongArrayList.cpp Song.h Song.cpp SongList.h)