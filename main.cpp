#include <iostream>
#include <fstream>

using namespace std;

class Bmp{
    int sizeInByte;
    int coordDataFile;
    int widthPic;
    int heightPic;
    int bitOnPixel;
public:
    Bmp(int sizeInByte, int coordDataFile, int widthPic, int heightPic, int biteOnPixel){
        this->sizeInByte = sizeInByte;
        this->coordDataFile = coordDataFile;
        this->widthPic = widthPic;
        this->heightPic = heightPic;
        this->bitOnPixel = biteOnPixel;
    }
    int getSizeInByte() const{
        return sizeInByte;
    }
    int getCoordDataFile() const{
        return coordDataFile;
    }
    int getWidthPic() const{
        return widthPic;
    }
    int getHeightPic() const{
        return heightPic;
    }
    int getBitOnPixel() const{
        return bitOnPixel;
    }
};

int readByte(ifstream &file, int size){
    char buffer[size];
    int value = 0;
    if (file.read(buffer, size)) {
        for(int i = 0; i < size; i++){
            value |= (static_cast<unsigned char>(buffer[i]) << i*8);
        }
        return value;
    }
}

void printInf(Bmp obj){
    cout << "Size: " << obj.getSizeInByte() << "\n";
    cout << "When start data picture: " << obj.getCoordDataFile() << "\n";
    cout << "Width: " << obj.getWidthPic() << "\n";
    cout << "Height: " << obj.getHeightPic() << "\n";
    cout << "Bit on pixel: " << obj.getBitOnPixel() << "\n";
}

int main() {
    ifstream file("C:\\FirstCursProgramm\\C++\\bmpFile\\sankt-peterburg-piter-rossiya-spb.bmp", std::ios::binary);
    if (file.is_open()) {
        cout << "File type:";
        char byte[2];
        file.read(byte, 2);
        cout << char (byte[0]) << char (byte[1]) << "\n";
        int sizeInByte = readByte(file, 4);
        readByte(file, 4);
        int coordDataFile = readByte(file, 4);
        readByte(file, 4);
        int widthPic = readByte(file, 4);
        int heightPic = readByte(file, 4);
        readByte(file, 2);
        int biteOnPixel = readByte(file, 2);
        file.close();
        Bmp obj(sizeInByte, coordDataFile, widthPic, heightPic, biteOnPixel);
        printInf(obj);
    } else {
        cerr << "Unable to open file" << endl;
    }
    getchar();
    return 0;
}
