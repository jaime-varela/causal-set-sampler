#include "schwarchild_spherical.h"
#include <cmath>

namespace causalSetSampler {

    schwarchild_spherical::schwarchild_spherical() : metric_volume_forms() {
        this->is_jacobian_defined = true;
        this->dimension = 4;
    }

    double schwarchild_spherical::differential_volume(const Eigen::VectorXd& coordinates) {
        auto r = coordinates[1];
        auto theta = coordinates[2];
       
        return r*r*sin(theta);//TODO: r^2 Sin(\theta)
    }

    Eigen::VectorXd schwarchild_spherical::differential_volume_derivative(const Eigen::VectorXd& coordinates) {
        auto r = coordinates[1];
        auto theta = coordinates[2];
        Eigen::VectorXd vec(4);
        vec << 0.0,2*r*sin(theta),r*r*cos(theta),0.0;
        return vec;
    }
    
}