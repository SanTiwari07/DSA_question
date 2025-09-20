#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string title;
    int duration;
    Song* next;

    Song(string t, int d) {
        title = t;
        duration = d;
        next = nullptr;
    }
};

class Playlist {
private:
    Song* current;

public:
    Playlist() {
        current = nullptr;
    }

    // Add a new song
    void addSong(string title, int duration) {
        Song* newSong = new Song(title, duration);
        if (!current) {
            current = newSong;
            newSong->next = newSong; // circular
        } else {
            Song* temp = current;
            while (temp->next != current) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->next = current;
        }
        cout << "Song added: " << title << endl;
    }

    // Delete a song by title
    void deleteSong(string title) {
        if (!current) {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* temp = current;
        Song* prev = nullptr;

        do {
            if (temp->title == title) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    // Deleting current node
                    if (temp->next == current) { // only one song
                        delete temp;
                        current = nullptr;
                        cout << "Song deleted. Playlist is now empty.\n";
                        return;
                    }
                    Song* last = current;
                    while (last->next != current) {
                        last = last->next;
                    }
                    current = current->next;
                    last->next = current;
                }
                delete temp;
                cout << "Song deleted: " << title << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != current);

        cout << "Song not found.\n";
    }

    // Play next song
    void nextSong() {
        if (!current) {
            cout << "Playlist is empty.\n";
            return;
        }
        current = current->next;
        cout << "Now playing: " << current->title << " (" << current->duration << " sec)" << endl;
    }

    // Display all songs
    void showPlaylist() {
        if (!current) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "\n--- Current Playlist ---\n";
        Song* temp = current;
        do {
            cout << temp->title << " (" << temp->duration << " sec)" << endl;
            temp = temp->next;
        } while (temp != current);
        cout << "-------------------------\n";
    }
};

int main() {
    Playlist pl;
    int choice;
    string title;
    int duration;

    do {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add Song\n2. Delete Song\n3. Next Song\n4. Show Playlist\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter song title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter duration (in sec): ";
            cin >> duration;
            pl.addSong(title, duration);
            break;
        case 2:
            cout << "Enter song title to delete: ";
            cin.ignore();
            getline(cin, title);
            pl.deleteSong(title);
            break;
        case 3:
            pl.nextSong();
            break;
        case 4:
            pl.showPlaylist();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}