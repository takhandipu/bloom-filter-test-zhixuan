#include <bits/stdc++.h>

using namespace std;

#include "bloom_filter.hpp"

int main(void)
{
    unsigned number_of_branches[]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    cout <<"Number-of-branches False-positive-rate-(\%) Number-of-hash-functions Bloom-filter-size-(KB)"<<endl;
    for(int i=1;i<=4096*8;i*=2)
    {
        for(int j=1;j<=100;j++)
        {
            bloom_parameters parameters;
            // parameters.maximum_size=i*8;
            //parameters.minimum_size=i*64;
            parameters.projected_element_count = i;//12*1024;
            parameters.maximum_number_of_hashes = 10;
            parameters.minimum_number_of_hashes = 2;
            parameters.false_positive_probability = 1.0*j/100.0;
            //parameters.maximum_size=i;
            if (!parameters)
            {
                std::cout << "Error - Invalid set of bloom filter parameters!" << std::endl;
            }
            else
            {
                parameters.compute_optimal_parameters();    
                cout<<i<<" "<<j<<" "<<parameters.optimal_parameters.number_of_hashes<<" "<<parameters.optimal_parameters.table_size*1.0/(1024*8.0)<<endl;
            }
        }
    }
}
