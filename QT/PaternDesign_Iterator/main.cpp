#include <QCoreApplication>
#include<iostream>
using namespace std;
#include "stdvectorlist.h"
#include "baseballplayerof.h"



StdVectorList<BaseballPlayer> * MakeNewYorkMetsLineup()
{
    StdVectorList<BaseballPlayer> * newYorkMetsLineup = new StdVectorList<BaseballPlayer>();

    newYorkMetsLineup->Append(BaseballPlayer(std::string("Curtis Granderson"), std::string("CF"), 'L'));
    newYorkMetsLineup->Append(BaseballPlayer(std::string("Asdrubal Cabrera"),  std::string("SS"), 'S'));
    newYorkMetsLineup->Append(BaseballPlayer(std::string("Yoenis Cespedes"),   std::string("LF"), 'R'));
    newYorkMetsLineup->Append(BaseballPlayer(std::string("Jay Bruce"),         std::string("RF"), 'L'));
    newYorkMetsLineup->Append(BaseballPlayer(std::string("Neil Walker"),       std::string("2B"), 'S'));
    newYorkMetsLineup->Append(BaseballPlayer(std::string("Lucas Duda"),        std::string("1B"), 'L'));
    newYorkMetsLineup->Append(BaseballPlayer(std::string("Travis d'Arnaud"),   std::string("C"),  'R'));
    newYorkMetsLineup->Append(BaseballPlayer(std::string("Jose Reyes"),        std::string("SS"), 'S'));
    newYorkMetsLineup->Append(BaseballPlayer(std::string("Noah Syndergaard"),  std::string("P"),  'L'));

    return newYorkMetsLineup;
}

void PrintLineup(std::string lineupName, Iterator<BaseballPlayer> * iterator)
{
    std::cout << lineupName << "\n";

     int lineupPosition = 1;

    for(iterator->First(); !iterator->IsDone(); iterator->Next()){
        std::cout << lineupPosition++ << ". " << iterator->CurrentItem() << "\n";
    }

    std::cout << "\n";
}




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout  << "hola" << endl;

    return a.exec();
}
