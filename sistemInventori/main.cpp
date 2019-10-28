#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

//using namespace std;

int main()
{
    int maxJml, pilih, acak, hapus;
    std::vector<std::string> item{"pisau","pistol","pedang","pisang","ikan"};
    std::vector<int> stat{1,2,3,4,5};
    std::vector<std::string> inventori;
    std::vector<std::string>::iterator iter;
    char jawab = 'y';

    std::cout << "Menu Inventory ;)" << std::endl;
    std::cout << "Input Max Item : ";
    std::cin >> maxJml;

    while(jawab == 'y'){
        std::cout << "\nSilahkan Pilih Menu Inventori <3" << std::endl;
        std::cout << "1. Tampil Item" << std::endl;
        std::cout << "2. Tambah Item" << std::endl;
        std::cout << "3. Hapus Item" << std::endl;
        std::cout << "Pilihan Anda : "; std::cin >> pilih;

        switch(pilih){
            case 1 :{
                if(inventori.empty()){
                    std::cout << "Invetori Masih Kosong..." << std::endl;
                }else{
                    std::cout << "\nIsi Invetori Anda : " << std::endl;
                    for(iter = inventori.begin(); iter != inventori.end(); iter++){
                        std::cout << *iter << std::endl;
                    }
                }
                break;
            }
            case 2 :{
                if(inventori.size() == maxJml){
                    std::cout << "Item Penuh!" << std::endl;
                }else{
                    srand(static_cast<unsigned int>(time(0)));
                    acak = rand()%item.size();
                    std::cout << "Anda Mendapat Item : " << item[acak] << std::endl;
                    inventori.push_back(item[acak]);
                }
                break;
            }
            case 3 :{
                if(inventori.empty()){
                    std::cout << "Inventori Anda Masih Kosong!" << std::endl;
                }else{
                    for(iter = inventori.begin(); iter != inventori.end(); iter++){
                        std::cout << *iter << std::endl;
                    }
                    std::cout << "\nItem Ke- Berapa Yang Ingin Dihapus? "; std::cin >> hapus;
                    inventori.erase(inventori.begin()+hapus-1);
                    std::cout << "Item Dihapus\n" << std::endl;
                }
                break;
            }
        }
        std::cout << "Ingin Edit Inventori Lagi? (y/n) "; std::cin >> jawab;
    }

    return 0;
}
