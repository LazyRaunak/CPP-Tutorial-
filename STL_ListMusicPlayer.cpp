#include <iostream>
#include <list>
#include <iomanip>
#include <iterator>

class Song{
    private:
        friend std::ostream &operator<<(std::ostream &os, const Song &p);
        std::string name;
        std::string artist;
        int rating;

    public:
        Song() = default;
        Song(std::string nameVal, std::string artistVal, int ratingVal)
            :name{nameVal}, artist{artistVal}, rating{ratingVal} {};
        
        std::string getName(){
            return name;
        }

        std::string getArtist(){
            return artist;
        }

        int getRating(){
            return rating;
        }

        bool operator<(const Song &rhs){
            return this->name<rhs.name;
        }

        bool operator==(const Song &rhs){
            return this->name==rhs.name;
        }
};

std::ostream &operator<<(std::ostream &os, const Song &s){
    os<<std::setw(30)<<std::left<<s.name
      <<std::setw(40)<<std::left<<s.artist
      <<std::setw(5)<<std::left<<s.rating;
    return os;
}

void displayMenu(){
    std::cout<<"F - Play first song"<<std::endl;
    std::cout<<"N - Play next song"<<std::endl;
    std::cout<<"P - Play previous song"<<std::endl;
    std::cout<<"A - Add new song at current location"<<std::endl;
    std::cout<<"L - List the current playlist"<<std::endl;
    std::cout<<"===================================="<<std::endl;
    std::cout<<"Enter a selection (Q to quit): ";
}

void playingCurrentSong(const Song &s){
    std::cout<<"Playing: "<<std::endl;
    std::cout<<s<<std::endl;
}

void displayPlaylist(const std::list<Song> &playlist, const Song &s){
    for(const Song &song:playlist)
        std::cout<<song<<std::endl;

    std::cout<<"\nPlaying: "<<std::endl;
    std::cout<<s<<std::endl;

}

int main(){
    std::list<Song> playlist{
        {"Hanuman Chalisa", "Shankar", 5},
        {"Vande Matram", "A.R. Rahman", 5},
        {"Sandese aate hai", "Sonu Nigam", 5},
        {"Genda fool", "Badshaah", 4},
        {"Ke Ghar Kab Aaoge", "Anu Malik", 5}
    };

    std::list<Song>::iterator currentSong = playlist.begin();
    displayPlaylist(playlist, *currentSong);

    char selection{};

    do{
        displayMenu();

        std::cin>>selection;
        selection = std::toupper(selection);

        if(selection == 'F'){
            std::cout<<"Playing first song"<<std::endl;
            currentSong = playlist.begin();
            playingCurrentSong(*currentSong);
        }

        if(selection == 'N'){
            std::cout<<"Playing next song"<<std::endl;
            currentSong++;
            if(currentSong == playlist.end()){
                std::cout<<"Wrapping to first song of the playlist"<<std::endl;
                currentSong = playlist.begin();
            }
            playingCurrentSong(*currentSong);
        }

        if(selection == 'P'){
            std::cout<<"Playing previous song"<<std::endl;
            if(currentSong == playlist.begin()){
                std::cout<<"Wrapping to last song of the playlist"<<std::endl;
                currentSong = playlist.end();
            }
            currentSong--;
            playingCurrentSong(*currentSong);
        }

        if(selection == 'A'){
            std::string name;
            std::string artist;
            int rating;

            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Adding and playing new song"<<std::endl;
            std::cout<<"enter Song name: ";
            std::cin>>name;
            std::cout<<"enter Artist name: ";
            std::cin>>artist;
            std::cout<<"enter rating 1-5: ";
            std::cin>>rating;

            playlist.insert(currentSong, Song{name, artist, rating});
            currentSong--;
            playingCurrentSong(*currentSong);
        }
        
        if(selection == 'L')
            displayPlaylist(playlist, *currentSong);

        if(selection == 'Q')
            std::cout<<"Quitting"<<std::endl;
        
        else
            std::cout<<"Invalid choice, please try again"<<std::endl;
    }while(selection != 'Q');

    std::cout<<"Thanks for listening"<<std::endl;

    return 0;
}