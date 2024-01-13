#ifndef HOSPITALS_TABU_HPP
#define HOSPITALS_TABU_HPP

#define Neigbour_mode 1
#define SIZE_ 5
#define TABU_SIZE 5

#include "structures.hpp"
#include <map>
#include <utility>
#include <vector>

//wektor, ktory ma swoja dlugosc, po przekroczeniu dlugosci zaczyna nadpisywac
//elementy zaczynajac od poczatku, wektor ma dlugosc dwa razy wieksza niz podana
//w tabu, przy jednej iteracji dodaje dwie pary do listy:
// {karetka1, index1_przeniesionego_pacjenta}, {karetka2, index2_przeniesionego_pacjenta}

class TabuList{
public:
    TabuList(int size): size_(size * 2){}

//dodaje dwie pary do listy tabu, jesli jest zapelniona dodaje od poczatku
    void update_tabu(std::map<Ambulance, int> const &pair1, std::map<Ambulance, int> const &pair2);

    int check_if_in_tabu(std::map<Ambulance, int> const &pair1, std::map<Ambulance, int> const &pair2);

private:
    int size_;
    std::vector<std::map<Ambulance, int>> tabu_l;
    int save_index = 0;
};

void copy_ambulance_vector(std::vector<Ambulance*> orginal, std::vector<Ambulance*>& copy);

std::vector<Ambulance*> TabuSearch();

extern int max_liczba_iteracji;

extern double najlepszy_wynik;

//lista wszsystkich szpitali, trzeba ja kiedys stworzyc
extern std::vector<Hospital*> hospital_list;

//lista wszystkich pacjentow
extern std::vector<Patient*> patients_list;

//lista wszystkich karetek
extern std::vector<Ambulance*> ambulance_list;

#endif //HOSPITALS_TABU_HPP



