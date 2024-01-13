#include <iostream>
//#include "tabu.hpp"
//
//int Patient::pat_id = 0;
//int Ambulance::amb_id = 0;
//
//void swap1(Ambulance &amb1, Ambulance &amb2, int patient1_idx, int patient2_idx) {
//    std::vector<Patient*> order1 = amb1.get_order();
//    std::vector<Patient*> order2 = amb2.get_order();
//
//    Patient* patient_temp = order1[patient1_idx];
//    order1[patient1_idx] = order2[patient2_idx];
//    order2[patient2_idx] = patient_temp;
//
//    amb1.new_order(order1);
//    amb2.new_order(order2);
//}
//
//
//void NeighbourSelect(Ambulance &amb1, Ambulance &amb2, std::vector<Ambulance*> solutions){
//
//            swap1(amb1, amb2, 0, 0);
//
//        }
//
//
//int main(){
//    std::vector<std::string> specializations= {
//            "Ortopedia",
//            "Okulistyka",
//            "Neurologia",
//            "Chirurgia",
//            "Kardiologia",
//            "Pediatria",
//            "Endokrynologia",
//            "Geriatria",
//            "Ginekologia",
//            "Urologia",
//            "Psychiatria",
//            "Oparzenia",
//            "Gastroenterologia"};
//
//    Hospital hos_1(0,  0 , specializations, std::vector<int>{0,0,0,0,0,0,0,0,0,0,0,0,0});
//    Hospital hos_2(1,  1 , specializations, std::vector<int>{0,0,0,0,0,0,0,0,0,0,0,0,0});
//
//    Ambulance ambulance_1(&hos_1);
//    Ambulance ambulance_2(&hos_2);
//
//    Patient pat_1(0,0,0,specializations,std::vector<int>{0,0,0,0,0,0,0,0,0,0,0,0,0},0);
//    Patient pat_2(1,1,1,specializations,std::vector<int>{0,0,0,0,0,0,0,0,0,0,0,0,0},0);
//
//    ambulance_1.add_patient(&pat_1);
//    ambulance_2.add_patient(&pat_2);
//
//    std::vector<Ambulance*> global_solution = {&ambulance_1};
//    std::vector<Ambulance*> solution = {&ambulance_2};
//
//
////    NeighbourSelect(ambulance_1, ambulance_2, solution);
//    swap1(ambulance_1, ambulance_2, 0, 0);
//
//    int x = 5;
//
//
//
//}
#include <tabu.hpp>
int Patient::pat_id = 0;
int Ambulance::amb_id = 0;

void swap1(Ambulance &amb1, Ambulance &amb2, int patient1_idx, int patient2_idx) {

    std::vector<Patient*> order1 = amb1.get_order();
    std::vector<Patient*> order2 = amb2.get_order();

    Patient* patient_temp = order1[patient1_idx];
    order1[patient1_idx] = order2[patient2_idx];
    order2[patient2_idx] = patient_temp;

    amb1.new_order(order1);
    amb2.new_order(order2);
}


void NeighbourSelect(Ambulance &amb1, Ambulance &amb2, std::vector<Ambulance> solutions){

    swap1(amb1, amb2, 0, 0);

}


int main(){
    std::vector<std::string> specializations= {
            "Ortopedia",
            "Okulistyka",
            "Neurologia",
            "Chirurgia",
            "Kardiologia",
            "Pediatria",
            "Endokrynologia",
            "Geriatria",
            "Ginekologia",
            "Urologia",
            "Psychiatria",
            "Oparzenia",
            "Gastroenterologia"};

    Hospital hos_1(0,  0 , specializations, std::vector<int>{0,0,0,0,0,0,0,0,0,0,0,0,0});
    Hospital hos_2(1,  1 , specializations, std::vector<int>{0,0,0,0,0,0,0,0,0,0,0,0,0});

    Ambulance ambulance_1(&hos_1);
    Ambulance ambulance_2(&hos_2);

    Patient pat_1(0,0,0, specializations,std::vector<int>{0,0,0,0,0,0,0,0,0,0,0,0,0}, 0);
    Patient pat_2(1,1,1, specializations,std::vector<int>{0,0,0,0,0,0,0,0,0,0,0,0,0}, 0);

    ambulance_1.add_patient(&pat_1);
    ambulance_2.add_patient(&pat_2);

    std::vector<Ambulance*> global_solution = {&ambulance_1, &ambulance_2};
    std::vector<Ambulance*> solution;

    for (Ambulance* ambulance : global_solution) {
        // Wywołaj konstruktor kopiujący lub klonujący obiekt Ambulance
        Ambulance* clonedAmbulance = new Ambulance(*ambulance);
        solution.push_back(clonedAmbulance);
    }

//    NeighbourSelect(ambulance_1, ambulance_2, solution);
    swap1(*solution[0], *solution[1], 0, 0);

    for (Ambulance* clonedAmbulance : solution) {
        delete clonedAmbulance;
    }

    return 0;
}
