class Component
{
    public:
        
        std::string name;
    
    private:

};

class GameObject
{
    public:
        
        std::string name;

        template <typename T>
        bool addComponent(T);

        template <typename T>
        void deleteComponent(T);

        template <typename T>
        T* getComponent(T);


    private:

        std::vector<Component> components;
};

template <typename T>
bool GameObject::addComponent(T comp)
{
    for(Component c: components)
    {    
        if(c.name == typeid(T).name()) // Can't check it's work, lack of test components
        {    
            std::cout << "This component is already adeed" << '\n';
            return false;
        }
    }
    T* obj = new T;
    components.push_back(*obj);
    return true;
}

template <typename T>
T* GameObject::getComponent(T)
{
    for(Component* c: components)
        if(c->name == typeid(T).name())
            return static_cast<T*>(c);

    return nullptr;
}
