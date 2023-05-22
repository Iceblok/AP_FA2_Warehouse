#pragma once

class IContainer {

    public:
        
        // IContainer functions
        virtual bool isEmpty() const = 0;
        virtual bool isFull() const = 0;
                
};
