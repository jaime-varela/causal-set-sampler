#pragma once
#include <Eigen/Dense>
// Abstract class for space-time metric volume forms

namespace causalSetSampler
{
    class metric_volume_forms
    {
    private:
        /* data */
        int dimension;
    public:
        metric_volume_forms(/* args */);
        ~metric_volume_forms();

        virtual double differential_volume(const Eigen::VectorXd& coordinates) = 0;

        virtual Eigen::VectorXd differential_volume_derivative(const Eigen::VectorXd& coordinates) {
            Eigen::VectorXd emptyVector; // Create an empty VectorXd
            return emptyVector;
        };

    };
    
    metric_volume_forms::metric_volume_forms(/* args */)
    {
    }
    
    metric_volume_forms::~metric_volume_forms()
    {
    }
    
    
}