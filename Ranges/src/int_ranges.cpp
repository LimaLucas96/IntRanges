
#include "../include/int_ranges.h"

using namespace std;

namespace ir
{
    void negate( value_type * first, value_type * last ){
        while( first != last )
            *first++ *= -1;
    }

    const value_type *min(const value_type *first, const value_type *last){
		auto tam=std::distance(first,last);

		int pos=0;
		int aux=first[pos];
		for(int i(0);i<tam;i++){
			if(first[i]<aux){
				aux=first[i];
				pos=i;
			}
		}

		return first+pos;
	}

	void reverse(value_type *first,value_type *last){
		last--;
	
		while(first < last){
			swap(*first,*last);
			first++;
			last--;
		}
	}

	void scalar_multiplication(value_type *first,value_type *last,value_type scalar){

		while(first<last){
			*first*=scalar;
			first++;
		}
	}

	value_type dot_product(value_type *a_first,value_type *a_last,value_type *b_frist){

		auto tam=distance(a_first,a_last);
		auto aux(0);

		for(int i(0);i<tam;i++){
			aux+=a_first[i] * b_frist[i];
		}

		return aux;
	}

	value_type *compact(value_type *first, value_type *last){
	
		auto tam=distance(first,last);

		int *pt=first;

		for(int i(0);i<tam;i++){
			if(first[i]>0){
				*pt=first[i];
				pt++;
			}
		}

		return pt;
	}

	value_type *copy(const value_type *first,const value_type *last, value_type *d_first){

		auto tam=distance(first,last);

		for(auto i(0);i<tam;i++){
			*d_first=first[i];
			d_first++;
		}

		return d_first;
	}

	value_type *unique(value_type *first,value_type *last){
		auto tam=distance(first,last);
		int cont(0);
		int *pont=first;
		pont++;

		for(int i(0);i<tam;i++){
			
			cont=0;

			for(auto j(first);j != pont;++j){
				if(first[i]==*j){
					cont++;
				}
			}

			if(cont==0){
				*pont=first[i];
				pont++;
			}
		}

		return pont;
	}

	value_type *sort_marbles(value_type *first,value_type *last){
	
		auto *pt=first;

		while (first<last){
			if(*first == 0){
				swap(*pt,*first);
				pt++;
			}

			first++;
		}

		return pt;
	}

	void partition(value_type *first,value_type *last, value_type *pivot){
		auto valor=*pivot;
		auto *aux=first;

		auto tam=distance(first,last);

		for(int i(0);i<tam;i++){
			if(first[i]<valor){
				swap(*aux,first[i]);
				aux++;
			}
		}

		first=aux;

		tam=distance(first,last);

		for (int i = 0; i < tam; ++i)
		{
			if(*aux > first[i]){
				swap(*aux,first[i]);
				aux++;
			}
		}
	}

	void rotate(value_type *first,value_type *n_first,value_type *last){
		auto tamV=distance (first,last);
		auto tamD=distance(first,n_first);

		while(tamD>0){
			auto aux= *first;

			for(int i(0);i<tamV;i++){
				first[i]=first[i+1];
			}
			first[tamV-1]=aux;

			tamD--;
		}
	}
}
