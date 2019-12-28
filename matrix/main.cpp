

#include <iostream>
#include <vector>
#include "Matrix_class.hpp"
using std::vector;



int main(int argc, const char * argv[]) {
    
    Matrix myMatrix;
    
    std::cin>>myMatrix;
    std::cout<<myMatrix;
    
    std::cout<<"//////////"<<std::endl;
    
    Matrix myMatrix2;
    
    std::cin>>myMatrix2;
    std::cout<<myMatrix2;
    
    std::cout<<"//////////"<<std::endl;
    
    if(myMatrix==myMatrix2){
        std::cout<<"Equal"<<std::endl;
    }
    else{
        std::cout<<"Not Equal"<<std::endl;
    }
    
    Matrix matrix3 = myMatrix + myMatrix2;
        
    std::cout<<matrix3;
    return 0;
}

