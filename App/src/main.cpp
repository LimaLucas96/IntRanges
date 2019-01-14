#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each

#include "../include/int_ranges.h"

std::string print( const int* first, const int* last );

//namespace Com os executaves dos exercicios de funcoes
namespace Ex{

    void ExecuteNegative(){

        int A[]={1,2,3,4,5,6};

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;
        ir::negate( std::begin(A), std::end(A) );
        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;
    }

    void ExecuteMin(){
        int A[]={1,2,-3,-4,5,-6};

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;
        auto result=ir::min(std::begin(A),std::end(A));
        std::cout<<*result<<std::endl;

        result=ir::min(std::begin(A)+1,std::begin(A)+5);

        std::cout<<*result<<std::endl;
    }

    void ExecuteReverse(){
        int A[]={1,2,3,4,5};

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

        ir::reverse (std::begin(A),std::end(A));

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

        ir::reverse(std::begin(A)+1,std::begin(A)+4);

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;
    }

    void ExecuteScalarMultiplication(){
        int Vet[]={1,2,-3,-4,5,-6};

        std::cout << ">>> A: " << print( std::begin(Vet), std::end(Vet) ) << std::endl;

        ir::scalar_multiplication(std::begin(Vet),std::end(Vet),3);

        std::cout << ">>> A: " << print( std::begin(Vet), std::end(Vet) ) << std::endl;
    }

    void ExecuteDotProduct(){
        int Vet[]={1 , 3 , -5 , 4 , -2 , -1 };

        std::cout << ">>> A: " << print( std::begin(Vet), std::end(Vet) ) << std::endl;

        auto result=ir::dot_product(std::begin(Vet),std::begin(Vet)+3,std::begin(Vet)+3);

        std::cout<<"O resultado é: "<<result<<std::endl;
    }

    void ExecuteCompact(){
        int A[]={-2,-8,2,7,-3,10,1,0,-3,7};

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

        int *pt=ir::compact(std::begin(A),std::end(A));

        std::cout << ">>> A: " << print( std::begin(A), pt ) << std::endl;
    }

    void ExecuteCopy(){
        int A[]={1,2,3,4,5};
        int B[]={0,0,0};

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

        auto b_last=ir::copy(std::begin(A)+1,std::begin(A)+4,std::begin(B));

        std::cout << ">>> B: " << print( std::begin(B), b_last ) << std::endl;
    }

    void ExecuteUnique(){
        int A[]={ 1 , 2 , 1 , 2 , 3 , 3 , 1 , 2 , 4 , 5 , 3 , 4 , 5 };

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

        auto last=ir::unique(std::begin(A),std::end(A));

        std::cout << ">>> A: " << print( std::begin(A), last) << std::endl;

        std::cout<<">>> O comprimento logico é: "<<std::distance(std::begin(A),last)<<"\n";
    }

    void ExecuteSortMarbles(){

        enum ball_t{B=0, W=1};

        int A[]={ W , B , B , W , W , B , W };

        std::cout << ">>> Ball: " << print( std::begin(A), std::end(A) ) << std::endl;

        auto result=ir::sort_marbles(std::begin(A),std::end(A));

        std::cout << ">>> A: " << print( std::begin(A), result ) << std::endl;
    }

    void ExecutePartition(){
        int A[]={-5,7,10,7,8,9,8,1,7,8,-2,3,8};

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

        ir::partition(std::begin(A),std::end(A),std::begin(A)+4);

        std::cout << ">>> Ball: " << print( std::begin(A), std::end(A) ) << std::endl;
    }

    void ExecuteRotate(){
        int A[]={ 1, 2, 3, 4, 5, 6, 7 };

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

        ir::rotate(std::begin(A),std::begin(A)+5,std::end(A));

        std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

    }
}

//funcao que imprime o vetor na tela
std::string print( const int* first, const int* last )
    {
    std::ostringstream oss;

    oss << "[ ";
    std::for_each(first, last, [&](const int & a){ oss << a << " ";} );
    oss << "]";
    return oss.str();
}

int main (void){

    std::cout<<"Negative:"<<std::endl;

    Ex::ExecuteNegative();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"Min:"<<std::endl;

    Ex::ExecuteMin();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"reverse:"<<std::endl;

    Ex::ExecuteReverse();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"ScalarMultiplication:"<<std::endl;

    Ex::ExecuteScalarMultiplication();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"DotProduct:"<<std::endl;

    Ex::ExecuteDotProduct();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"Compact:"<<std::endl;

    Ex::ExecuteCompact();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"Copy:"<<std::endl;

    Ex::ExecuteCopy();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"Unique:"<<std::endl;

    Ex::ExecuteUnique();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"sort_marbles:"<<std::endl;

    Ex::ExecuteSortMarbles();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"Partion:"<<std::endl;

    Ex::ExecutePartition();

    std::cout<<"-----------------"<<std::endl;

    std::cout<<"Rotate:"<<std::endl;

    Ex::ExecuteRotate();

    std::cout<<"-----------------"<<std::endl;

    return EXIT_SUCCESS;
}
