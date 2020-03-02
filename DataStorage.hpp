//#include <iostream>
//#include <vector>
#include <map>
#include "GameObject.hpp"

class DataStorage
{
    public:
        
        bool addObject(GameObject& newObject);
        bool deleteObject(std::string name);
        GameObject* getObject(std::string name);
        std::vector<GameObject>* getAllBojects();

    private:

        std::map <std::string, GameObject> objects;        

};

bool DataStorage::addObject(GameObject& newObject)
{
    std::string name = newObject.name;
    
    if (objects.find(name) == objects.end()) // check, that it doesn't exist in objects
    {    
        objects[name] = newObject;
        return true;
    }

    else
    {
        std::cout << "This element is already in DataStorage" << '\n';
        return false;
    }
    
}