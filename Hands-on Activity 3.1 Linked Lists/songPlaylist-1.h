#ifndef SONGPLAYLIST_H
#define SONGPLAYLIST_H

template<typename baka>
class playlist {
public:
    baka song;
    baka artist;
    playlist<baka>* next = nullptr;
    playlist<baka>* prev = nullptr;
};

// default constructor for creating songs
template<typename baka>
playlist<baka>* newSong (baka title, baka author) {
    playlist<baka>* new_Song = new playlist<baka>;
    new_Song->song = title;
    new_Song->artist = author;
    new_Song->next = nullptr;
    new_Song->prev = nullptr;
    return new_Song;
}

// printing the whole playlist
template<typename baka>
void songList (playlist<baka>* firstS) {
    if (firstS == nullptr) {
        std::cout << "Playlist is empty.\n\n";
        return;
    }

    std::cout << "<-------------Start of Playlist------------->\n";
    int count = 1;
    playlist<baka>* firstSong = firstS;
    std::cout << count << ". " << firstS->song << " - " << firstS->artist << std::endl;
    firstS = firstS->next;
    while (firstS != firstSong) {
        count += 1;
        std::cout << count << ". " << firstS->song << " - " << firstS->artist << std::endl;
        firstS = firstS->next;
    }
    std::cout << "<-------------End of Playlist------------->\n";

}

// adding new song, it'll default to the very back
template<typename baka>
void addSong (std::string title, std::string author, playlist<baka>* firstS ) {
    playlist<baka>* prevSong = firstS->prev;

    playlist<baka>* music = newSong(title, author);
    music->prev = prevSong;
    music->next = firstS;
    firstS->prev = music;
    prevSong->next = music;

    std::cout << music->song << " added.\n";

}

//deleting a song
template<typename baka>
void deleteSong (std::string title, playlist<baka>** head, playlist<std::string>** playing) {
    playlist<baka>* currentSong = *head;
    playlist<baka>* firstSong = *head;

    while (currentSong->song != title) {
        currentSong = currentSong->next;
        if (currentSong == firstSong) {
            std::cout << "Song not found... \n";
            return;
        }
    }

    playlist<baka>* nextSong = currentSong->next;
    playlist<baka>* prevSong = currentSong->prev;

    nextSong->prev = prevSong;
    prevSong->next = nextSong;

    // checks if the song about to be deleted is the first song
    if (currentSong == *head) {
        // checks if this song points to itself, meaning it is the only song in the list
        if (currentSong == nextSong) {
            // turns the list into a null
            *head = nullptr;
        } else {
            // assigns the next song in the list to be the first song so from 2nd to 1st
            *head = nextSong;
        }
    }

    std::cout << "\n '" << title << " by " << currentSong->artist << " ' deleted.\n\n";
    if (currentSong == *playing) {
        *playing = nullptr;
    }
    delete currentSong;
}

// playing a song
template<typename baka>
void playSong (std::string title, playlist<baka>** playing, playlist<baka>* head) {
    playlist<baka>* currentSong = head;
    playlist<baka>* firstSong = head;

    while (currentSong->song != title) {
        currentSong = currentSong->next;
        if (currentSong == firstSong) {
            std::cout << "Song not found... \n";
            return;
        }
    }

    *playing = currentSong;
    std::cout << "\nNow playing: " << currentSong->song << " - " << currentSong->artist << "\n";
}

// moving to the next song
template<typename baka>
void nextSong (playlist<baka>** playing) {
    if (*playing == nullptr) {
        std::cout << "\nNothing is playing...\n";
        return;
    }
    *playing = (*playing)->next;
    std::cout << "\nNow playing: " << (*playing)->song << " - " << (*playing)->artist << "\n";
}

// going back to the previous song
template<typename baka>
void prevSong (playlist<baka>** playing) {
    if (*playing == nullptr) {
        std::cout << "Nothing is playing...\n";
        return;
    }
    *playing = (*playing)->prev;
    std::cout << "\nNow playing: " << (*playing)->song << " - " << (*playing)->artist << "\n";
}

// deleting entire playlist
template<typename baka>
void deleteplaylist (playlist<baka>** head, playlist<baka>** playing) {
    if (*head == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    playlist<baka>* currentSong = *head;
    playlist<baka>* firstSong = *head;

    do {
        playlist<baka>* temp = currentSong;
        currentSong = currentSong->next;
        delete temp;
    } while (currentSong != firstSong);

    *head = nullptr;
    *playing = nullptr;

    std::cout << "\nPlaylist successfully deleted.\n";
}

// pause the song
template<typename baka>
void pauseSong (playlist<baka>** playing, bool* isPaused) {
    if (*playing == nullptr) {
        std::cout << "Nothing is playing...\n";
        return;
    }
    if (*isPaused) {
        std::cout << "Song is already paused\n";
    } else {
        std::cout << (*playing)->song << " - " << (*playing)->artist << " is now paused...\n";
        *isPaused = true;
    }
}

// resume the song
template<typename baka>
void resumeSong (playlist<baka>** playing, bool* isPaused) {
    if (*playing == nullptr) {
        std::cout << "Nothing is playing...\n";
        return;
    }
    if (*isPaused == false) {
        std::cout << "Song is already playing\n";
    } else {
        std::cout << (*playing)->song << " - " << (*playing)->artist << " is now resumed\n";
        *isPaused = false;
    }
}

#endif
