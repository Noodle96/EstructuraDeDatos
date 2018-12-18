#include "mainwindow.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    vector<char> vc;
    vc.push_back('l');
    vc.push_back('o');
    vc.push_back('s');
    vc.push_back('m');
    vc.push_back('o');
    vc.push_back('n');
    vc.push_back('o');
    vc.push_back('s');
    /*
    for(auto it = vc.begin() ; it != vc.end() ; it++){
        cout << (*it) << endl;
    }
    */

    /*
    vector< vector<int> > Vector2;
    vector<int> v1t;

    for(int y=0;y<10;y++){
        for(int x=0;x<10;x++){
            v1t.push_back(y);
        }
        Vector2.push_back(v1t);
        v1t.clear();
    }

    for(int e = 0 ; e < 10 ; e++){
        for(int j = 0 ; j < 10 ;j++){
            std::cout << Vector2[e][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    return a.exec();
}
