#include "ground.h"

Ground::Ground(string path,AllBlocks *allBlocks)
{
    qDebug() << "Chargement d'un ground";
    //Initialize allBlocks
    this->allBlocks = allBlocks;
    //Create the variable that load the file
    ifstream load;
    //Open the file
    try {
        load.open(path);
        //If we can't load the file
        if(!load){
            throw QString("Error file does no exist : " + QString::fromStdString(path));
        }
        //We succesfully open the file so we read it and put all the blocks in the vector
        do{
            string line;
            //Get the line
            getline(load,line);
            //Separate the different blocks
            vector<string> elements = Tools::split(line,' ');
            //transform elements to block, GF for good format
            vector<Block> elementsGF = stringToBlock(elements);
            //Push it to t¨final vector
            blocks.push_back(elementsGF);
        }while(!load.eof());
    }  catch (QString e) {
        qDebug() << e;
    }
}

Ground::Ground()
{

}

vector<vector<Block>> *Ground::getBlocks()
{
    return &blocks;
}

void Ground::setBlocks(const vector<vector<Block>> &value)
{
    blocks = value;
}

vector<Block> Ground::stringToBlock(vector<string> vec)
{
    vector<Block> finalVector; //Final vector to return
    for(vector<string>::iterator it = vec.begin(); it !=vec.end(); it++){ //Browse the vector and push the good block
        if(*it=="W"){
            finalVector.push_back(*allBlocks->getWater());
        }else if(*it=="G"){
            finalVector.push_back(*allBlocks->getGrass());
        }else if(*it=="D"){
            finalVector.push_back(*allBlocks->getDirt());
        }else if(*it=="R"){
            finalVector.push_back(*allBlocks->getRoad());
        }
    }
    return finalVector;
}
