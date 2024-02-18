#define OPTIM_ENABLE_EIGEN_WRAPPERS
#include "optim.hpp"
        
#include "schwarchild_spherical.h"
        
int main()
{

    causalSetSampler::schwarchild_spherical schwar_4d{};

    
    Eigen::VectorXd x = 2.0 * Eigen::VectorXd::Ones(4); // initial values: (2,2)
        
    return 0;
}