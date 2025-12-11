#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* next;
    Node* prev;

    Node(string name) {
        song = name;
        next = prev = NULL;
    }
};

class Playlist {
    Node* head;
    Node* current;

public:
    Playlist() {
        head = NULL;
        current = NULL;
    }

    void addSong(string name) {
        Node* newSong = new Node(name);

        if (head == NULL) {
            head = current = newSong;
            cout << "Song added: " << name << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newSong;
        newSong->prev = temp;

        cout << "Song added: " << name << endl;
    }

    void deleteSong(string name) {
        if (head == NULL) {
            cout << "Playlist empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->song != name)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Song not found!" << endl;
            return;
        }

        if (temp == head)
            head = head->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        if (temp->prev)
            temp->prev->next = temp->next;

        if (current == temp)
            current = head;

        delete temp;
        cout << "Song deleted: " << name << endl;
    }

    void playNext() {
        if (current == NULL) {
            cout << "No songs in playlist!" << endl;
            return;
        }
        if (current->next == NULL) {
            cout << "Reached end of playlist!" << endl;
            return;
        }
        current = current->next;
        cout << "Now playing: " << current->song << endl;
    }

    void playPrevious() {
        if (current == NULL) {
            cout << "No songs in playlist!" << endl;
            return;
        }
        if (current->prev == NULL) {
            cout << "At the first song!" << endl;
            return;
        }
        current = current->prev;
        cout << "Now playing: " << current->song << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "Playlist empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "---- Playlist ----" << endl;
        while (temp != NULL) {
            cout << temp->song;
            if (temp == current)
                cout << " <- CURRENT";
            cout << endl;
            temp = temp->next;
        }
    }

    void countSongs() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Total songs: " << count << endl;
    }
};

int main() {
    Playlist p;
    int choice;
    string name;

    while (true) {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add Song\n2. Delete Song\n3. Play Next\n4. Play Previous\n5. Display Playlist\n6. Count Songs\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, name);
            p.addSong(name);
            break;

        case 2:
            cout << "Enter song to delete: ";
            cin.ignore();
            getline(cin, name);
            p.deleteSong(name);
            break;

        case 3:
            p.playNext();
            break;

        case 4:
            p.playPrevious();
            break;

        case 5:
            p.display();
            break;

        case 6:
            p.countSongs();
            break;

        case 7:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
