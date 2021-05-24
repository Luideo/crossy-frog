#include "ground.h"

Ground::Ground(string path)
{

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
            vector<Block*> elementsGF = stringToBlock(elements);
            //Push it to t¨final vector
            blocks.push_back(elementsGF);
        }while(!load.eof());
    }  catch (QString e) {
        qDebug() << e;
    }
    /*
    //Create the ground 17*7
    //Create line x
    vector<Block*> line;
    //Push the 17blocks
    line.push_back(water);
    line.push_back(dirt);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    line.push_back(grass);
    //Push the line in blocks
    blocks.push_back(line);
    //Set all Grass
    line.at(0) = grass;
    line.at(1) = grass;

    //Push all the other lines
    blocks.push_back(line);
    blocks.push_back(line);
    blocks.push_back(line);
    blocks.push_back(line);
    blocks.push_back(line);
    blocks.push_back(line);
    */
}

vector<vector<Block*>> Ground::getBlocks() const
{
    return blocks;
}

void Ground::setBlocks(const vector<vector<Block*>> &value)
{
    blocks = value;
}

vector<Block *> Ground::stringToBlock(vector<string> vec)
{
    vector<Block *> finalVector; //Final vector to return
    for(vector<string>::iterator it = vec.begin(); it !=vec.end(); it++){ //Browse the vector and push the good block
        if(*it=="W"){
            finalVector.push_back(new Block(AllBlocks::water()));
        }else if(*it=="G"){
            finalVector.push_back(new Block(AllBlocks::grass()));
        }else if(*it=="D"){
            finalVector.push_back(new Block(AllBlocks::dirt()));
        }
    }
    return finalVector;
}
