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

    };
    
    metric_volume_forms::metric_volume_forms(/* args */)
    {
    }
    
    metric_volume_forms::~metric_volume_forms()
    {
    }
    
    
}